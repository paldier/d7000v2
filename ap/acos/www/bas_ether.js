function setIP(cf)
{
	var dflag = cf.WANAssign[0].checked;
	setDisabled(dflag,cf.WPethr1,cf.WPethr2,cf.WPethr3,cf.WPethr4,cf.WMask1,cf.WMask2,cf.WMask3,cf.WMask4,cf.WGateway1,cf.WGateway2,cf.WGateway3,cf.WGateway4);
	if (cf.WANAssign[1].checked)
	{
		cf.DNSAssign[1].checked = true;
		setDNS(cf);
		//cf.test_mark.disabled =true;
	}
	//else
	//	cf.test_mark.disabled =false;
	DisableFixedIP = dflag;
}

function setDNS(cf)
{
	var dflag = cf.DNSAssign[0].checked;
	if (cf.WANAssign[1].checked)
	{
		cf.DNSAssign[1].checked=true;
		dflag = false;
	}
	setDisabled(dflag,cf.DAddr1,cf.DAddr2,cf.DAddr3,cf.DAddr4,cf.PDAddr1,cf.PDAddr2,cf.PDAddr3,cf.PDAddr4);
	DisableFixedDNS = dflag;
}

function check_wizard_dhcp(check,page)
{
	cf=document.forms[0];
	if(cf.system_name.value=="")
	{
		alert("<%getstr("c_ilname");%>");
		return false;
	}
	for(i=0;i<cf.system_name.value.length;i++)
	{
		if(isValidChar_space(cf.system_name.value.charCodeAt(i))==false)
		{
			alert("<%getstr("acname_not_allowed");%>");
			return false;
		}
	}
	for(i=0;i<cf.domain_name.value.length;i++)
	{
		if(isValidDdnsHost(cf.domain_name.value.charCodeAt(i))==false)
		{
			alert("<%getstr("doname_not_allowed");%>");
			return false;
		}
	}

	if (check == 1)
	{
		cf.run_test.value="test";
		if( page == "wiz")
			cf.action="ru_wan_flow.cgi";
	}
	else
		cf.run_test.value="no";

	return true;
}

function check_static_ip_mask_gtw()
{
	cf=document.forms[0];
	cf.ether_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	cf.ether_subnet.value=cf.WMask1.value+'.'+cf.WMask2.value+'.'+cf.WMask3.value+'.'+cf.WMask4.value;
	cf.ether_gateway.value=cf.WGateway1.value+'.'+cf.WGateway2.value+'.'+cf.WGateway3.value+'.'+cf.WGateway4.value;
	if(checkipaddr(cf.ether_ipaddr.value)==false || is_sub_or_broad(cf.ether_ipaddr.value, cf.ether_ipaddr.value, cf.ether_subnet.value) == false)
	{
		alert("<%getstr("invalid_ip");%>");
		return false;
	}
	if(checksubnet(cf.ether_subnet.value)==false)
	{
		alert("<%getstr("invalid_mask");%>");
		return false;
	}
	if(checkgateway(cf.ether_gateway.value)==false)
	{
		alert("<%getstr("invalid_gateway");%>");
		return false;
	}
	if(isGateway(cf.ether_ipaddr.value,cf.ether_subnet.value,cf.ether_gateway.value)==false)
	{
		alert("<%getstr("invalid_gateway");%>");
		return false;
	}
	if( isSameIp(cf.ether_ipaddr.value, cf.ether_gateway.value) == true )
	{
		alert("<%getstr("invalid_gateway");%>");
		return false;
	}
	if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,cf.ether_gateway.value,cf.ether_subnet.value) == false)
	{
		alert("<%getstr("bh_same_subnet_ip_gtw");%>");
		return false;
	}
	return true;
}

function check_static_dns( wan_assign )
{
	var cf=document.forms[0];
	cf.ether_dnsaddr1.value=cf.DAddr1.value+'.'+cf.DAddr2.value+'.'+cf.DAddr3.value+'.'+cf.DAddr4.value;
	cf.ether_dnsaddr2.value=cf.PDAddr1.value+'.'+cf.PDAddr2.value+'.'+cf.PDAddr3.value+'.'+cf.PDAddr4.value;
	cf.ether_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;

	if(cf.ether_dnsaddr1.value=="...")
		cf.ether_dnsaddr1.value="";

	if(cf.ether_dnsaddr2.value=="...")
		cf.ether_dnsaddr2.value="";

	if(cf.ether_ipaddr.value=="...")
		cf.ether_ipaddr.value="";
	if( check_DNS(cf.ether_dnsaddr1.value,cf.ether_dnsaddr2.value,wan_assign,cf.ether_ipaddr.value))
		return true;
	else
		return false;
}

function check_ether_samesubnet()
{
	var cf=document.forms[0];
	cf.ether_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	cf.ether_subnet.value=cf.WMask1.value+'.'+cf.WMask2.value+'.'+cf.WMask3.value+'.'+cf.WMask4.value;
	cf.ether_gateway.value=cf.WGateway1.value+'.'+cf.WGateway2.value+'.'+cf.WGateway3.value+'.'+cf.WGateway4.value;
	if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,lan_subnet) == true)
	{
		alert("<%getstr("bh_same_lan_wan_subnet");%>");
		return false;
	}
	if(isSameSubNet(cf.ether_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
	{
		alert("<%getstr("bh_same_lan_wan_subnet");%>");
		return false;
	}
	if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,cf.ether_subnet.value) == true)
	{
		alert("<%getstr("bh_same_lan_wan_subnet");%>");
		return false;
	}
	if(isSameIp(cf.ether_ipaddr.value,lan_ip) == true)
	{
		alert("<%getstr("bh_same_lan_wan_subnet");%>");
		return false;
	}
	return true;
}

function check_wizard_static(check,page)
{
	var cf=document.forms[0];
	if(check_static_ip_mask_gtw()==false)
		return false;
	/*
	if(check_ether_samesubnet()==false)
		return false;
	*/
	if(check_static_dns(true)==false)
		return false;
	
	if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,lan_subnet) == true)
	{
		cf.conflict_wanlan.value=1;
	}
	if(isSameSubNet(cf.ether_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
	{
		cf.conflict_wanlan.value=1;
	}
	if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,cf.ether_subnet.value) == true)
	{
		cf.conflict_wanlan.value=1;
	}
	if(isSameIp(cf.ether_ipaddr.value,lan_ip) == true)
	{
		cf.conflict_wanlan.value=1;
	}
	if (check == 1)
	{
		cf.run_test.value="test";
		if( page == "wiz")
			cf.action="ru_wan_flow.cgi";
	}
	else
		cf.run_test.value="no";

	return true;
}

function check_ether(cf,check)
{
	cf.ether_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	cf.ether_subnet.value=cf.WMask1.value+'.'+cf.WMask2.value+'.'+cf.WMask3.value+'.'+cf.WMask4.value;
	cf.ether_gateway.value=cf.WGateway1.value+'.'+cf.WGateway2.value+'.'+cf.WGateway3.value+'.'+cf.WGateway4.value;

	if(check_wizard_dhcp(check,"bas")==false)
		return false;
	if (cf.MACAssign[2].checked )
	{
		the_mac=cf.Spoofmac.value;
		if(the_mac.indexOf(":")==-1 && the_mac.length=="12")
		{
			var tmp_mac=the_mac.substr(0,2)+":"+the_mac.substr(2,2)+":"+the_mac.substr(4,2)+":"+the_mac.substr(6,2)+":"+the_mac.substr(8,2)+":"+the_mac.substr(10,2);
			cf.Spoofmac.value = tmp_mac;
		}
		else if ( the_mac.split("-").length == 6 )
		{
			var tmp_mac = the_mac.replace(/-/g,":");
			cf.Spoofmac.value=tmp_mac;
		}
		if(maccheck_multicast(cf.Spoofmac.value) == false)
			return false;
	}
	if(cf.WANAssign[1].checked == true)
	{
		if(check_static_ip_mask_gtw()==false)
			return false;
		if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,lan_subnet) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		
		if(isSameSubNet(cf.ether_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,cf.ether_subnet.value) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameIp(cf.ether_ipaddr.value,lan_ip) == true)
		{
			cf.conflict_wanlan.value=1;
		}
	}
	if(cf.DNSAssign[1].checked)
	{
		if(check_static_dns(cf.WANAssign[1].checked)==false)
			return false;
	}
	if( old_wan_type!="dhcp" )
		cf.change_wan_type.value=0;
	else if ( old_wan_assign == "1" )
	{
		if(old_wan_ip!=cf.ether_ipaddr.value && cf.WANAssign[1].checked)
			cf.change_wan_type.value=0;
		else if(cf.WANAssign[0].checked)
			cf.change_wan_type.value=0;
		else
			cf.change_wan_type.value=1;
	}
	else if(old_wan_assign == "0" )
	{
		if(old_wan_ip!=cf.ether_ipaddr.value && cf.WANAssign[1].checked)
			cf.change_wan_type.value=0;
		else
			cf.change_wan_type.value=1;
	}

	return true;
}

function check_welcome_dhcp()
{
	var cf = document.forms[0];
	parent.account_name=cf.system_name.value;
	parent.domain_name=cf.domain_name.value;
	parent.welcome_wan_type=2;
	return true;
}

function check_welcome_static()
{
	var cf = document.forms[0];
	cf.ether_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	cf.ether_subnet.value=cf.WMask1.value+'.'+cf.WMask2.value+'.'+cf.WMask3.value+'.'+cf.WMask4.value;
	cf.ether_gateway.value=cf.WGateway1.value+'.'+cf.WGateway2.value+'.'+cf.WGateway3.value+'.'+cf.WGateway4.value;
	cf.ether_dnsaddr1.value=cf.DAddr1.value+'.'+cf.DAddr2.value+'.'+cf.DAddr3.value+'.'+cf.DAddr4.value;
	cf.ether_dnsaddr2.value=cf.PDAddr1.value+'.'+cf.PDAddr2.value+'.'+cf.PDAddr3.value+'.'+cf.PDAddr4.value;
	if(cf.ether_dnsaddr2.value=="...")
		cf.ether_dnsaddr2.value="";
	if(check_wizard_static(0,"welcome")==false)
		return false;
	parent.welcome_wan_type=1;
	parent.static_ip=cf.ether_ipaddr.value;
	parent.static_subnet=cf.ether_subnet.value;
	parent.static_gateway=cf.ether_gateway.value;
	parent.static_dns1=cf.ether_dnsaddr1.value;
	parent.static_dns2=cf.ether_dnsaddr2.value;
	return true;
}

function check_RU_dhcp_static()
{
	var cf = document.forms[0];
	cf.ether_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	cf.ether_subnet.value=cf.WMask1.value+'.'+cf.WMask2.value+'.'+cf.WMask3.value+'.'+cf.WMask4.value;
	cf.ether_gateway.value=cf.WGateway1.value+'.'+cf.WGateway2.value+'.'+cf.WGateway3.value+'.'+cf.WGateway4.value;
	if(cf.WANAssign[1].checked == true)
	{
		if(check_static_ip_mask_gtw()==false)
			return false;
		if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,lan_subnet) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		
		if(isSameSubNet(cf.ether_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,cf.ether_subnet.value) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameIp(cf.ether_ipaddr.value,lan_ip) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		parent.welcome_wan_type=1;
	}
	else
	{
		cf.ether_ipaddr.value="";
		cf.ether_subnet.value="";
		cf.ether_gateway.value="";
		cf.conflict_wanlan.value=0;
		parent.welcome_wan_type=2;
	}
	if(cf.DNSAssign[1].checked)
	{
		if(check_static_dns(cf.WANAssign[1].checked)==false)
			return false;
	}
	else
	{
		cf.ether_dnsaddr1.value="";
		cf.ether_dnsaddr2.value="";
	}
	parent.static_ip=cf.ether_ipaddr.value;
	parent.static_subnet=cf.ether_subnet.value;
	parent.static_gateway=cf.ether_gateway.value;
	parent.static_dns1=cf.ether_dnsaddr1.value;
	parent.static_dns2=cf.ether_dnsaddr2.value;
	parent.conflict_wanlan=cf.conflict_wanlan.value;
	
	location.href="RU_manual_spoof.htm";
}

function RU_welcome_static()
{
	var cf = document.forms[0];
	cf.ether_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	cf.ether_subnet.value=cf.WMask1.value+'.'+cf.WMask2.value+'.'+cf.WMask3.value+'.'+cf.WMask4.value;
	cf.ether_gateway.value=cf.WGateway1.value+'.'+cf.WGateway2.value+'.'+cf.WGateway3.value+'.'+cf.WGateway4.value;
	cf.ether_dnsaddr1.value=cf.DAddr1.value+'.'+cf.DAddr2.value+'.'+cf.DAddr3.value+'.'+cf.DAddr4.value;
	cf.ether_dnsaddr2.value=cf.PDAddr1.value+'.'+cf.PDAddr2.value+'.'+cf.PDAddr3.value+'.'+cf.PDAddr4.value;
	if(check_static_ip_mask_gtw()==false)
		return false;
	if(cf.ether_dnsaddr2.value=="...")
		cf.ether_dnsaddr2.value="";
	if(check_wizard_static(0,"welcome")==false)
		return false;

	if (cf.submit_wan)
		cf.submit_wan.value = parent.isp_type;

	parent.welcome_wan_type=1;
	
	parent.static_ip=cf.ether_ipaddr.value;
	parent.static_subnet=cf.ether_subnet.value;
	parent.static_gateway=cf.ether_gateway.value;
	parent.static_dns1=cf.ether_dnsaddr1.value;
	parent.static_dns2=cf.ether_dnsaddr2.value;
	parent.conflict_wanlan=cf.conflict_wanlan.value;
	
	if(parent.isp_type=="3" || parent.isp_type=="9" || parent.isp_type=="13")
		location.href="RU_isp_spoof.htm";
	else if(parent.isp_type=="4")
	{
		cf.ether_ipaddr.value=cf.ether_ipaddr.value;
		cf.ether_subnet.value=cf.ether_subnet.value;
		cf.ether_gateway.value=cf.ether_gateway.value;
		cf.ether_dnsaddr1.value=cf.ether_dnsaddr1.value;
		cf.ether_dnsaddr2.value=cf.ether_dnsaddr2.value;
		cf.DNSAssign.value="1";
		cf.WANAssign.value="static";
		cf.welcome_wan_type.value=1;
		cf.submit();
	}
	else if(parent.isp_type=="6")
	{
		alert("<%getstr("attention_static_ip");%>");
		cf.pppoe_dual_ipaddr.value=cf.ether_ipaddr.value;
		cf.pppoe_dual_subnet.value=cf.ether_subnet.value;
		cf.pppoe_dual_gateway.value="";
		cf.welcome_wan_type.value="3";
		cf.submit();
	}
	else if(parent.isp_type=="14")
	{
		alert("<%getstr("attention_static_ip");%>");
		cf.l2tp_myip.value=cf.ether_ipaddr.value;
		cf.l2tp_mynetmask.value=cf.ether_subnet.value;
		cf.l2tp_gateway.value=cf.ether_gateway.value;
		cf.l2tp_dnsaddr1.value=cf.ether_dnsaddr1.value;
		cf.l2tp_dnsaddr2.value=cf.ether_dnsaddr2.value;
		cf.DNSAssign.value="1";
		cf.WANAssign.value="1";
		cf.STATIC_DNS.value=parent.STATIC_DNS;
		cf.welcome_wan_type.value="5";
		cf.submit();
	}
	else if(parent.isp_type=="10")
	{
		alert("<%getstr("attention_static_ip");%>");
		cf.pptp_myip.value=cf.ether_ipaddr.value;
		cf.pptp_mynetmask.value=cf.ether_subnet.value;
		cf.pptp_gateway.value=cf.ether_gateway.value;
		cf.pptp_dnsaddr1.value=cf.ether_dnsaddr1.value;
		cf.pptp_dnsaddr2.value=cf.ether_dnsaddr2.value;
		cf.DNSAssign.value="1";
		cf.WANAssign.value="1";
		cf.STATIC_DNS.value=parent.STATIC_DNS;
		cf.welcome_wan_type.value="4";
		cf.submit();
	}
}

function RU_welcome_pppoe_static()
{
	var cf = document.forms[0];
	cf.ether_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	cf.ether_subnet.value=cf.WMask1.value+'.'+cf.WMask2.value+'.'+cf.WMask3.value+'.'+cf.WMask4.value;
	cf.ether_gateway.value=cf.WGateway1.value+'.'+cf.WGateway2.value+'.'+cf.WGateway3.value+'.'+cf.WGateway4.value;
	
	if(checkipaddr(cf.ether_ipaddr.value)==false || is_sub_or_broad(cf.ether_ipaddr.value, cf.ether_ipaddr.value, cf.ether_subnet.value) == false)
	{
		alert("<%getstr("invalid_ip");%>");
		return false;
	}
	if(checksubnet(cf.ether_subnet.value)==false)
	{
		alert("<%getstr("invalid_mask");%>");
		return false;
	}

	if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,lan_subnet) == true)
	{
		cf.conflict_wanlan.value=1;
	}
	
	if(isSameSubNet(cf.ether_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
	{
		cf.conflict_wanlan.value=1;
	}
	if(isSameSubNet(cf.ether_ipaddr.value,cf.ether_subnet.value,lan_ip,cf.ether_subnet.value) == true)
	{
		cf.conflict_wanlan.value=1;
	}
	if(isSameIp(cf.ether_ipaddr.value,lan_ip) == true)
	{
		cf.conflict_wanlan.value=1;
	}

	if (cf.submit_wan)
		cf.submit_wan.value = parent.isp_type;

	cf.run_test.value="no";
	parent.pppoe_eth_ip=cf.ether_ipaddr.value;
	parent.pppoe_eth_netmask=cf.ether_subnet.value;
	parent.static_ip=cf.ether_ipaddr.value;
	parent.static_subnet=cf.ether_subnet.value;
	parent.static_gateway=cf.ether_gateway.value;

	if(parent.isp_type=="6")
	{
		alert("<%getstr("attention_static_ip");%>");
		cf.pppoe_dual_ipaddr.value=cf.ether_ipaddr.value;
		cf.pppoe_dual_subnet.value=cf.ether_subnet.value;
		cf.pppoe_dual_gateway.value=cf.ether_gateway.value;
		cf.pppoe_dnsaddr1.value=parent.static_dns1;
		cf.pppoe_dnsaddr2.value=parent.static_dns2;
		cf.pppoe_servername.value=parent.pppoe_server;
		if(cf.pppoe_dnsaddr1.value != "" || cf.pppoe_dnsaddr2.value!= "")
			cf.DNSAssign.value="1";
		else
			cf.DNSAssign.value="0";
		cf.welcome_wan_type.value="3";
		cf.submit();
	}
	else if(parent.isp_type=="5")
	{
		location.href="RU_isp_spoof.htm";
	}
	else if(parent.isp_type=="88")
	{
		alert("<%getstr("attention_static_ip");%>");
		cf.pppoe_dual_ipaddr.value=cf.ether_ipaddr.value;
		cf.pppoe_dual_subnet.value=cf.ether_subnet.value;
		cf.pppoe_dual_gateway.value=cf.ether_gateway.value;
		cf.pppoe_dnsaddr1.value="";
		cf.pppoe_dnsaddr2.value="";
		cf.welcome_wan_type.value="3";
		cf.submit();
	}
}
