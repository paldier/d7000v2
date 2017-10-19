#!/bin/sh
#-------------------------------------------------------------------------
#  Copyright 2010, NETGEAR
#  All rights reserved.
#-------------------------------------------------------------------------

# load environment
. /opt/rcagent/scripts/env.sh

# get Url for hook server
URL=`readycloud_nvram get readycloud_fetch_url`

# auth data
NAS_NAME=`readycloud_nvram get readycloud_hostname`
NAS_PASS=`readycloud_nvram get readycloud_password`

LOG_FILE="/tmp/readycloud_register.log"
	
# construct comm exec
COMM_EXEC="curl --basic -k --user ${NAS_NAME}:${NAS_PASS} --url ${URL}"

#
# arg: <data> [<store.path>]
#
comm_post()
{
    local post="${TMP_PREFIX}/readycloud_r.post"
    echo "${1}" > "${post}"
    comm_post_file "${post}" "${2}" || {
# 	rm -f "${post}"
	return $ERROR
    }
#     rm -f "${post}"
    return $OK
}

#
# args: <file.path> [<store.path>]
#
comm_post_file()
{
    COMM_RESULT=""
    [ -z "${1}" ] && return $ERROR
    if [ -z "${2}" ];
    then
	FULL_EXEC="\`cat "${1}" | ${COMM_EXEC} -X POST --data-binary @- 2>/dev/null\`"
# 	FULL_EXEC="\`cat "${1}" | ${COMM_EXEC} -X POST --data-binary @- \`"
    else
# 	FULL_EXEC="\`cat "${1}" | ${COMM_EXEC} -X POST --data-binary @- > "${2}"\`"
	FULL_EXEC="\`cat "${1}" | ${COMM_EXEC} -X POST --data-binary @- 2>/dev/null -o '${2}'\`"
    fi
#     echo "${FULL_EXEC}"
    eval COMM_RESULT="${FULL_EXEC}" || return $ERROR

    return $OK
}

#
# args: <user name> <password>
#
do_register()
{
	# construct request
	USER_NAME=$1
	USER_PASS=$2
	temp_dir=$3
	XAGENT_ID=$(readycloud_nvram get x_agent_id | tr -d '[[:space:]]')
	MODEL=$(remote_smb_conf -get_model_name | tr -d '[[:space:]]')
	USE_XCLOUD=$(readycloud_nvram get readycloud_use_xcloud | tr -d '[[:space:]]')
	SERIAL_NUMBER=$(system get serial_number | tr -d '[[:space:]]')

	FIRMWARE_VERSION=$(remote_smb_conf -get_firmware_version | tr -d '[[:space:]]')
	#get second line of "version" command output
	#get second part of "U12H270T00/V1.0.3.49/20140403_xAgent" line (version)
	#and removing first character "V" from it
	#output - "1.0.3.49"

	DATA="<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	DATA="${DATA}<request moniker=\"/root/devices\" method=\"register\">"
	DATA="${DATA}<body type=\"registration\">"
	DATA="${DATA}<username>${USER_NAME}</username>"
	DATA="${DATA}<password>${USER_PASS}</password>"
	DATA="${DATA}<model>${MODEL}</model>"
	DATA="${DATA}<firmware_id>${FIRMWARE_VERSION}</firmware_id>"
	if [ $USE_XCLOUD -eq 1 ]; then 
		DATA="${DATA}<x_agent_id>${XAGENT_ID}</x_agent_id>"
	fi
	DATA="${DATA}<license><LicenseKey>sdfsfgjsflkj</LicenseKey><hardwareSN>${SERIAL_NUMBER}</hardwareSN><StartTime>0</StartTime><ExpiredTime>999</ExpiredTime><valid>true</valid></license>"
	DATA="${DATA}</body></request>"


	echo "Registering with following string (credentials are ${NAS_NAME} ${NAS_PASS}): ${DATA}" > ${LOG_FILE}
	comm_post "${DATA}" && {
	   if [ "xSUCCESS" = "x${COMM_RESULT}" ]; then
		readycloud_nvram set readycloud_registration_owner=${USER_NAME}
        readycloud_nvram set leafp2p_run="1"
        readycloud_nvram set x_force_connection="1"
        readycloud_nvram save
        if [ -f /tmp/xagent_watchdog.pid ]; then
        	kill -SIGHUP `cat /tmp/xagent_watchdog.pid`
        fi
        internet set connection readycloud 1

		return $OK
	    fi
	}
	echo "Invalid User Name or Password"
	return $ERROR
}

#
# arg: <user name> <password>
#
do_unregister()
{
    # construct request
	USER_NAME=$1
	USER_PASS=$2

	DATA="<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	DATA="${DATA}<request moniker=\"/root/devices\" method=\"unregister\">"
	DATA="${DATA}<body type=\"registration\">"
	DATA="${DATA}<username>${USER_NAME}</username>"
	DATA="${DATA}<password>${USER_PASS}</password>"
	DATA="${DATA}<license><LicenseKey>sdfsfgjsflkj</LicenseKey><hardwareSN>2496249</hardwareSN><StartTime>0</StartTime><ExpiredTime>999</ExpiredTime><valid>true</valid></license>"
	DATA="${DATA}</body></request>"

	comm_post "${DATA}" && {
	if [ "xSUCCESS" = "x$COMM_RESULT" ]; then
            readycloud_nvram unset readycloud_registration_owner
            readycloud_nvram set leafp2p_run="0"
            readycloud_nvram unset x_force_connection
            readycloud_nvram unset leafp2p_username
            readycloud_nvram unset leafp2p_password
            readycloud_nvram save
            internet set connection readycloud 0
            return $OK
	fi
	}
	echo "Connect to Server fail, Please check inernet connection"
	return $ERROR
}

#
# args: <alias>
#
do_updatealias()
{
	# construct request
	ALIAS=$1

	DATA="<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	DATA="${DATA}<request moniker=\"/root/devices\" method=\"updatealias\">"
	DATA="${DATA}<body type=\"alias\">"
	DATA="${DATA}<alias>${ALIAS}</alias>"
	DATA="${DATA}</body></request>"

	comm_post "${DATA}" && {
		if [ "xSUCCESS" = "x$COMM_RESULT" ]; then
			pidof leafp2p | xargs kill -USR1
# 			$readycloud_nvram set leafp2p_device_alias="${ALIAS}"
# 			$readycloud_nvram commit >/dev/null
# 			echo "Updated Device Alias Successfully"
# 			echo ok
			return $OK
		fi
	}
	echo "Update alias error: connect to Server fail, Please check inernet connection"
	return $ERROR
}

