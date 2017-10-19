function ReleasePeriodClick(cf)
{
	var dflag;
	if(cf.enable_pppoe_dual.checked)
		dflag = false;
	else
		dflag = true;
	//setDisabled(dflag,cf.Duethr1,cf.Duethr2,cf.Duethr3,cf.Duethr4,cf.DuMask1,cf.DuMask2,cf.DuMask3,cf.DuMask4,cf.DuGateway1,cf.DuGateway2,cf.DuGateway3,cf.DuGateway4);
	setDisabled(dflag,cf.Duethr1,cf.Duethr2,cf.Duethr3,cf.Duethr4,cf.DuMask1,cf.DuMask2,cf.DuMask3,cf.DuMask4);
	return;
}

function setIP(cf)
{
	var dflag = cf.WANAssign[0].checked;
	setDisabled(dflag,cf.WPethr1,cf.WPethr2,cf.WPethr3,cf.WPethr4);
	//setDisabled(dflag,cf.WMask1,cf.WMask2,cf.WMask3,cf.WMask4);
	DisableFixedIP = dflag;
}

function setDNS(cf)
{
	var dflag = cf.DNSAssign[0].checked;
	setDisabled(dflag,cf.DAddr1,cf.DAddr2,cf.DAddr3,cf.DAddr4,cf.PDAddr1,cf.PDAddr2,cf.PDAddr3,cf.PDAddr4);
	DisableFixedDNS = dflag;
}

function check_static_ip_mask_gtw()
{
	cf=document.forms[0];
	cf.pppoe_dual_ipaddr.value=cf.Duethr1.value+'.'+cf.Duethr2.value+'.'+cf.Duethr3.value+'.'+cf.Duethr4.value;
	cf.pppoe_dual_subnet.value=cf.DuMask1.value+'.'+cf.DuMask2.value+'.'+cf.DuMask3.value+'.'+cf.DuMask4.value;
	//cf.pppoe_dual_gateway.value=cf.DuGateway1.value+'.'+cf.DuGateway2.value+'.'+cf.DuGateway3.value+'.'+cf.DuGateway4.value;
	//if(cf.pppoe_dual_ipaddr.value=="..." && cf.pppoe_dual_subnet.value=="..." && cf.pppoe_dual_gateway.value=="...")
	if(cf.pppoe_dual_ipaddr.value=="..." && cf.pppoe_dual_subnet.value=="...")
	{
		cf.pppoe_dual_ipaddr.value="";
		cf.pppoe_dual_subnet.value="";
		//cf.pppoe_dual_gateway.value="";
		cf.pppoe_dual_assign.value=0;
		return true;
	}
	if(checkipaddr(cf.pppoe_dual_ipaddr.value)==false || is_sub_or_broad(cf.pppoe_dual_ipaddr.value, cf.pppoe_dual_ipaddr.value, cf.pppoe_dual_subnet.value) == false)
	{
		alert("<%getstr("invalid_ip");%>");
		return false;
	}
	if(checksubnet(cf.pppoe_dual_subnet.value)==false)
	{
		alert("<%getstr("invalid_mask");%>");
		return false;
	}
	/*
	if(checkgateway(cf.pppoe_dual_gateway.value)==false)
	{
		alert("<%getstr("invalid_gateway");%>");
		return false;
	}
	if(isGateway(cf.pppoe_dual_ipaddr.value,cf.pppoe_dual_subnet.value,cf.pppoe_dual_gateway.value)==false)
	{
		alert("<%getstr("invalid_gateway");%>");
		return false;
	}
	if( isSameIp(cf.pppoe_dual_ipaddr.value, cf.pppoe_dual_gateway.value) == true )
	{
		alert("<%getstr("invalid_gateway");%>");
		return false;
	}
	if(isSameSubNet(cf.pppoe_dual_ipaddr.value,cf.pppoe_dual_subnet.value,cf.pppoe_dual_gateway.value,cf.pppoe_dual_subnet.value) == false)
	{
		alert("<%getstr("bh_same_subnet_ip_gtw");%>");
		return false;
	}
	*/
	cf.pppoe_dual_assign.value=1;
	if(isSameSubNet(cf.pppoe_dual_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
	{
		cf.conflict_wanlan.value=1;
	}
	if(isSameIp(cf.pppoe_dual_ipaddr.value,lan_ip) == true)
	{
		cf.conflict_wanlan.value=1;
	}
	return true;
}

function check_wizard_pppoe(check,servername,page)
{
	var form=document.forms[0];
	if(form.pppoe_username.value=="")
	{
		alert("<%getstr("user_name_null");%>");
		return false;
	}
	for(i=0;i<form.pppoe_username.value.length;i++)
	{
		if(isValidChar(form.pppoe_username.value.charCodeAt(i))==false)
		{
			alert("<%getstr("invalid_login");%>");
			return false;
		}
	}
	for(i=0;i<form.pppoe_passwd.value.length;i++)
	{
		if(isValidChar(form.pppoe_passwd.value.charCodeAt(i))==false)
		{
			alert("<%getstr("bh_password_error");%>");
			return false;
		}
	}
	for(i=0;i<servername.length;i++)
	{
		if(isValidChar(servername.charCodeAt(i))==false)
		{
			alert("<%getstr("invalid_ser_name");%>");
			return false;
		}
	}
	if(form.pppoe_idletime.value.length<=0)
	{
		alert("<%getstr("bh_idle_time_null");%>");
		return false;
	}
	else if(!_isNumeric(form.pppoe_idletime.value))
	{
		alert("<%getstr("m_proper_time");%>");
		return false;
	}
	if (check == 1)
	{
		form.run_test.value="test";
		if( page == "wiz")
			form.action="ru_wan_flow.cgi";
	}
	else
		form.run_test.value="no";
	
	return true;
}

function check_pppoe(form,check)
{
	if(check_wizard_pppoe(check,form.pppoe_servername.value,"bas")==false)
		return false;
	form.hidden_pppoe_idle_time.value = form.pppoe_idletime.value;
	//auto_reset
	if(gr_flag=="1")  //german
	{
		if(form.enable_auto_reset.checked==true)
			form.hidden_enable_auto_reset.value=1;
		else
			form.hidden_enable_auto_reset.value=0;
		form.auto_reset_time.value=form.reset_sche.selectedIndex;
	}
	else
	{
		form.hidden_enable_auto_reset.value=0;
		form.auto_reset_time.value=0;
	}
	
	form.pppoe_ipaddr.value=form.WPethr1.value+'.'+form.WPethr2.value+'.'+form.WPethr3.value+'.'+form.WPethr4.value;
	if(form.WANAssign[1].checked == true)
	{
		if(checkipaddr(form.pppoe_ipaddr.value)==false || is_sub_or_broad(form.pppoe_ipaddr.value, lan_ip, lan_subnet) == false)
		{
			alert("<%getstr("invalid_ip");%>");
			return false;
		}
		if(isSameSubNet(form.pppoe_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
		{
			form.conflict_wanlan.value=1;
		}
		if(isSameIp(form.pppoe_ipaddr.value,lan_ip) == true)
		{
			form.conflict_wanlan.value=1;
		}
		/*
		if(form.pppoe_netmask.value !="..." && form.pppoe_netmask.value!="0.0.0.0")
		{
			if(checksubnet(form.pppoe_netmask.value)==false)
			{
				alert("<%getstr("invalid_mask");%>");
				return false;
			}
		}
		*/
	}
	if( RU_flag == "1")
	{ 
		if(form.enable_pppoe_dual.checked)
		{
			form.dual_access.value=1;
			if(check_static_ip_mask_gtw() == false)
				return false;
		}
		else
			form.dual_access.value=0;
	}
	if (form.DNSAssign[1].checked == true)
	{
		form.pppoe_dnsaddr1.value=form.DAddr1.value+'.'+form.DAddr2.value+'.'+form.DAddr3.value+'.'+form.DAddr4.value;
		form.pppoe_dnsaddr2.value=form.PDAddr1.value+'.'+form.PDAddr2.value+'.'+form.PDAddr3.value+'.'+form.PDAddr4.value;
		form.pppoe_ipaddr.value=form.WPethr1.value+'.'+form.WPethr2.value+'.'+form.WPethr3.value+'.'+form.WPethr4.value;

		if(form.pppoe_dnsaddr1.value=="...")
			form.pppoe_dnsaddr1.value="";

		if(form.pppoe_dnsaddr2.value=="...")
			form.pppoe_dnsaddr2.value="";

		if( !check_DNS(form.pppoe_dnsaddr1.value,form.pppoe_dnsaddr2.value,form.WANAssign[1].checked,form.pppoe_ipaddr.value))
			return false;
	}
	if ( !(old_wan_type=="pppoe"))
		form.change_wan_type.value=0;
	else if ( old_pppoe_wan_assign == "1")
	{
		if( old_wan_ip!= form.pppoe_ipaddr.value)
			form.change_wan_type.value=0;
		else
			form.change_wan_type.value=1;
	}
	else if( old_pppoe_wan_assign == "0")
	{
		if( old_wan_ip!=form.pppoe_ipaddr.value)
			form.change_wan_type.value=0;
		else
			form.change_wan_type.value=1;
	}
	if (form.MACAssign[2].checked )
	{
		the_mac=form.Spoofmac.value;
		if(the_mac.indexOf(":")==-1 && the_mac.length=="12")
		{
			var tmp_mac=the_mac.substr(0,2)+":"+the_mac.substr(2,2)+":"+the_mac.substr(4,2)+":"+the_mac.substr(6,2)+":"+the_mac.substr(8,2)+":"+the_mac.substr(10,2);
			form.Spoofmac.value = tmp_mac;
		}
		else if ( the_mac.split("-").length == 6 )
		{
			var tmp_mac = the_mac.replace(/-/g,":");
			form.Spoofmac.value=tmp_mac;
		}
		if(maccheck_multicast(form.Spoofmac.value) == false)
			return false;
	}
	return true;
}

function setIP_welcome_pppoe()
{
	cf=document.forms[0];
	var dflag = cf.WANAssign[0].checked;
	setDisabled(dflag,cf.WPethr1,cf.WPethr2,cf.WPethr3,cf.WPethr4);
	DisableFixedIP = dflag;
}

function setDNS_welcome_pppoe()
{
	cf=document.forms[0];
	var dflag = cf.DNSAssign[0].checked;
	setDisabled(dflag,cf.DAddr1,cf.DAddr2,cf.DAddr3,cf.DAddr4,cf.PDAddr1,cf.PDAddr2,cf.PDAddr3,cf.PDAddr4);
	DisableFixedDNS = dflag;
}

function check_wizard_pppoe_new(check)
{
	var cf=document.forms[0];
	if(check_wizard_pppoe(check,cf.pppoe_servicename.value,"wiz")==false)
		return false;
	cf.pppoe_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	
	if(cf.WANAssign[1].checked == true)
	{
		if(checkipaddr(cf.pppoe_ipaddr.value)==false)
		{
			alert("<%getstr("invalid_ip");%>");
			return false;
		}
		if(isSameSubNet(cf.pppoe_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameIp(cf.pppoe_ipaddr.value,lan_ip) == true)
		{
			cf.conflict_wanlan.value=1;
		}
	}
	if( RU_flag == "1")
	{ 
		if(cf.enable_pppoe_dual.checked)
		{
			cf.dual_access.value=1;
			if(check_static_ip_mask_gtw() == false)
				return false;
		}
		else
			cf.dual_access.value=0;
	}
	if(cf.DNSAssign[1].checked == true)
	{
		cf.pppoe_dnsaddr1.value=cf.DAddr1.value+'.'+cf.DAddr2.value+'.'+cf.DAddr3.value+'.'+cf.DAddr4.value;
		cf.pppoe_dnsaddr2.value=cf.PDAddr1.value+'.'+cf.PDAddr2.value+'.'+cf.PDAddr3.value+'.'+cf.PDAddr4.value;

		if(cf.pppoe_dnsaddr1.value=="...")
			cf.pppoe_dnsaddr1.value="";

		if(cf.pppoe_dnsaddr2.value=="...")
			cf.pppoe_dnsaddr2.value="";

		if( !check_DNS(cf.pppoe_dnsaddr1.value,cf.pppoe_dnsaddr2.value,cf.WANAssign[1].checked,cf.pppoe_ipaddr.value))
			return false;
	}
}
function check_welcome_pppoe()
{
	var cf=document.forms[0];
	if(check_wizard_pppoe(0, cf.pppoe_servicename.value,"")==false)
		return false;
	cf.pppoe_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	if(cf.WANAssign[0].checked == true)
	{
		parent.pppoe_wan_assign=0;
		parent.pppoe_static_ip="";
	}
	else
	{
		if(checkipaddr(cf.pppoe_ipaddr.value)==false || is_sub_or_broad(cf.pppoe_ipaddr.value, lan_ip, lan_subnet) == false)
		{
			alert("<%getstr("invalid_ip");%>");
			return false;
		}
		parent.pppoe_wan_assign=1;
		parent.pppoe_static_ip=cf.pppoe_ipaddr.value;
	}
	/*
	form.pppoe_netmask.value=form.WMask1.value+'.'+form.WMask2.value+'.'+form.WMask3.value+'.'+form.WMask4.value;
	if(form.pppoe_netmask.value !="..." && form.pppoe_netmask.value!="0.0.0.0")
	{
		if(checksubnet(form.pppoe_netmask.value)==false)
		{
			alert("<%getstr("invalid_mask");%>");
			return false;
		}
	}
	*/
	if(cf.DNSAssign[1].checked == true)
	{
		cf.pppoe_dnsaddr1.value=cf.DAddr1.value+'.'+cf.DAddr2.value+'.'+cf.DAddr3.value+'.'+cf.DAddr4.value;
		cf.pppoe_dnsaddr2.value=cf.PDAddr1.value+'.'+cf.PDAddr2.value+'.'+cf.PDAddr3.value+'.'+cf.PDAddr4.value;

		if(cf.pppoe_dnsaddr1.value=="...")
			cf.pppoe_dnsaddr1.value="";

		if(cf.pppoe_dnsaddr2.value=="...")
			cf.pppoe_dnsaddr2.value="";

		if( !check_DNS(cf.pppoe_dnsaddr1.value,cf.pppoe_dnsaddr2.value,cf.WANAssign[1].checked,cf.pppoe_ipaddr.value))
			return false;
	}
	if( RU_flag == "1")
	{
		if(cf.enable_pppoe_dual.checked)
		{
			cf.dual_access.value=1;
			if(check_static_ip_mask_gtw() == false)
				return false;
		}
		else
			cf.dual_access.value=0;
	}
	
	parent.pppoe_username=cf.pppoe_username.value;
	parent.pppoe_password=cf.pppoe_passwd.value;
	parent.pppoe_server=cf.pppoe_servicename.value;
	parent.pppoe_idle=cf.pppoe_idletime.value;
	
	parent.pppoe_eth_ip=cf.pppoe_dual_ipaddr.value;
	parent.pppoe_eth_netmask=cf.pppoe_dual_subnet.value;
	parent.pppoe_eth_gateway=cf.pppoe_dual_gateway.value;
	parent.pppoe_dual_assign=cf.pppoe_dual_assign.value;
	parent.dual_access=cf.dual_access.value;
	
	if(cf.DNSAssign[1].checked == true)
	{
		parent.pppoe_dns_assign=1;
		parent.static_dns1.value=cf.pppoe_dnsaddr1.value;
		parent.static_dns2.value=cf.pppoe_dnsaddr2.value;
	}
	else
	{
		parent.pppoe_dns_assign=0;
		parent.static_dns1.value="";
		parent.static_dns2.value="";
	}
	parent.welcome_wan_type=3;
	return true;
}

function RU_pppoe_user_info()
{
	var cf=document.forms[0];
	if(cf.pppoe_username.value=="")
	{
		alert("<%getstr("user_name_null");%>");
		return false;
	}
	for(i=0;i<cf.pppoe_username.value.length;i++)
	{
		if(isValidChar(cf.pppoe_username.value.charCodeAt(i))==false)
		{
			alert("<%getstr("invalid_login");%>");
			return false;
		}
	}
	for(i=0;i<cf.pppoe_passwd.value.length;i++)
	{
		if(isValidChar(cf.pppoe_passwd.value.charCodeAt(i))==false)
		{
			alert("<%getstr("bh_password_error");%>");
			return false;
		}
	}
	for(i=0;i<cf.pppoe_servername.value.length;i++)
	{
		if(isValidChar(cf.pppoe_servername.value.charCodeAt(i))==false)
		{
			alert("<%getstr("invalid_ser_name");%>");
			return false;
		}
	}

	if (cf.submit_wan)
		cf.submit_wan.value = parent.isp_type;

	parent.pppoe_username=cf.pppoe_username.value;
	parent.pppoe_password=cf.pppoe_passwd.value;
	parent.pppoe_server=cf.pppoe_servername.value;
	parent.welcome_wan_type=3;
	
	if(parent.isp_type=="8")
	{
		cf.basic_type.value="0";
		cf.ppp_login_type.value="0";
		cf.welcome_wan_type.value="3";
		cf.dual_access.value="1";
		cf.pppoe_dual_assign.value="0";
		cf.conflict_wanlan.value="0";
		cf.pppoe_dual_ipaddr.value="";
		cf.pppoe_dual_subnet.value="";
		cf.pppoe_dnsaddr1.value=parent.static_dns1;
		cf.pppoe_dnsaddr2.value=parent.static_dns2;
		if(cf.pppoe_dnsaddr1.value != "" || cf.pppoe_dnsaddr2.value!= "")
			cf.DNSAssign.value="1";
		else
			cf.DNSAssign.value="0";
		cf.WANAssign.value="Dynamic";
		cf.pppoe_dod.value="0";
		cf.pppoe_servername.value=parent.pppoe_server;
		cf.submit();
	}
	else if(parent.isp_type=="18")
	{
		cf.basic_type.value="0";
		cf.ppp_login_type.value="0";
		cf.welcome_wan_type.value="3";
		cf.dual_access.value="0";
		cf.pppoe_dual_assign.value="0";
		cf.conflict_wanlan.value="0";
		cf.pppoe_dual_ipaddr.value="";
		cf.pppoe_dual_subnet.value="";
		cf.DNSAssign.value="0";
		cf.WANAssign.value="Dynamic";
		cf.pppoe_dod.value="0";
		cf.pppoe_servername.value=parent.pppoe_server;
		cf.submit();
	}
	else if(parent.isp_type=="7" || parent.isp_type=="17")
	{
		location.href="RU_isp_spoof.htm";
	}
	else if(parent.isp_type=="5" || parent.isp_type=="6")
	{
		location.href="RU_isp_pppoe_static.htm";
	}
	else if(parent.isp_type=="88")
	{
		location.href="RU_isp_pppoe_static.htm";
	}
	else
		location.href="RU_manual_pppoe2.htm";
}

function RU_check_pppoe()
{
	var cf=document.forms[0];
	cf.pppoe_ipaddr.value=cf.WPethr1.value+'.'+cf.WPethr2.value+'.'+cf.WPethr3.value+'.'+cf.WPethr4.value;
	if(cf.WANAssign[0].checked == true)
	{
		cf.pppoe_ipaddr.value="";
		parent.pppoe_wan_assign="0";
	}
	else
	{
		if(checkipaddr(cf.pppoe_ipaddr.value)==false || is_sub_or_broad(cf.pppoe_ipaddr.value, lan_ip, lan_subnet) == false)
		{
			alert("<%getstr("invalid_ip");%>");
			return false;
		}
		if(isSameSubNet(cf.pppoe_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameIp(cf.pppoe_ipaddr.value,lan_ip) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		parent.pppoe_wan_assign="1";
	}
	if (cf.DNSAssign[1].checked == true)
	{
		cf.pppoe_dnsaddr1.value=cf.DAddr1.value+'.'+cf.DAddr2.value+'.'+cf.DAddr3.value+'.'+cf.DAddr4.value;
		cf.pppoe_dnsaddr2.value=cf.PDAddr1.value+'.'+cf.PDAddr2.value+'.'+cf.PDAddr3.value+'.'+cf.PDAddr4.value;

		if(cf.pppoe_dnsaddr1.value=="...")
			cf.pppoe_dnsaddr1.value="";

		if(cf.pppoe_dnsaddr2.value=="...")
			cf.pppoe_dnsaddr2.value="";
		
		var wan_assign_flag;
		if(parent.pppoe_wan_assign == "0")
			wan_assign_flag=false;
		else
			wan_assign_flag=true;
		if( !check_DNS(cf.pppoe_dnsaddr1.value,cf.pppoe_dnsaddr2.value,wan_assign_flag,parent.pppoe_static_ip))
			return false;
	}
	else
	{
		cf.pppoe_dnsaddr1.value="";
		cf.pppoe_dnsaddr2.value="";
	}
	parent.pppoe_static_ip=cf.pppoe_ipaddr.value;
	parent.pppoe_dns1=cf.pppoe_dnsaddr1.value;
	parent.pppoe_dns2=cf.pppoe_dnsaddr2.value;
	location.href="RU_pppoe_dual.htm";
}

function setdualIP(cf)
{
	var dflag = cf.DualAssign[0].checked;
	setDisabled(dflag,cf.Duethr1,cf.Duethr2,cf.Duethr3,cf.Duethr4,cf.DuMask1,cf.DuMask2,cf.DuMask3,cf.DuMask4,cf.DuGateway1,cf.DuGateway2,cf.DuGateway3,cf.DuGateway4);
	DisableFixedIP = dflag;
}

function RU_check_pppoe_dual()
{
	var cf=document.forms[0];
	cf.pppoe_dual_ipaddr.value=cf.Duethr1.value+'.'+cf.Duethr2.value+'.'+cf.Duethr3.value+'.'+cf.Duethr4.value;
	cf.pppoe_dual_subnet.value=cf.DuMask1.value+'.'+cf.DuMask2.value+'.'+cf.DuMask3.value+'.'+cf.DuMask4.value;
	cf.pppoe_dual_gateway.value=cf.DuGateway1.value+'.'+cf.DuGateway2.value+'.'+cf.DuGateway3.value+'.'+cf.DuGateway4.value;
	cf.conflict_wanlan.value=0;
	if(cf.DualAssign[1].checked == true)
	{
		cf.pppoe_dual_assign.value=1;
		if(checkipaddr(cf.pppoe_dual_ipaddr.value)==false || is_sub_or_broad(cf.pppoe_dual_ipaddr.value, cf.pppoe_dual_ipaddr.value, cf.pppoe_dual_subnet.value) == false)
		{
			alert("<%getstr("invalid_ip");%>");
			return false;
		}
		if(checksubnet(cf.pppoe_dual_subnet.value)==false)
		{
			alert("<%getstr("invalid_mask");%>");
			return false;
		}
		cf.pppoe_dual_assign.value=1;
		if(isSameSubNet(cf.pppoe_dual_ipaddr.value,lan_subnet,lan_ip,lan_subnet) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameIp(cf.pppoe_dual_ipaddr.value,lan_ip) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		alert("<%getstr("attention_static_ip");%>");
	}
	else
	{
		cf.pppoe_dual_assign.value=0;
		cf.pppoe_dual_ipaddr.value="";
		cf.pppoe_dual_subnet.value="";
		cf.pppoe_dual_gateway.value="";
	}
	
	parent.conflict_wanlan=cf.conflict_wanlan.value;
	parent.pppoe_dual_assign=cf.pppoe_dual_assign.value;
	parent.pppoe_eth_ip=cf.pppoe_dual_ipaddr.value;
	parent.pppoe_eth_netmask=cf.pppoe_dual_subnet.value;
	parent.pppoe_eth_gateway=cf.pppoe_dual_gateway.value;
	location.href="RU_manual_spoof.htm";
}
