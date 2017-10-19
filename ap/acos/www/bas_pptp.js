function myip_update()
{
	var cf = document.forms[0];

	if((cf.myip_1.value.length>0)&&(cf.myip_2.value.length>0)&&(cf.myip_3.value.length>0)&&(cf.myip_4.value.length>0))
	{
		setDisabled(false, cf.mygw_1, cf.mygw_2, cf.mygw_3, cf.mygw_4);
	}
	else
	{
		setDisabled(true, cf.mygw_1, cf.mygw_2, cf.mygw_3, cf.mygw_4);
	}
}

/*
function pptp_servip_update()
{
	var disable=false;
	var cf = document.forms[0];
	var serv_array=cf.pptp_serv_ip.value.split('.');
	if (serv_array.length == 4)
	{
		var flag = 0;
		for (iptab=0; iptab<4; iptab++)
			if (isNumeric(serv_array[iptab], 255))
				flag++;
		if (flag == 4)
		{
			if (checkipaddr(cf.pptp_serv_ip.value) == false)
				disable=true;
		}
		else
		{
			disable=true;
		}
	}
	else if (cf.pptp_serv_ip.value.length > 0)
	{
		disable=true;
	}

	setDisabled(disable, cf.myip_1, cf.myip_2, cf.myip_3, cf.myip_4);
}
*/
function setDNS(cf)
{
	var dflag = cf.DNSAssign[0].checked;
	setDisabled(dflag,cf.DAddr1,cf.DAddr2,cf.DAddr3,cf.DAddr4,cf.PDAddr1,cf.PDAddr2,cf.PDAddr3,cf.PDAddr4);
	DisableFixedDNS = dflag;
}

function check_wizard_pptp(check,page)
{
	var cf=document.forms[0];
	if(cf.pptp_username.value=="")
	{
		alert("<%getstr("user_name_null");%>");
		return false;
	}
	for(i=0;i<cf.pptp_username.value.length;i++)
	{
		if(isValidChar(cf.pptp_username.value.charCodeAt(i))==false)
		{
			alert("<%getstr("invalid_login");%>");
			return false;
		}
	}
	for(i=0;i<cf.pptp_passwd.value.length;i++)
	{
		if(isValidChar(cf.pptp_passwd.value.charCodeAt(i))==false)
		{
			alert("<%getstr("bh_password_error");%>");
			return false;
		}
	}
	if(cf.pptp_idletime.value.length<=0)
	{
		alert("<%getstr("bh_idle_time_null");%>");
		return false;
	}
	else if(!_isNumeric(cf.pptp_idletime.value))
	{
		alert("<%getstr("m_proper_time");%>");
		return false;
	}
	cf.pptp_myip.value=cf.myip_1.value+'.'+cf.myip_2.value+'.'+cf.myip_3.value+'.'+cf.myip_4.value;
	cf.pptp_mynetmask.value=cf.my_mask1.value+'.'+cf.my_mask2.value+'.'+cf.my_mask3.value+'.'+cf.my_mask4.value;
	cf.pptp_gateway.value=cf.mygw_1.value+'.'+cf.mygw_2.value+'.'+cf.mygw_3.value+'.'+cf.mygw_4.value;

	if( cf.pptp_myip.value != "..." )
	{
		if(checkipaddr(cf.pptp_myip.value)==false)
		{
			alert("<%getstr("invalid_myip");%>");
			return false;
		}
		if(isSameSubNet(cf.pptp_myip.value,lan_subnet,lan_ip,lan_subnet) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameIp(cf.pptp_myip.value,lan_ip) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameSubNet(cf.pptp_myip.value,cf.pptp_mynetmask.value,lan_ip,cf.pptp_mynetmask.value) == true)
		{
			cf.conflict_wanlan.value=1;
		}
		if(isSameSubNet(cf.pptp_myip.value,cf.pptp_mynetmask.value,lan_ip,lan_subnet) == true)
		{
			cf.conflict_wanlan.value=1;
		}
	}
	if( cf.pptp_mynetmask.value != "..." )
	{
		if(checksubnet(cf.pptp_mynetmask.value)==false)
		{
			alert("<%getstr("invalid_mask");%>");
			return false;
		}
	}
	else
	{
		cf.pptp_mynetmask.value="";
	}
	if(cf.pptp_myip.value=="...")
	{
		cf.pptp_myip.value="";
		cf.pptp_gateway.value="";
		cf.WANAssign.value=0;
	}
	else
	{
		cf.WANAssign.value=1;
		if ( cf.pptp_gateway.value != "..." && checkgateway(cf.pptp_gateway.value) == false )
		{
			alert("<%getstr("invalid_gateway");%>");
			return false;
		}

		if(cf.pptp_mynetmask.value=="")
		{
			if( parseInt(cf.myip_1.value) < 128 )
				cf.pptp_mynetmask.value="255.0.0.0";
			else if(parseInt(cf.myip_1.value) < 192 )
				cf.pptp_mynetmask.value="255.255.0.0";
			else
				cf.pptp_mynetmask.value="255.255.255.0";
		}
		if( cf.pptp_gateway.value != "..." )
		{
			if(isGateway(cf.pptp_myip.value,cf.pptp_mynetmask.value,cf.pptp_gateway.value) == false)
			{
				alert("<%getstr("invalid_gateway");%>");
				return false;
			}
			if(isSameIp(cf.pptp_myip.value,cf.pptp_gateway.value) == true)
			{
				alert("<%getstr("invalid_gateway");%>");
				return false;
			}
		}
		else
			cf.pptp_gateway.value="";
	}

	if(cf.pptp_serv_ip.value=="")
	{
		alert("<%getstr("invalid_servip");%>");
		return false;
	}
	for(i=0;i<cf.pptp_serv_ip.value.length;i++)
	{
		if(isValidChar(cf.pptp_serv_ip.value.charCodeAt(i))==false)
		{
			alert("<%getstr("invalid_servip");%>");
			return false;
		}
	}
	if( cf.pptp_serv_ip.value == cf.pptp_myip.value )
	{
		alert("<%getstr("ip_is_same");%>");
		return false;
	}

	/*
	var serv_array=cf.pptp_serv_ip.value.split('.');
	if( serv_array.length==4 )
	{
		var flag = 0;
		for( iptab=0; iptab<4; iptab++ )
			if( isNumeric(serv_array[iptab], 255) )
				flag++;
		if( flag == 4 )
		{
			if ( checkipaddr(cf.pptp_serv_ip.value) == false )
			{
				alert("<%getstr("invalid_servip");%>");
				return false;
			}
		}
		else //if the serverip is not a correct ip, it is a FQDN. then the My IP Address MUST be blank to indicate DHCP is used to get the router's IP address
		{
			cf.WANAssign.value=0;
			cf.pptp_myip.value="";
			cf.pptp_gateway.value="";
		}
	}
	else //if the serverip is not a correct ip, it is a FQDN. then the My IP Address MUST be blank to indicate DHCP is used to get the router's IP address
	{
		cf.WANAssign.value=0;
		cf.pptp_myip.value="";
		cf.pptp_gateway.value="";
	}
	*/
	for(i=0;i<cf.pptp_conn_id.value.length;i++)
	{
		if(isValidChar(cf.pptp_conn_id.value.charCodeAt(i))==false)
		{
			alert("<%getstr("invalid_conn_id");%>");
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
	if (cf.WANAssign.value == 1)
	{
		if(isSameSubNet(cf.pptp_myip.value,cf.pptp_mynetmask.value,cf.pptp_serv_ip.value,cf.pptp_mynetmask.value) != true)
		{
			if(isSameSubNet(cf.pptp_myip.value,cf.pptp_mynetmask.value,cf.pptp_gateway.value,cf.pptp_mynetmask.value) != true)
			{
				alert("<%getstr("invalid_gateway");%>");
				return false;
			}
		}
	}
	return true;
}

function check_pptp(cf,check)
{
	var wan_assgin = false;
	if(check_wizard_pptp(check,"bas")==false)
		return false;
	cf.hidden_pptp_idle_time.value=cf.pptp_idletime.value;

	if(cf.WANAssign.value == 1)
		wan_assgin = true;
	
	var server_addr_array = cf.pptp_serv_ip.value.split('.');
	var i;
	for( i=0; i<server_addr_array.length; i++ )
	{
		if( server_addr_array[i].length > 63 )
		{
			alert("<%getstr("invalid_servip");%>");
			return false;
		}
	}
	
	if(cf.DNSAssign[1].checked == true)
	{
		cf.pptp_dnsaddr1.value=cf.DAddr1.value+'.'+cf.DAddr2.value+'.'+cf.DAddr3.value+'.'+cf.DAddr4.value;
		cf.pptp_dnsaddr2.value=cf.PDAddr1.value+'.'+cf.PDAddr2.value+'.'+cf.PDAddr3.value+'.'+cf.PDAddr4.value;

		if(cf.pptp_dnsaddr1.value=="...")
			cf.pptp_dnsaddr1.value="";
		if(cf.pptp_dnsaddr2.value=="...")
			cf.pptp_dnsaddr2.value="";
	
		if(!check_DNS(cf.pptp_dnsaddr1.value,cf.pptp_dnsaddr2.value,wan_assgin,cf.pptp_myip.value))
			return false;
	}
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
	if(!(old_wan_type=="pptp"))
		cf.change_wan_type.value=0;
	else
		cf.change_wan_type.value=1;

	return true;
}

function setIP_welcome_pptp()
{
	var cf = document.forms[0];
	var dflag = cf.WANAssign[0].checked;
	setDisabled(dflag,cf.myip_1,cf.myip_2,cf.myip_3,cf.myip_4);
	DisableFixedIP = dflag;
}


function check_welcome_pptp()
{
	var cf = document.forms[0];
	if(check_wizard_pptp(0,"welcome")==false)
		return false;
	parent.pptp_username=cf.pptp_username.value;
	parent.pptp_password=cf.pptp_passwd.value;
	parent.pptp_idle_time=cf.pptp_idletime.value;
	/*
	cf.pptp_myip.value=cf.myip_1.value+'.'+cf.myip_2.value+'.'+cf.myip_3.value+'.'+cf.myip_4.value;
	cf.pptp_gateway.value=cf.mygw_1.value+'.'+cf.mygw_2.value+'.'+cf.mygw_3.value+'.'+cf.mygw_4.value;
	cf.pptp_mynetmask.value=cf.my_mask1.value+'.'+cf.my_mask2.value+'.'+cf.my_mask3.value+'.'+cf.my_mask4.value;
	if(cf.pptp_myip.value=="...")
	{
		cf.pptp_myip.value="";
		cf.WANAssign.value=0;
		parent.pptp_wan_assign=0;
	}
	else
	{
		if(checkipaddr(cf.pptp_myip.value)==false)
		{
			alert("<%getstr("invalid_myip");%>");
			return false;
		}
		cf.WANAssign.value=1;
		parent.pptp_wan_assign=1;
	}
	if( cf.pptp_gateway.value != "..." )
	{
		if(checkipaddr(cf.pptp_gateway.value)==false)
		{
			alert("<%getstr("invalid_gateway");%>");
			return false;
		}
	}
	else
	{
		cf.pptp_gateway.value="";
	}
	if( cf.pptp_mynetmask.value != "..." )
	{
		if(checksubnet(cf.pptp_mynetmask.value)==false)
		{
			alert("<%getstr("invalid_mask");%>");
			return false;
		}
	}
	else
	{
		cf.pptp_mynetmask.value="";
	}
	if (cf.WANAssign.value==1)
	{
		if(isSameSubNet(cf.pptp_myip.value,cf.pptp_mynetmask.value,cf.pptp_serv_ip.value,cf.pptp_mynetmask.value) != true)
		{
			if(isSameSubNet(cf.pptp_myip.value,cf.pptp_mynetmask.value,cf.pptp_gateway.value,cf.pptp_mynetmask.value) != true)
			{
				alert("<%getstr("invalid_gateway");%>");
				return false;
			}
		}
	}
	*/
	parent.pptp_local_ipaddr=cf.pptp_myip.value;
	parent.pptp_local_netmask=cf.pptp_mynetmask.value;
	parent.pptp_local_gateway=cf.pptp_gateway.value;
	parent.pptp_server_ipaddr=cf.pptp_serv_ip.value;
	parent.pptp_connect_id=cf.pptp_conn_id.value;
	parent.welcome_wan_type=4;
	return true;
}

function pptp_servip_update(I)
{
	var cf = document.forms[0];
	servName = cf.pptp_serv_ip.value;
	if((servName.search(/[A-Za-z]/i) != -1) &&
		((cf.myip_1.value.length > 0) || 
		 (cf.myip_2.value.length > 0) ||
		 (cf.myip_3.value.length > 0) ||
		 (cf.myip_4.value.length > 0) ) )
	{
		if(cf.DNSAssign[0].checked == true)
		{
			cf.DAddr1.disabled=false;
			cf.DAddr2.disabled=false;
			cf.DAddr3.disabled=false;
			cf.DAddr4.disabled=false;

			cf.PDAddr1.disabled=false;
			cf.PDAddr2.disabled=false;
			cf.PDAddr3.disabled=false;
			cf.PDAddr4.disabled=false;
		}
		cf.DNSAssign[0].checked=false;
		cf.DNSAssign[1].checked=true;
		cf.DNSAssign[0].disabled=true;
		cf.STATIC_DNS.value=1;

	}
	else
	{
		cf.DNSAssign[0].disabled=false;
		cf.STATIC_DNS.value=0;
	}
}

function RU_pptp_user_info()
{
	var cf=document.forms[0];
	if(cf.pptp_username.value=="")
	{
		alert("<%getstr("user_name_null");%>");
		return false;
	}
	for(i=0;i<cf.pptp_username.value.length;i++)
	{
		if(isValidChar(cf.pptp_username.value.charCodeAt(i))==false)
		{
			alert("<%getstr("invalid_login");%>");
			return false;
		}
	}
	for(i=0;i<cf.pptp_passwd.value.length;i++)
	{
		if(isValidChar(cf.pptp_passwd.value.charCodeAt(i))==false)
		{
			alert("<%getstr("bh_password_error");%>");
			return false;
		}
	}
	if(cf.pptp_serv_ip.value=="")
	{
		alert("<%getstr("invalid_servip");%>");
		return false;
	}
	for(i=0;i<cf.pptp_serv_ip.value.length;i++)
	{
		if(isValidChar(cf.pptp_serv_ip.value.charCodeAt(i))==false)
		{
			alert("<%getstr("invalid_servip");%>");
			return false;
		}
	}
	var server_addr_array = cf.pptp_serv_ip.value.split('.');
	var i;
	for( i=0; i<server_addr_array.length; i++ )
	{
		if( server_addr_array[i].length > 63 )
		{
			alert("<%getstr("invalid_servip");%>");
			return false;
		}
	}

	if (cf.submit_wan)
		cf.submit_wan.value = parent.isp_type;

	parent.pptp_username=cf.pptp_username.value;
	parent.pptp_password=cf.pptp_passwd.value;
	parent.pptp_server_ipaddr=cf.pptp_serv_ip.value;
	parent.welcome_wan_type=4;
	
	if(parent.isp_type=="12")
	{
		cf.basic_type.value="0";
		cf.ppp_login_type.value="1";
		cf.welcome_wan_type.value="4";
		cf.pptp_dnsaddr1.value=parent.static_dns1;
		cf.pptp_dnsaddr2.value=parent.static_dns2;
		if(cf.pptp_dnsaddr1.value != "" || cf.pptp_dnsaddr2.value!= "")
			cf.DNSAssign.value="1";
		else 
			cf.DNSAssign.value="0";
		cf.WANAssign.value="0";
		cf.STATIC_DNS.value="0";
		cf.submit();
	}
	else if(parent.isp_type=="11")
	{
		location.href="RU_isp_spoof.htm";
	}
	else if(parent.isp_type=="9" || parent.isp_type=="10")
	{
		location.href="RU_isp_pptp_static.htm";
	}
	else
		location.href="RU_manual_pptp_dual.htm";
}

function setIP(cf)
{
	var dflag = cf.DualAssign[0].checked;
	setDisabled(dflag,cf.myip_1,cf.myip_2,cf.myip_3,cf.myip_4,cf.my_mask1,cf.my_mask2,cf.my_mask3,cf.my_mask4,cf.mygw_1,cf.mygw_2,cf.mygw_3,cf.mygw_4);
	DisableFixedIP = dflag;
}

function RU_pptp_servip_FQDN(I)
{
	var cf = document.forms[0];
	servName = cf.pptp_serv_ip.value;
	if(servName.search(/[A-Za-z]/i) != -1)
	{
		parent.pptp_server_FQDN=1;
	}
	else
	{
		parent.pptp_server_FQDN=0;
	}
}

function RU_pptp_servip_update(I)
{
	var cf = document.forms[0];
	if((parent.pptp_server_FQDN == 1) &&
		((cf.myip_1.value.length > 0) || 
		 (cf.myip_2.value.length > 0) ||
		 (cf.myip_3.value.length > 0) ||
		 (cf.myip_4.value.length > 0) ) )
	{
		if(cf.DNSAssign[0].checked == true)
		{
			cf.DAddr1.disabled=false;
			cf.DAddr2.disabled=false;
			cf.DAddr3.disabled=false;
			cf.DAddr4.disabled=false;

			cf.PDAddr1.disabled=false;
			cf.PDAddr2.disabled=false;
			cf.PDAddr3.disabled=false;
			cf.PDAddr4.disabled=false;
		}
		cf.DNSAssign[0].checked=false;
		cf.DNSAssign[1].checked=true;
		cf.DNSAssign[0].disabled=true;
		cf.STATIC_DNS.value=1;

	}
	else
	{
		cf.DNSAssign[0].disabled=false;
		cf.STATIC_DNS.value=0;
	}
}

function RU_check_pptp_dual()
{
	var cf=document.forms[0];
	var wan_assgin = false;
	cf.pptp_myip.value=cf.myip_1.value+'.'+cf.myip_2.value+'.'+cf.myip_3.value+'.'+cf.myip_4.value;
	cf.pptp_mynetmask.value=cf.my_mask1.value+'.'+cf.my_mask2.value+'.'+cf.my_mask3.value+'.'+cf.my_mask4.value;
	cf.pptp_gateway.value=cf.mygw_1.value+'.'+cf.mygw_2.value+'.'+cf.mygw_3.value+'.'+cf.mygw_4.value;
	if(cf.DualAssign[1].checked == true)
	{
		wan_assgin = true;
		parent.pptp_wan_assign=1;
		if(checkipaddr(cf.pptp_myip.value)==false)
		{
			alert("<%getstr("invalid_myip");%>");
			return false;
		}
		if(checksubnet(cf.pptp_mynetmask.value)==false)
		{
			alert("<%getstr("invalid_mask");%>");
			return false;
		}
		if ( cf.pptp_gateway.value != "..." && checkgateway(cf.pptp_gateway.value) == false )
		{
			alert("<%getstr("invalid_gateway");%>");
			return false;
		}
		if( cf.pptp_gateway.value != "..." )
		{
			if(isGateway(cf.pptp_myip.value,cf.pptp_mynetmask.value,cf.pptp_gateway.value) == false)
			{
				alert("<%getstr("invalid_gateway");%>");
				return false;
			}
			if(isSameIp(cf.pptp_myip.value,cf.pptp_gateway.value) == true)
			{
				alert("<%getstr("invalid_gateway");%>");
				return false;
			}
		}
		else
			cf.pptp_gateway.value="";
		if(isSameSubNet(cf.pptp_myip.value,cf.pptp_mynetmask.value,pptp_serv_ip,cf.pptp_mynetmask.value) != true)
		{
			if(isSameSubNet(cf.pptp_myip.value,cf.pptp_mynetmask.value,cf.pptp_gateway.value,cf.pptp_mynetmask.value) != true)
			{
				alert("<%getstr("invalid_gateway");%>");
				return false;
			}
		}
	}
	else
	{
		cf.pptp_myip.value="";
		cf.pptp_mynetmask.value="";
		cf.pptp_gateway.value="";
		parent.pptp_wan_assign=0;
	}
	if(cf.DNSAssign[1].checked == true)
	{
		cf.pptp_dnsaddr1.value=cf.DAddr1.value+'.'+cf.DAddr2.value+'.'+cf.DAddr3.value+'.'+cf.DAddr4.value;
		cf.pptp_dnsaddr2.value=cf.PDAddr1.value+'.'+cf.PDAddr2.value+'.'+cf.PDAddr3.value+'.'+cf.PDAddr4.value;

		if(cf.pptp_dnsaddr1.value=="...")
			cf.pptp_dnsaddr1.value="";
		if(cf.pptp_dnsaddr2.value=="...")
			cf.pptp_dnsaddr2.value="";

		if(!check_DNS(cf.pptp_dnsaddr1.value,cf.pptp_dnsaddr2.value,wan_assgin,cf.pptp_myip.value))
			return false;
	}
	else
	{
		cf.pptp_dnsaddr1.value="";
		cf.pptp_dnsaddr2.value="";
	}
	if(cf.DualAssign[1].checked == true)
		alert("<%getstr("attention_static_ip");%>");
	parent.pptp_local_ipaddr=cf.pptp_myip.value;
	parent.pptp_local_netmask=cf.pptp_mynetmask.value;
	parent.pptp_local_gateway=cf.pptp_gateway.value;
	parent.pptp_dns1=cf.pptp_dnsaddr1.value;
	parent.pptp_dns2=cf.pptp_dnsaddr2.value;
	parent.STATIC_DNS=cf.STATIC_DNS.value;
	location.href="RU_manual_spoof.htm";
}
