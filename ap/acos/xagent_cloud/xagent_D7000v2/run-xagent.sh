#!/bin/sh

SN=`system get serial_number `
MODEL=`system get model_name `

echo 20 > /proc/sys/net/ipv4/tcp_keepalive_time
echo 3 > /proc/sys/net/ipv4/tcp_keepalive_probes
echo 20 > /proc/sys/net/ipv4/tcp_keepalive_intvl

/opt/xagent/xagent -w -d --ca_file /opt/xagent/certs/ca-bundle-mega.crt --hardware_id ${SN} --model_id ${MODEL}
