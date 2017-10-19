#!/bin/sh

## Uncomment this to print the list of commands instead of executing them
#ECHO="echo"

exec_ip()
{
	$ECHO ip $@
}

exec_ifconfig()
{
	$ECHO ifconfig $@
}

exec_brctl()
{
	$ECHO brctl $@
}

exec_switch_cli()
{
	$ECHO switch_cli $@
}

create_vlanid()
{
	exec_switch_cli dev=0 GSW_VLAN_ID_CREATE nVId=$1 nFId=0
}

config_port_pvid()
{
	exec_switch_cli dev=0 GSW_VLAN_PORT_CFG_SET nPortId=$2 nPortVId=$1 bVLAN_UnknownDrop=0 bVLAN_ReAssign=0 eVLAN_MemberViolation=3 eAdmitMode=0 bTVM=1
}

config_port_member()
{
	exec_switch_cli dev=0 GSW_VLAN_PORT_MEMBER_ADD nVId=$1 nPortId=$2 bVLAN_TagEgress=$3
}

INTERNAL_VLANS="2050 2051 2052 2053"
SOFTWARE_VLANS="2 3 4 5"
INTERNAL_VLANS_BASE=2050
SOFTWARE_VLANS_BASE=2
ALL_LAN_PORTS="0 1 2 3"
CPU_PORT=4

exec_switch_cli dev=0 GSW_CFG_SET bVLAN_Aware=1

## Create Software & internal vlans
for vlan_id in $INTERNAL_VLANS; do create_vlanid $vlan_id; done
for vlan_id in $SOFTWARE_VLANS; do create_vlanid $vlan_id; done

## Configure switch ports with internal vlans
for vlan_id in $INTERNAL_VLANS; do config_port_pvid "$vlan_id" "`expr $vlan_id \- $INTERNAL_VLANS_BASE`"; done

## Making all the LAN Ports & CPU port to the member of each of the internal VLANs
for vlan_id in $INTERNAL_VLANS; do
	for port in $ALL_LAN_PORTS; do config_port_member "$vlan_id" "$port" "0"; done
	config_port_member "$vlan_id" "$CPU_PORT" "1"
done

## Making CPU port and ONE LAN port as member of each SW VLANs
for vlan_id in $SOFTWARE_VLANS; do
	config_port_member "$vlan_id" "`expr $vlan_id \- $SOFTWARE_VLANS_BASE`" "0"
	config_port_member "$vlan_id" "$CPU_PORT" "0"
done

## Create VLAN interface with Software VLANs, change it's mac address, add it to the bridge & make it up
for vlan_id in $SOFTWARE_VLANS; do
	exec_ip link add link eth0_LAN name eth0_`expr $vlan_id \- $SOFTWARE_VLANS_BASE \+ 1` type vlan id "$vlan_id"
done

#switch_cli GSW_VLAN_PORT_CFG_GET nPortId=0
#switch_cli GSW_VLAN_PORT_MEMBER_READ
