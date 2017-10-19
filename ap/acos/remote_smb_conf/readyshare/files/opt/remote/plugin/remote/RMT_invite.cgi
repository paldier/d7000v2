#!/bin/sh
. /www/cgi-bin/func.sh
eval "`/www/cgi-bin/proccgi $*`"
refreshed_page=${QUERY_STRING}

SYS_PREFIX=$(${nvram} get leafp2p_sys_prefix)

cd "${SYS_PREFIX}/bin"
. "./comm.sh"

EXEC_RESULT="register_fail"

case "$FORM_submit_flag" in
    register_user)
		 do_register "$FORM_TXT_remote_login" "$FORM_TXT_remote_password" && {
			if [ "xSUCCESS" == "x$COMM_RESULT" ]; then
				EXEC_RESULT="register_ok"				
			else
				EXEC_RESULT="register_fail"
			fi
		}
	;;
    unregister_user)
		do_unregister "$FORM_TXT_remote_login" "$FORM_TXT_remote_password" && {
			if [ "xSUCCESS" == "x$COMM_RESULT" ]; then
				EXEC_RESULT="unreg_ok"
			else
				EXEC_RESULT="unreg_fail"
			fi
		}
	;;
esac

HTTP_URL=`echo ${HTTP_HOST} | sed '$s/.$//' `
print_http_refresh "http://$HTTP_URL${refreshed_page}?${EXEC_RESULT}" "0"

exec >&-
