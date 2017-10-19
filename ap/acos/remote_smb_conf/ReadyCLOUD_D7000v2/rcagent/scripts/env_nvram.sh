#!/bin/sh
#Script is setting up readycloud_nvram variables needed to register device in cloud

readycloud_nvram set readycloud_fetch_url="https://readycloud.netgear.com/device/entry"
readycloud_nvram set readycloud_hook_url="https://readycloud.netgear.com/device/hook"
readycloud_nvram set readycloud_upload_url="https://readycloud.netgear.com/directio"

#set up variables for readycloud_control
readycloud_nvram set rcagent_path="/opt/rcagent"
readycloud_nvram set readycloud_control_path="/opt/rcagent/scripts"
readycloud_nvram set remote_path="/opt/remote"
readycloud_nvram set leafp2p_path="/opt/leafp2p"

readycloud_nvram set readycloud_use_lantry=1
readycloud_nvram set rcagent_log_to_console=0
readycloud_nvram set rcagent_log_level=error
readycloud_nvram set rcagent_log_to_file=1

readycloud_nvram commit
