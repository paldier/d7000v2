function check_DNS(dnsaddr1,dnsaddr2,wan_assign,wan_ip)
{
	if(dnsaddr1!="")
	{
		if(checkipaddr(dnsaddr1)==false)
		{
			alert("<%getstr("invalid_primary_dns");%>");
			return false;
		}
		if( wan_assign == true && isSameIp(dnsaddr1,wan_ip))
		{
			alert("<%getstr("invalid_primary_dns");%>");
			return false;
		}
	}
	if(dnsaddr2!="")
	{
		if(checkipaddr(dnsaddr2)==false)
		{
			alert("<%getstr("invalid_primary_dns");%>");
			return false;
		}
		if( wan_assign == true && isSameIp(dnsaddr2,wan_ip))
		{
			alert("<%getstr("invalid_primary_dns");%>");
			return false;
		}
	}

	if(dnsaddr1=="" && dnsaddr2=="" )
	{
		alert("<%getstr("invalid_primary_dns");%>");
		return false;
	}
	return true;
}
/*
	Saturday, Jan 01, 2000 10:51:13
*/
function change_cur_time(old_str,gui_region)
{
	each_str=old_str.split(', ');

	week=each_str[0];
	show_week=change_full_week(week);

	date_info=each_str[1].split(' ');
	month=date_info[0];
	show_month=change_month(month);
	day=date_info[1];

	time=each_str[2];

	if( gui_region == "German" )
		new_str = show_week+', '+day+'.'+show_month+', '+time;
	else
		new_str = show_week+', '+show_month+' '+day+', '+time;

	return new_str;
}

function change_week(week)
{
	var show_week;
	if(week == "Mon")
		show_week="Monday";
	else if(week == "Tue")
		show_week="Tuesday";
	else if(week == "Wed")
		show_week="Wednesday";
	else if(week == "Thu")
		show_week="Thursday";
	else if(week == "Fri")
		show_week="Friday";
	else if(week == "Sat")
		show_week="Saturday";
	else if(week == "Sun")
		show_week="Sunday";
	else
		show_week=week;

	return show_week;
}

function change_full_week(week)
{
	var show_week;
	if(week == "Monday")
		show_week="Monday";
	else if(week == "Tuesday")
		show_week="Tuesday";
	else if(week == "Wednesday")
		show_week="Wednesday";
	else if(week == "Thursday")
		show_week="Thursday";
	else if(week == "Friday")
		show_week="Friday";
	else if(week == "Saturday")
		show_week="Saturday";
	else if(week == "Sunday")
		show_week="Sunday";
	else
		show_week=week;

	return show_week;
}

function change_month(month)
{
	var show_month;
	if( month == "Jan" )
		show_month="Jan";
	else if( month == "Feb" )
		show_month="Feb";
	else if( month == "Mar" )
		show_month="Mar";
	else if( month == "Apr" )
		show_month="Apr";
	else if( month == "May" )
		show_month="May";
	else if( month == "Jun" )
		show_month="Jun";
	else if( month == "Jul" )
		show_month="Jul";
	else if( month == "Aug" )
		show_month="Aug";
	else if( month == "Sep" )
		show_month="Sep";
	else if( month == "Oct" )
		show_month="Oct";
	else if( month == "Nov" )
		show_month="Nov";
	else if( month == "Dec" )
		show_month="Dec";
	else
		show_month=month;
	return show_month;
}

function change_month2num(month)
{
	var show_month;
	if( month == "Jan" )
		show_month="1";
	else if( month == "Feb" )
		show_month="2";
	else if( month == "Mar" )
		show_month="3";
	else if( month == "Apr" )
		show_month="4";
	else if( month == "May" )
		show_month="5";
	else if( month == "Jun" )
		show_month="6e";
	else if( month == "Jul" )
		show_month="7";
	else if( month == "Aug" )
		show_month="8";
	else if( month == "Sep" )
		show_month="9";
	else if( month == "Oct" )
		show_month="10";
	else if( month == "Nov" )
		show_month="11";
	else if( month == "Dec" )
		show_month="12";
	else
		show_month=month;
	return show_month;
}

/* input ip, if input length = 3 or input '.' , change focus to next text, */
function keydown(e,text)
{
	if((e.keyCode == 190 || e.keyCode == 110) && text.value.length !=0)
		text.form[(getIndex(text)+1) % text.form.length].focus();
}
function keyup(e,text)
{
	if(text.value.length == 3 && (e.keyCode != 190 && e.keyCode != 110 && e.keyCode != 9))
		text.form[(getIndex(text)+1) % text.form.length].focus();
}
function getIndex(input)
{
	var index = -1;
	var i = 0;
	var found = false;
	while (i < input.form.length && index == -1)
		if (input.form[i] == input)
			index = i;
		else
			i++;
	return index;
}

function getObj(name)
{
	if (document.getElementById)
	{
		return document.getElementById(name).style;
	}
	else if (document.all)
	{
		return document.all[name].style;
	}
	else if (document.layers)
	{
		return document.layers[name];
	}
}

function check_maxNumAdd(form,nowNum,maxNum,msg,go2href)
{
	nowNum=parseInt(nowNum,10);
	if (nowNum >= maxNum)
	{
		alert(msg);
		return false;
	}
	else
		location.href=go2href;
}

function checkIPMain(ip,max)
{
	if (isNumeric(ip, max) == false)
		return false;
}

function checkIP(ip1, ip2, ip3, ip4,max)
{
	if(checkIPMain(ip1,255)==false) return false;
	if(checkIPMain(ip2,255)==false) return false;
	if(checkIPMain(ip3,255)==false) return false;
	if(checkIPMain(ip4,max)==false) return false;
	if((parseInt(ip1)==0)||(parseInt(ip1)==0)&&(parseInt(ip2)==0)&&(parseInt(ip3)==0)&&(parseInt(ip4)==0))
		return false;
	if ( ip1 == 0 )
		return false;
	return true;
}

/* Check Numeric*/
function isNumeric(str, max)
{
	if(str.length == 0 || str == null || str == "")
		return false;
	for(i=0; i<str.length; i++)
	{
		var c = str.substring(i, i+1);
		if("0" <= c && c <= "9") 
			continue;
		else
			return false;
	}
	var i = parseInt(str);
	if(i>max) 
		return false;

	return true;
}

function isIE()
{
	var browser = new Object();
	browser.version = parseInt(navigator.appVersion);
	browser.isNs = false;
	browser.isIe = false;
	if(navigator.appName.indexOf("Netscape") != -1)
		browser.isNs = true;
	else if(navigator.appName.indexOf("Microsoft") != -1)
		browser.isIe = true;

	if(browser.isNs)
		return false;
	else if (browser.isIe)
		return true;
	else
		return false;
}

function get_browser()
{
	if(navigator.userAgent.indexOf("MSIE") != -1)
		return "IE";
	else if(navigator.userAgent.indexOf("Firefox") != -1)
		return "Firefox";
	else if(navigator.userAgent.indexOf("Safari") != -1 )
		return "Safari";
	else if(navigator.userAgent.indexOf("Camino") != -1) 
		return "Camino";
	else if(navigator.userAgent.indexOf("Gecko/") != -1)
		return "Gecko";
	else
		return "";
}

function load_default(step)
{
	if (parent.frames['IA_menu'])
	{
		for(var i=1;i<=3;i++)
		{
			var element = parent.frames['IA_menu'].document.getElementById("IA_menu_" + i);
			element.className="left_nav_headers";
		}
		var element_current = parent.frames['IA_menu'].document.getElementById("IA_menu_" + step);
		element_current.className="left_nav_headers_current_state";
	}
}

function _isNumeric(str)
{
	var i;
	for(i = 0; i<str.length; i++)
	{
		var c = str.substring(i, i+1);
		if("0" <= c && c <= "9")
		{
			continue;
		}
		return false;
	}
	return true;
}

function isSameIp(ipstr1,ipstr2)
{
	var count = 0;
	var ip1_array=ipstr1.split('.');
	var ip2_array=ipstr2.split('.');
	for(i = 0;i<4;i++)
	{
		num1 = parseInt(ip1_array[i]);
		num2 = parseInt(ip2_array[i]);
		if( num1 == num2)
			count++;
	}
	if( count == 4)
		return true;
	else
		return false;
}

function cp_ip2(from,to)
//true invalid from and to ip;  false valid from and to ip;
{
	var total1 = 0;
	var total2 = 0;
	var from_array=from.split('.');
	var to_array = to.split('.');
	var from1=from_array[0];
	var from2=from_array[1];
	var from3=from_array[2];
	var from4=from_array[3];
	var to1=to_array[0];
	var to2=to_array[1];
	var to3=to_array[2];
	var to4=to_array[3];

	total1 += parseInt(from4);
	total1 += parseInt(from3)*256;
	total1 += parseInt(from2)*256*256;
	total1 += parseInt(from1)*256*256*256;

	total2 += parseInt(to4);
	total2 += parseInt(to3)*256;
	total2 += parseInt(to2)*256*256;
	total2 += parseInt(to1)*256*256*256;
	if(total1 <= total2)
		return true;
	return false;
}

function is_sub_or_broad(be_checkip, ip, mask)
{
	var addr_arr = be_checkip.split('.');
	var ip_addr=0;
	for (i = 0; i < 4; i++)
	{
		addr_str = parseInt(addr_arr[i],10);
		ip_addr=ip_addr*256+parseInt(addr_str);
	}
	var ip_sub=isSub(ip, mask);
	var ip_broadcast=isBroadcast(ip, mask);
	if(ip_addr == ip_sub || ip_addr == ip_broadcast)
	{
		return false;
	}
	return true;
}

function isGateway(lanIp, lanMask, gtwIp)
{
	var gtw_arr = gtwIp.split('.');
	var ip_gtw=0;
	for (i = 0; i < 4; i++)
	{
		gtw_str = parseInt(gtw_arr[i],10);
		ip_gtw=ip_gtw*256+parseInt(gtw_str);
	}

	var addr_arr = lanIp.split('.');
	var ip_addr=0;
	for (i = 0; i < 4; i++)
	{
		addr_str = parseInt(addr_arr[i],10);
		ip_addr=ip_addr*256+parseInt(addr_str);
	}

	var ip_sub=isSub(lanIp, lanMask);
	var ip_broadcast=isBroadcast(lanIp, lanMask);
	if((parseInt(ip_sub)<parseInt(ip_gtw))&&(parseInt(ip_gtw)<parseInt(ip_broadcast)))
		return true;
	else
		return false;
}

function isSub(lanIp, lanMask)
{
	var ip_arr = lanIp.split('.');
	var mask_arr = lanMask.split('.');
	var ip_sub=0
	for (i = 0; i < 4; i++)
	{
		ip_str = parseInt(ip_arr[i],10);
		mask_str = parseInt(mask_arr[i],10);
		ip_sub=ip_sub*256+parseInt(ip_str & mask_str)
	}
	return(ip_sub);
}

function isBroadcast(lanIp, lanMask)
{
	var ip_arr = lanIp.split('.');
	var mask_arr = lanMask.split('.');
	var ip_broadcast=0;
	for (i = 0; i < 4; i++)
	{
		ip_str = parseInt(ip_arr[i],10);
		mask_str = parseInt(mask_arr[i],10);
		n_str = ~mask_str+256;
		ip_broadcast=ip_broadcast*256+parseInt(ip_str | n_str);
	}
	return(ip_broadcast);
}

function isSameSubNet(lan1Ip, lan1Mask, lan2Ip, lan2Mask)
{
	var count = 0;
	var lan1a = lan1Ip.split('.');
	var lan1m = lan1Mask.split('.');
	var lan2a = lan2Ip.split('.');
	var lan2m = lan2Mask.split('.');
	for (i = 0; i < 4; i++) 
	{
		l1a_n = parseInt(lan1a[i],10);
		l1m_n = parseInt(lan1m[i],10);
		l2a_n = parseInt(lan2a[i],10);
		l2m_n = parseInt(lan2m[i],10);
		if ((l1a_n & l1m_n) == (l2a_n & l2m_n))
			count++;
	}
	if (count == 4)
		return true;
	else
		return false;
}
function checkipaddr(ipaddr)
{
	var form = document.forms[0];
	var ipArray = ipaddr.split(".");
	var ipstr = ipArray[0]+ipArray[1]+ipArray[2]+ipArray[3];
	var i = 0;

	if((ipArray[0]=="")||(ipArray[0]<0)||(ipArray[0]>255)||(ipArray[1]=="")||(ipArray[1]<0)||(ipArray[1]>255)
			||(ipArray[2]=="")||(ipArray[2]<0)||(ipArray[2]>255)||(ipArray[3]=="")||(ipArray[3]<0)||(ipArray[3]>255))
	{
		return false;
	}
	for(i=0;i<ipstr.length;i++)
	{
		if((ipstr.charAt(i)!='0')&&(ipstr.charAt(i)!='1')&&(ipstr.charAt(i)!='2')
			&&(ipstr.charAt(i)!='3')&&(ipstr.charAt(i)!='4')&&(ipstr.charAt(i)!='5')
			&&(ipstr.charAt(i)!='6')&&(ipstr.charAt(i)!='7')&&(ipstr.charAt(i)!='8')
			&&(ipstr.charAt(i)!='9'))
		{
			return false;
		}
	}
	if( ipArray[0] > 223 || ipArray[0] == 0 )
		return false;
	if (ipaddr == "0.0.0.0" || ipaddr == "255.255.255.255")
	{
		return false;
	}

	var each=ipaddr.split(".");
	if (each[0] == "127")
	{
		return false;
	}
	if (!ipArray || ipArray.length != 4)
	{
		return false;
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			thisSegment = ipArray[i];
			if (thisSegment != "")
			{
				if(i==3)
				{
					if (!((ipArray[3] > 0) && (ipArray[3] < 255)))
					{
						return false;
					}
				}
				else if (!(thisSegment >=0 && thisSegment <= 255))
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}

	}
	return true;
}

function checksubnet(subnet)
{
	var subnetArray = subnet.split(".");
	var subnetstr = subnetArray[0]+subnetArray[1]+subnetArray[2]+subnetArray[3];
	var i = 0;
	var maskTest = 0;
	var validValue = true;

	if((subnetArray[0]=="")||(subnetArray[0]<0)||(subnetArray[0]>255)||(subnetArray[1]=="")||(subnetArray[1]<0)||(subnetArray[1]>255)
		||(subnetArray[2]=="")||(subnetArray[2]<0)||(subnetArray[2]>255)||(subnetArray[3]=="")||(subnetArray[3]<0)||(subnetArray[3]>255))
	{
		return false;
	}
	for(i=0;i<subnetstr.length;i++)
	{
		if((subnetstr.charAt(i)!='0')&&(subnetstr.charAt(i)!='1')&&(subnetstr.charAt(i)!='2')
			&&(subnetstr.charAt(i)!='3')&&(subnetstr.charAt(i)!='4')&&(subnetstr.charAt(i)!='5')
			&&(subnetstr.charAt(i)!='6')&&(subnetstr.charAt(i)!='7')&&(subnetstr.charAt(i)!='8')
			&&(subnetstr.charAt(i)!='9'))
		{
			return false;
		}
	}
	if (!subnetArray || subnetArray.length != 4)
	{
		return false;
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			thisSegment = subnetArray[i];
			if (thisSegment != "")
			{
				if (!(thisSegment >=0 && thisSegment <= 255))
				{ //check if number?
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	if( subnetArray[0] < 255 )
	{
		if( (subnetArray[1] > 0) || (subnetArray[2] > 0) || (subnetArray[3] > 0))
			validValue = false;
		else
			maskTest = subnetArray[0];
	}
	else
	{
		if( subnetArray[1] < 255 )
		{
			if( (subnetArray[2] > 0) || (subnetArray[3] > 0))
				validValue = false;
			else
				maskTest = subnetArray[1];
		}
		else
		{
			if( subnetArray[2] < 255 )
			{
				if( (subnetArray[3] > 0) )
					validValue = false;
				else
					maskTest = subnetArray[2];
			}
			else
				maskTest = subnetArray[3];
		}
	}
	if( validValue )
	{
		switch( maskTest )
		{
			case "0":
			case "128":
			case "192":
			case "224":
			case "240":
			case "248":
			case "252":
			case "254":
			case "255":
				break;
			default:
				validValue = false;
		}
		if( subnet == "0.0.0.0" )
			validValue = false;
	}
	else
		validValue = false;

	return validValue;
}

function checkgateway(gateway)
{
	var form = document.forms[0];
	var dgArray = gateway.split(".");
	var dgstr = dgArray[0]+dgArray[1]+dgArray[2]+dgArray[3];
	var i = 0;

	if((dgArray[0]=="")||(dgArray[0]<0)||(dgArray[0]>255)||(dgArray[1]=="")||(dgArray[1]<0)||(dgArray[1]>255)
		||(dgArray[2]=="")||(dgArray[2]<0)||(dgArray[2]>255)||(dgArray[3]=="")||(dgArray[3]<0)||(dgArray[3]>255))
	{
		return false;
	}
	for(i=0;i<dgstr.length;i++)
	{
		if((dgstr.charAt(i)!='0')&&(dgstr.charAt(i)!='1')&&(dgstr.charAt(i)!='2')
			&&(dgstr.charAt(i)!='3')&&(dgstr.charAt(i)!='4')&&(dgstr.charAt(i)!='5')
			&&(dgstr.charAt(i)!='6')&&(dgstr.charAt(i)!='7')&&(dgstr.charAt(i)!='8')
			&&(dgstr.charAt(i)!='9'))
		{
			return false;
		}
	}
	if( dgArray[0] > 223 || dgArray[0] == 0 )
		return false;
	if (gateway == "0.0.0.0" || gateway == "255.255.255.255")
	{
		return false;
	}
	if (gateway == "127.0.0.1")
	{
		return false;
	}
	if (!dgArray || dgArray.length != 4)
	{
		return false;
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			thisSegment = dgArray[i];
			if (thisSegment != "")
			{
				if (!(thisSegment >=0 && thisSegment <= 255))
				{ //check if number?
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
function loadhelp(fname,anchname)
{
	if(parent.parent.help_info)
		parent.parent.help_info = fname;
	if ((loadhelp.arguments.length == 1 ) || (anchname == "" ))
		top.helpframe.location.href="/help.htm"; 
	else
		top.helpframe.location.href="/help.htm#" + anchname;

	return;
}

function getkeya(e)
{
	var keycode;
	if (window.event)
	{
		keycode = window.event.keyCode;
		if (((keycode>47) && (keycode<58))||(keycode==8)||((keycode>64) && (keycode<71))||((keycode>96) && (keycode<103)))
		{
			return true;
		}
		else
			return false;
	}
	else if (e)
	{
		keycode = e.which;
		if (((keycode>47) && (keycode<58))||(keycode==8)||(keycode==0)||((keycode>64) && (keycode<71))||((keycode>96) && (keycode<103)))
		{
			return true;
		}
		else
			return false;
	}
	else
	{
		return true;
	}
}
function getkey(type, e)
{
	var keycode, event;

	if (window.event) 
	{
		event = window.event;
		keycode = window.event.keyCode;
	}
	else if (e)
	{
		event = e;
		keycode = e.which;
	}
	else
		return true;

	if(event.ctrlKey && ( keycode==99 || keycode==118 || keycode==120) )
		return true;

	if(type == "apname")
	{
		if ((keycode==34) ||(keycode==39)||(keycode==92))
		{
			return false;
		}
		else
			return true;
	}
	else if(type == "ipaddr")
	{	
		if (((keycode>47) && (keycode<58))||(keycode==8)||(keycode==0)||(keycode==46))
		{
			return true;
		}
		else
			return false;
	}
	else if(type == "ssid")
	{
		//if (keycode==32)
		//	return false;
		//else
		//	return true;
		return true;
	}
	else if(type == "wep")
	{
		if (((keycode>47) && (keycode<58))||((keycode>64) && (keycode<71))||((keycode>96) && (keycode<103))||(keycode == 8)||(keycode == 0))
			return true;
		else
			return false;
	}
	else if(type == "num")
	{
		if (((keycode>47) && (keycode<58)) || (keycode==8)||(keycode==0))
			return true;
		else
			return false;
	}
	else if(type == "hostname")
	{
		if (((keycode>47) && (keycode<58))||(keycode==45)||((keycode>64) && (keycode<91))||((keycode>96) && (keycode<123)) || (keycode==8)||(keycode==0))
		{
			return true;
		}
		else
			return false;
	}
	else if(type == "ddns_hostname")
	{
		if (((keycode>47) && (keycode<58))||(keycode==45)||(keycode==46)||((keycode>64) && (keycode<91))||((keycode>96) && (keycode<123)) || (keycode==8)||(keycode==0))
		{
			return true;
		}
		else
			return false;
	}
	else if(type == "mac")
	{
		if (((keycode>47) && (keycode<58))||((keycode>64) && (keycode<71))||((keycode>96) && (keycode<103))||(keycode == 8)||(keycode == 0) || (keycode == 58) || (keycode == 45))
			return true;
		else
			return false;
	}
	else if(type == "folderPath")// not / * ? " <>
	{
		if((keycode==47) || (keycode==42) || (keycode==63) || (keycode==34) || (keycode==60) || (keycode==62) ||(keycode==124))
			return false;
		else
			return true;
	}
	else if(type == "shareName")// not / * ? " <> \ :
	{
		if((keycode==47) || (keycode==42) || (keycode==63) || (keycode==34) || (keycode==60) || (keycode==62) ||(keycode==58) || (keycode==92) || (keycode==93) || (keycode==124))
			return false;
		else
			return true;
	}
	else if(type == "ascii")
	{
		if ((keycode<32) || (keycode>126))
			return false;
		else
			return true;
	}
	else
		return false;
}



function changesectype(fname)
{
	var html_href;
	if(fname.options[0].selected == true)
		html_href = "security_off.asp";
	else if(fname.options[1].selected == true)
		html_href = "wep.asp";
	else if(fname.options[2].selected == true)
		html_href = "wpa.asp";
	else if(fname.options[3].selected == true)
		html_href = "wpa2.asp";
	else if(fname.options[4].selected == true)
		html_href = "wpas.asp";

	location.href = html_href;
}

function printableKeyFilter()
{
	if (event.keyCode < 32 || event.keyCode > 126)
		event.returnValue = false;
}

function checkpsk(passphrase, passphrase_len)
{
	var len = passphrase.value.length;
	if ( len == 64 )
	{
		//Don't enable Hex passphrase support
		alert("<%getstr("passphrase_long63");%>");
		return false;

		for(i=0;i<len;i++)
		{
			if(isValidHex(passphrase.value.charAt(i))==false)
			{
				alert("<%getstr("a_notallowpassp");%>");
				return false;
			}
		}
	}
	else
	{
		if(len < 8 )
		{
			alert("<%getstr("passphrase_short8");%>");
			return false;
		}
		if(len > 63)
		{
			alert("<%getstr("passphrase_long63");%>");
			return false;
		}
		for(i=0;i<passphrase.value.length;i++)
		{
			if(isValidChar_space(passphrase.value.charCodeAt(i))==false)
			{
				alert("<%getstr("a_notallowpassp");%>");
				return false;
			}
		}
	}
	passphrase_len.value=len;
	return true;
}

var wep_128="<%getstr("m_key128");%>";
var wep_64="<%getstr("m_key64");%>";

function checkwep(form)
{
	form.wep_press_flag.value=0;
	var KEY1=form.KEY1.value;
	var KEY2=form.KEY2.value;
	var KEY3=form.KEY3.value;
	var KEY4=form.KEY4.value;
	if(form.wepenc.value==13)
	{
		if( form.wep_key_no[0].checked == true )
		{
			if(form.KEY1.value.length!=26) 
			{
				alert(wep_128);
				return false;
			}
		}
		else if( form.KEY1.value.length!=0 && form.KEY1.value.length!=26) 
		{
			alert(wep_128);
			return false;
		}
		if(form.KEY1.value.length!=0)
			for(i=0;i<KEY1.length;i++)
			{
				if(isValidHex(KEY1.charAt(i))==false)
				{
					alert(wep_128);
					return false;
				}
			}

		if( form.wep_key_no[1].checked == true )
		{
			if(form.KEY2.value.length!=26)
			{
				alert(wep_128);
				return false;
			}
		}
		else if( form.KEY2.value.length!=0 && form.KEY2.value.length!=26)
		{
			alert(wep_128);
			return false;
		}
		if(form.KEY2.value.length!=0)
			for(i=0;i<KEY2.length;i++)
			{
				if(isValidHex(KEY2.charAt(i))==false)
				{
					alert(wep_128);
					return false;
				}
			}
		if( form.wep_key_no[2].checked == true)
		{
			if(form.KEY3.value.length!=26)
			{
				alert(wep_128);
				return false;
			}
		}
		else if( form.KEY3.value.length!=0 && form.KEY3.value.length!=26)
		{
			alert(wep_128);
			return false;
		}
		if(form.KEY3.value.length!=0)
			for(i=0;i<KEY3.length;i++)
			{
				if(isValidHex(KEY3.charAt(i))==false)
				{
					alert(wep_128);
					return false;
				}
			}
		if( form.wep_key_no[3].checked == true)
		{
			if(form.KEY4.value.length!=26)
			{
				alert(wep_128);
				return false;
			}
		}
		else if( form.KEY4.value.length!=0 && form.KEY4.value.length!=26)
		{
			alert(wep_128);
			return false;
		}
		if(form.KEY4.value.length!=0)
			for(i=0;i<KEY4.length;i++)
			{
				if(isValidHex(KEY4.charAt(i))==false)
				{
					alert(wep_128);
					return false;
				}
			}
	}
	if(form.wepenc.value==5)
	{
		if( form.wep_key_no[0].checked == true)
		{
			if(form.KEY1.value.length!=10) 
			{
				alert(wep_64);
				return false;
			}
		}
		else if( form.KEY1.value.length!=0 && form.KEY1.value.length!=10)
		{
			alert(wep_64);
			return false;
		}
		if(form.KEY1.value.length!=0)
			for(i=0;i<KEY1.length;i++)
			{
				if(isValidHex(KEY1.charAt(i))==false)
				{
					alert(wep_64);
					return false;
				}
			}
		if( form.wep_key_no[1].checked == true)
		{
			if(form.KEY2.value.length!=10)
			{
				alert(wep_64);
				return false;
			}
		}
		else if( form.KEY2.value.length!=0 && form.KEY2.value.length!=10)
		{
			alert(wep_64);
			return false;
		}
		if(form.KEY2.value.length!=0)
			for(i=0;i<KEY2.length;i++)
			{
				if(isValidHex(KEY2.charAt(i))==false)
				{
					alert(wep_64);
					return false;
				}
			}

		if( form.wep_key_no[2].checked == true)
		{
			if(form.KEY3.value.length!=10)
			{
				alert(wep_64);
				return false;
			}
		}
		else if( form.KEY3.value.length!=0 && form.KEY3.value.length!=10)
		{
			alert(wep_64);
			return false;
		}
		if(form.KEY3.value.length!=0)
			for(i=0;i<KEY3.length;i++)
			{
				if(isValidHex(KEY3.charAt(i))==false)
				{
					alert(wep_64);
					return false;
				}
			}
		if( form.wep_key_no[3].checked == true)
		{
			if(form.KEY4.value.length!=10)
			{
				alert(wep_64);
				return false;
			}
		}
		else if( form.KEY4.value.length!=0 && form.KEY4.value.length!=10)
		{
			alert(wep_64);
			return false;
		}
		if(form.KEY4.value.length!=0)
			for(i=0;i<KEY4.length;i++)
			{
				if(isValidHex(KEY4.charAt(i))==false)
				{
					alert(wep_64);
					return false;
				}
			}
	}
	return true;
}

function checkwep_a(form)
{
	form.wep_press_flag.value=0;
	var KEY1=form.KEY1_a.value;
	var KEY2=form.KEY2_a.value;
	var KEY3=form.KEY3_a.value;
	var KEY4=form.KEY4_a.value;
	if(form.wepenc_a.value==13)
	{
		if( form.wep_key_no_a[0].checked == true )
		{
			if(KEY1.length!=26)
			{
				alert(wep_128);
				return false;
			}
		}
		else if( KEY1.length!=0 && KEY1.length!=26)
		{
			alert(wep_128);
			return false;
		}
		if(KEY1.length!=0)
			for(i=0;i<KEY1.length;i++)
			{
				if(isValidHex(KEY1.charAt(i))==false)
				{
					alert(wep_128);
					return false;
				}
			}

		if( form.wep_key_no_a[1].checked == true )
		{
			if(KEY2.length!=26)
			{
				alert(wep_128);
				return false;
			}
		}
		else if( KEY2.length!=0 && KEY2.length!=26)
		{
			alert(wep_128);
			return false;
		}
		if(KEY2.length!=0)
			for(i=0;i<KEY2.length;i++)
			{
				if(isValidHex(KEY2.charAt(i))==false)
				{
					alert(wep_128);
					return false;
				}
			}
		if( form.wep_key_no_a[2].checked == true)
		{
			if(KEY3.length!=26) 
			{
				alert(wep_128);
				return false;
			}
		}
		else if( KEY3.length!=0 && KEY3.length!=26)
		{
			alert(wep_128);
			return false;
		}
		if(KEY3.length!=0)
			for(i=0;i<KEY3.length;i++)
			{
				if(isValidHex(KEY3.charAt(i))==false)
				{
					alert(wep_128);
					return false;
				}
			}
		if( form.wep_key_no_a[3].checked == true)
		{
			if(KEY4.length!=26)
			{
				alert(wep_128);
				return false;
			}
		}
		else if( KEY4.length!=0 && KEY4.length!=26)
		{
			alert(wep_128);
			return false;
		}
		if(KEY4.length!=0)
			for(i=0;i<KEY4.length;i++)
			{
				if(isValidHex(KEY4.charAt(i))==false)
				{
					alert(wep_128);
					return false;
				}
			}
	}
	if(form.wepenc_a.value==5)
	{
		if( form.wep_key_no_a[0].checked == true)
		{
			if(KEY1.length!=10)
			{
				alert(wep_64);
				return false;
			}
		}
		else if( KEY1.length!=0 && KEY1.length!=10)
		{
			alert(wep_64);
			return false;
		}
		if(KEY1.length!=0)
			for(i=0;i<KEY1.length;i++)
			{
				if(isValidHex(KEY1.charAt(i))==false)
				{
					alert(wep_64);
					return false;
				}
			}
		if( form.wep_key_no_a[1].checked == true)
		{
			if(KEY2.length!=10)
			{
				alert(wep_64);
				return false;
			}
		}
		else if( KEY2.length!=0 && KEY2.length!=10)
		{
			alert(wep_64);
			return false;
		}
		if(KEY2.length!=0)
			for(i=0;i<KEY2.length;i++)
			{
				if(isValidHex(KEY2.charAt(i))==false)
				{
					alert(wep_64);
					return false;
				}
			}

		if( form.wep_key_no_a[2].checked == true)
		{
			if(KEY3.length!=10)
			{
				alert(wep_64);
				return false;
			}
		}
		else if( KEY3.length!=0 && KEY3.length!=10)
		{
			alert(wep_64);
			return false;
		}
		if(KEY3.length!=0)
			for(i=0;i<KEY3.length;i++)
			{
				if(isValidHex(KEY3.charAt(i))==false)
				{
					alert(wep_64);
					return false;
				}
			}
		if( form.wep_key_no_a[3].checked == true)
		{
			if(KEY4.length!=10)
			{
				alert(wep_64);
				return false;
			}
		}
		else if( KEY4.length!=0 && KEY4.length!=10)
		{
			alert(wep_64);
			return false;
		}
		if(KEY4.length!=0)
			for(i=0;i<KEY4.length;i++)
			{
				if(isValidHex(KEY4.charAt(i))==false)
				{
					alert(wep_64);
					return false;
				}
			}
	}
	return true;
}

/////////////////////////////////////generate wep key by md5////////////////////////////////////////////////////
function HexToAscii(wepenc,wep_key_no,I,S,D) {
	var temp1="";

	S = S.toUpperCase();

	var optionindex=wepenc.selectedIndex;

	if( wepenc.options[optionindex].value=="13" )
	{
		wordCount = 26;
	}
	else
	{
		wordCount = 10;
	}

	//if(F.keyno_11g[I].checked)
	if(1)
	{
		if( (S.length!=wordCount) )
		{
			if(wep_key_no[I].checked)
			{
				var s="Hex type key length must be ";
				alert(s + wordCount);
			}
			D.value="";
			S="";
			return S;
		}
		for(i=0;i<wordCount;i+=2)
		{
			var c=S.charCodeAt(i);
			var d=S.charCodeAt(i+1);

			if( (c>=48)&&(c<=57) )
				c=c-48;
			else if( (c>=65)&&(c<=70) )
				c=c-55;
			else
			{
				var s="Over Hex range (0~F)";
				alert(s);
				return S;
			}

			if( (d>=48)&&(d<=57) )
				d=d-48;
			else if( (d>=65)&&(d<=70) )
				d=d-55;
			else
			{
				var s="Over Hex range (0~F)";
				alert(s);
				return S;
			}
			var value=c*16+d;

			if( ((value>=0)&&(value<32)) || ((value>128)&&(value<=255)) )
			{
				temp1+=String.fromCharCode(92);
				temp1+=S.substring(i,i+2);
			}
			else
			{
				if(value==92)
				{
					temp1+=String.fromCharCode(value);
					temp1+=String.fromCharCode(value);
				}
				else
					temp1+=String.fromCharCode(value);
			}
		}
		D.value=temp1;
	}
	return S;
}

function PassPhrase40(passphraseStr, wepenc, wep_key_no, KEY1, KEY2, KEY3, KEY4)
{
	var seed = 0;
	var pseed = new Array(0, 0, 0, 0);
	var pkey = new Array(4);
	var asciiObj = new Array(4);
	Length = passphraseStr.value.length;

	if(Length != 0)
	{
		for (i=0; i<Length; i++ )
		{
			pseed[i%4] ^= passphraseStr.value.charCodeAt(i);
		}
		seed = pseed[0];
		seed += pseed[1] << 8;
		seed += pseed[2] << 16;
		seed += pseed[3] << 24;
	}

	KEY1.value = KEY2.value = "";
	KEY3.value = KEY4.value = "";

	// init key array
	pkey[0] = KEY1;
	pkey[1] = KEY2;
	pkey[2] = KEY3;
	pkey[3] = KEY4;

	for(j=0; j<4; j++)
	{
		for (i=0; i<5 ;i++ )
		{
			seed = (214013 * seed) & 0xffffffff;

			if(seed & 0x80000000)
			{
				seed = (seed & 0x7fffffff) + 0x80000000 + 0x269ec3;
			}
			else
			{
				seed = (seed & 0x7fffffff) + 0x269ec3;
			}

			temp = ((seed >> 16) & 0xff);
			if(temp < 0x10)
			{
				pkey[j].value += "0" + temp.toString(16).toUpperCase();
			}
			else
			{
				pkey[j].value += temp.toString(16).toUpperCase();
			}
		}
	}

	asciiObj[0] = "";
	asciiObj[1] = "";
	asciiObj[2] = "";
	asciiObj[3] = "";

	for(k=0; k<4; k++)
	{
		HexToAscii(wepenc, wep_key_no, k, pkey[k].value, asciiObj[k]);
	}

	wepkey1 = pkey[0].value;
	wepkey2 = pkey[1].value;
	wepkey3 = pkey[2].value;
	wepkey4 = pkey[3].value;
}

/*
 * A JavaScript implementation of the RSA Data Security, Inc. MD5 Message
 * Digest Algorithm, as defined in RFC 1321.
 * Copyright (C) Paul Johnston 1999 - 2000.
 * Updated by Greg Holt 2000 - 2001.
 * See http://pajhome.org.uk/site/legal.html for details.
 */

/*
 * Convert a 32-bit number to a hex string with ls-byte first
 */
var hex_chr = "0123456789abcdef";
function rhex(num)
{
	str = "";
	for(j = 0; j <= 3; j++)
		str += hex_chr.charAt((num >> (j * 8 + 4)) & 0x0F) +
			hex_chr.charAt((num >> (j * 8)) & 0x0F);
	return str;
}

/*
 * Convert a string to a sequence of 16-word blocks, stored as an array.
 * Append padding bits and the length, as described in the MD5 standard.
 */
function str2blks_MD5(str)
{
	nblk = ((str.length + 8) >> 6) + 1;
	blks = new Array(nblk * 16);
	for(i = 0; i < nblk * 16; i++) blks[i] = 0;
	for(i = 0; i < str.length; i++)
		blks[i >> 2] |= str.charCodeAt(i) << ((i % 4) * 8);
	blks[i >> 2] |= 0x80 << ((i % 4) * 8);
	blks[nblk * 16 - 2] = str.length * 8;
	return blks;
}

/*
 * Add integers, wrapping at 2^32. This uses 16-bit operations internally 
 * to work around bugs in some JS interpreters.
 */
function add(x, y)
{
	var lsw = (x & 0xFFFF) + (y & 0xFFFF);
	var msw = (x >> 16) + (y >> 16) + (lsw >> 16);
	return (msw << 16) | (lsw & 0xFFFF);
}

/*
 * Bitwise rotate a 32-bit number to the left
 */
function rol(num, cnt)
{
	return (num << cnt) | (num >>> (32 - cnt));
}

/*
 * These functions implement the basic operation for each round of the
 * algorithm.
 */
function cmn(q, a, b, x, s, t)
{
	return add(rol(add(add(a, q), add(x, t)), s), b);
}
function ff(a, b, c, d, x, s, t)
{
	return cmn((b & c) | ((~b) & d), a, b, x, s, t);
}
function gg(a, b, c, d, x, s, t)
{
	return cmn((b & d) | (c & (~d)), a, b, x, s, t);
}
function hh(a, b, c, d, x, s, t)
{
	return cmn(b ^ c ^ d, a, b, x, s, t);
}
function ii(a, b, c, d, x, s, t)
{
	return cmn(c ^ (b | (~d)), a, b, x, s, t);
}

/*
 * Take a string and return the hex representation of its MD5.
 */
function calcMD5(str)
{
	x = str2blks_MD5(str);
	a =  1732584193;
	b = -271733879;
	c = -1732584194;
	d =  271733878;

	for(i = 0; i < x.length; i += 16)
	{
		olda = a;
		oldb = b;
		oldc = c;
		oldd = d;

		a = ff(a, b, c, d, x[i+ 0], 7 , -680876936);
		d = ff(d, a, b, c, x[i+ 1], 12, -389564586);
		c = ff(c, d, a, b, x[i+ 2], 17,  606105819);
		b = ff(b, c, d, a, x[i+ 3], 22, -1044525330);
		a = ff(a, b, c, d, x[i+ 4], 7 , -176418897);
		d = ff(d, a, b, c, x[i+ 5], 12,  1200080426);
		c = ff(c, d, a, b, x[i+ 6], 17, -1473231341);
		b = ff(b, c, d, a, x[i+ 7], 22, -45705983);
		a = ff(a, b, c, d, x[i+ 8], 7 ,  1770035416);
		d = ff(d, a, b, c, x[i+ 9], 12, -1958414417);
		c = ff(c, d, a, b, x[i+10], 17, -42063);
		b = ff(b, c, d, a, x[i+11], 22, -1990404162);
		a = ff(a, b, c, d, x[i+12], 7 ,  1804603682);
		d = ff(d, a, b, c, x[i+13], 12, -40341101);
		c = ff(c, d, a, b, x[i+14], 17, -1502002290);
		b = ff(b, c, d, a, x[i+15], 22,  1236535329);    

		a = gg(a, b, c, d, x[i+ 1], 5 , -165796510);
		d = gg(d, a, b, c, x[i+ 6], 9 , -1069501632);
		c = gg(c, d, a, b, x[i+11], 14,  643717713);
		b = gg(b, c, d, a, x[i+ 0], 20, -373897302);
		a = gg(a, b, c, d, x[i+ 5], 5 , -701558691);
		d = gg(d, a, b, c, x[i+10], 9 ,  38016083);
		c = gg(c, d, a, b, x[i+15], 14, -660478335);
		b = gg(b, c, d, a, x[i+ 4], 20, -405537848);
		a = gg(a, b, c, d, x[i+ 9], 5 ,  568446438);
		d = gg(d, a, b, c, x[i+14], 9 , -1019803690);
		c = gg(c, d, a, b, x[i+ 3], 14, -187363961);
		b = gg(b, c, d, a, x[i+ 8], 20,  1163531501);
		a = gg(a, b, c, d, x[i+13], 5 , -1444681467);
		d = gg(d, a, b, c, x[i+ 2], 9 , -51403784);
		c = gg(c, d, a, b, x[i+ 7], 14,  1735328473);
		b = gg(b, c, d, a, x[i+12], 20, -1926607734);

		a = hh(a, b, c, d, x[i+ 5], 4 , -378558);
		d = hh(d, a, b, c, x[i+ 8], 11, -2022574463);
		c = hh(c, d, a, b, x[i+11], 16,  1839030562);
		b = hh(b, c, d, a, x[i+14], 23, -35309556);
		a = hh(a, b, c, d, x[i+ 1], 4 , -1530992060);
		d = hh(d, a, b, c, x[i+ 4], 11,  1272893353);
		c = hh(c, d, a, b, x[i+ 7], 16, -155497632);
		b = hh(b, c, d, a, x[i+10], 23, -1094730640);
		a = hh(a, b, c, d, x[i+13], 4 ,  681279174);
		d = hh(d, a, b, c, x[i+ 0], 11, -358537222);
		c = hh(c, d, a, b, x[i+ 3], 16, -722521979);
		b = hh(b, c, d, a, x[i+ 6], 23,  76029189);
		a = hh(a, b, c, d, x[i+ 9], 4 , -640364487);
		d = hh(d, a, b, c, x[i+12], 11, -421815835);
		c = hh(c, d, a, b, x[i+15], 16,  530742520);
		b = hh(b, c, d, a, x[i+ 2], 23, -995338651);

		a = ii(a, b, c, d, x[i+ 0], 6 , -198630844);
		d = ii(d, a, b, c, x[i+ 7], 10,  1126891415);
		c = ii(c, d, a, b, x[i+14], 15, -1416354905);
		b = ii(b, c, d, a, x[i+ 5], 21, -57434055);
		a = ii(a, b, c, d, x[i+12], 6 ,  1700485571);
		d = ii(d, a, b, c, x[i+ 3], 10, -1894986606);
		c = ii(c, d, a, b, x[i+10], 15, -1051523);
		b = ii(b, c, d, a, x[i+ 1], 21, -2054922799);
		a = ii(a, b, c, d, x[i+ 8], 6 ,  1873313359);
		d = ii(d, a, b, c, x[i+15], 10, -30611744);
		c = ii(c, d, a, b, x[i+ 6], 15, -1560198380);
		b = ii(b, c, d, a, x[i+13], 21,  1309151649);
		a = ii(a, b, c, d, x[i+ 4], 6 , -145523070);
		d = ii(d, a, b, c, x[i+11], 10, -1120210379);
		c = ii(c, d, a, b, x[i+ 2], 15,  718787259);
		b = ii(b, c, d, a, x[i+ 9], 21, -343485551);

		a = add(a, olda);
		b = add(b, oldb);
		c = add(c, oldc);
		d = add(d, oldd);
	}
	return rhex(a) + rhex(b) + rhex(c) + rhex(d);
}

function PassPhrase104(passphraseStr, KEY1, KEY2, KEY3, KEY4) 
{

	var pseed2 = "";
	Length2 = passphraseStr.value.length;

	for(p=0; p<64; p++)
	{
		tempCount = p % Length2;
		pseed2 += passphraseStr.value.substring(tempCount, tempCount+1);
	}
	md5Str = calcMD5(pseed2);

	KEY1.value = md5Str.substring(0, 26).toUpperCase();
	KEY2.value = md5Str.substring(0, 26).toUpperCase();
	KEY3.value = md5Str.substring(0, 26).toUpperCase();
	KEY4.value = md5Str.substring(0, 26).toUpperCase();
}

function clickgenerate(form)
{
	if(form.passphraseStr.value.length == 0 )
	{
		alert("Empty!")
		return false;
	}
	for(i=0;i<form.passphraseStr.value.length;i++)
	{
		if(isValidChar_space(form.passphraseStr.value.charCodeAt(i))==false)
		{
			alert("<%getstr("a_notallowpassp");%>");
			return false;
		}
	}
	if(form.wepenc.options[0].selected == true)
		PassPhrase40(form.passphraseStr, form.wepenc, form.wep_key_no, form.KEY1, form.KEY2, form.KEY3, form.KEY4);
	else
		PassPhrase104(form.passphraseStr, form.KEY1, form.KEY2, form.KEY3, form.KEY4);
	form.generate_flag.value=1;
}
function clickgenerate_a(form)
{
	/*
	if(form.passphraseStr_a.value.length == 0 )
	{
		alert("You should input 1 to 32 ASCII characters to generate 4 keys.")
		return false;
	}
	*/
	for(i=0;i<form.passphraseStr_a.value.length;i++)
	{
		if(isValidChar_space(form.passphraseStr_a.value.charCodeAt(i))==false)
		{
			alert("<%getstr("a_notallowpassp");%>");
			return false;
		}
	}
	if(form.wepenc_a.options[0].selected == true)
		PassPhrase40(form.passphraseStr_a, form.wepenc_a, form.wep_key_no_a, form.KEY1_a, form.KEY2_a, form.KEY3_a, form.KEY4_a);
	else
		PassPhrase104(form.passphraseStr_a, form.KEY1_a, form.KEY2_a, form.KEY3_a, form.KEY4_a);
	form.generate_flag.value=1;
}

function doPortChange(check)
{
	if(check == 0)
		location.href="forwarding.htm";
	else
		location.href="triggering.htm";
}

function setDisabled(OnOffFlag,formFields)
{
	for (var i = 1; i < setDisabled.arguments.length; i++)
		setDisabled.arguments[i].disabled = OnOffFlag;
}

function change_serv(cf)
{
	if ( cf.login_type[1].selected == true )
	{
		location.href="BAS_pppoe.htm";
		loadhelp('_BAS_pppoe');
	}
	else if ( cf.login_type[0].selected == true )
	{
		location.href="BAS_pptp.htm";
		loadhelp('_BAS_pptp');
	}
	else if (cf.login_type[2].selected == true )
	{
		location.href="BAS_l2tp.htm";
		loadhelp('_BAS_l2tp');
	}
	else if (cf.login_type[3].selected == true )
		location.href="BAS_mulpppoe.htm";
}

function maccheck_multicast(mac_addr)
{
	mac_array=mac_addr.split(':');
	var mac11 = mac_array[0];
	mac11 = mac11.substr(1,1);
	if((mac11=="1")||(mac11=="3")||(mac11=="5")||(mac11=="7")||(mac11=="9")||(mac11=="b")||(mac11=="d")||(mac11=="f")||(mac11=="B")||(mac11=="D")||(mac11=="F"))
	{
		//Reject MAC address like 11:xx:xx:xx:xx:xx
		alert("<%getstr("invalid_mac");%>");
		return false;
	}
	if(mac_array.length!=6)
	{
		alert("<%getstr("invalid_mac");%>");
		return false;
	}
	if(( mac_array[0]=="")||( mac_array[1]=="")||( mac_array[2]=="")||( mac_array[3]=="")||( mac_array[4]=="")||( mac_array[5]==""))
	{
		alert("<%getstr("invalid_mac");%>");
		return false;
	}
	if((( mac_array[0]=="00")&&( mac_array[1]=="00")&&
		( mac_array[2]=="00")&&( mac_array[3]=="00")&&
		( mac_array[4]=="00")&&( mac_array[5]=="00"))||
		(( mac_array[0]=="ff")&&( mac_array[1]=="ff")&&
		 ( mac_array[2]=="ff")&&( mac_array[3]=="ff")&&
		 ( mac_array[4]=="ff")&&( mac_array[5]=="ff"))||
		(( mac_array[0]=="FF")&&( mac_array[1]=="FF")&&
		 ( mac_array[2]=="FF")&&( mac_array[3]=="FF")&&
		 ( mac_array[4]=="FF")&&( mac_array[5]=="FF")))
	{
		alert("<%getstr("invalid_mac");%>");
		return false;
	}
	if(( mac_array[0].length!=2)||( mac_array[1].length!=2)||
		( mac_array[2].length!=2)||( mac_array[3].length!=2)||
		( mac_array[4].length!=2)||( mac_array[5].length!=2))
	{
		alert("<%getstr("invalid_mac");%>");
		return false;
	}
	for(i=0;i<mac_addr.length;i++)
	{
		if(isValidMac(mac_addr.charAt(i))==false)
		{
			alert("<%getstr("invalid_mac");%>");
			return false;
		}
	}
	return true;
}

function maccheck(mac_addr)
{
	/*
	if ( mac_addr.indexOf(":")==-1 && mac_addr.length=="12" )
	{
		var tmp_mac=mac_addr.substr(0,2)+":"+mac_addr.substr(2,2)+":"+mac_addr.substr(4,2)+":"+mac_addr.substr(6,2)+":"+mac_addr.substr(8,2)+":"+mac_addr.substr(10,2);
		mac_addr = tmp_mac;
	}
	*/
	mac_array=mac_addr.split(':');
	var mac11 = mac_array[0];
	mac11 = mac11.substr(1,1);
	if((mac11=="1")||(mac11=="3")||(mac11=="5")||(mac11=="7")||(mac11=="9")||(mac11=="b")||(mac11=="d")||(mac11=="f")||(mac11=="B")||(mac11=="D")||(mac11=="F"))
	{
		if(mac11=="1" && mac_array[0] == "11")
		{
		}
		else
		{
			alert("<%getstr("invalid_mac");%>");
			return false;
		}
	}
	if(mac_array.length!=6)
	{
		alert("<%getstr("invalid_mac");%>");
		return false;
	}
	if(( mac_array[0]=="")||( mac_array[1]=="")||( mac_array[2]=="")||( mac_array[3]=="")||( mac_array[4]=="")||( mac_array[5]==""))
	{
		alert("<%getstr("invalid_mac");%>");
		return false;
	}
	if((( mac_array[0]=="00")&&( mac_array[1]=="00")&&
		( mac_array[2]=="00")&&( mac_array[3]=="00")&&
		( mac_array[4]=="00")&&( mac_array[5]=="00"))||
		(( mac_array[0]=="ff")&&( mac_array[1]=="ff")&&
		 ( mac_array[2]=="ff")&&( mac_array[3]=="ff")&&
		 ( mac_array[4]=="ff")&&( mac_array[5]=="ff"))||
		(( mac_array[0]=="FF")&&( mac_array[1]=="FF")&&
		 ( mac_array[2]=="FF")&&( mac_array[3]=="FF")&&
		 ( mac_array[4]=="FF")&&( mac_array[5]=="FF")))
	{
		alert("<%getstr("invalid_mac");%>");
		return false;
	}
	if(( mac_array[0].length!=2)||( mac_array[1].length!=2)||
		( mac_array[2].length!=2)||( mac_array[3].length!=2)||
		( mac_array[4].length!=2)||( mac_array[5].length!=2))
	{
		alert("<%getstr("invalid_mac");%>");
		return false;
	}

	for(i=0;i<mac_addr.length;i++)
	{
		if(isValidMac(mac_addr.charAt(i))==false)
		{
			alert("<%getstr("invalid_mac");%>");
			return false;
		}
	}
	return true;
}

function setMAC(cf,this_mac)
{
	var dflag;
	if (cf.MACAssign[0].checked || cf.MACAssign[1].checked)
	{
		dflag = true;
		cf.Spoofmac.value=this_mac;
		setDisabled(dflag,cf.Spoofmac);
	}
	else
	{
		dflag = false;
		setDisabled(dflag,cf.Spoofmac);
		cf.Spoofmac.value=this_mac;
	}
}

function maccheck_wds(mac_addr,num,form)
{
	var return_num=0;
	//if(mac_addr==":::::")
	if(mac_addr=="")
		return 2;
	var mac_array=mac_addr.split(':');
	var mac11 = mac_array[0];
	mac11 = mac11.substr(1,1);
	if((mac11=="1")||(mac11=="3")||(mac11=="5")||(mac11=="7")||
		(mac11=="9")||(mac11=="b")||(mac11=="d")||(mac11=="f")||
		(mac11=="B")||(mac11=="D")||(mac11=="F"))
	{
		if( mac11 == "1" && mac_array[0]=="11")
		{
		}
		else
			return 1;
	}
	if(mac_addr.length!=17 && mac_addr.length!=0)
		return 1;
	if((mac_array[0]=="")||(mac_array[1]=="")||(mac_array[2]=="")||(mac_array[3]=="")|| (mac_array[4]=="")||(mac_array[5]==""))
	{
		if((mac_array[0]=="")&&(mac_array[1]=="")&&(mac_array[2]=="")&&(mac_array[3]=="")&& (mac_array[4]=="")&&(mac_array[5]==""))
			return 2;
		else
			return 1;
	}
	if(((mac_array[0]=="00")&&(mac_array[1]=="00")&&
		(mac_array[2]=="00")&&(mac_array[3]=="00")&&
		(mac_array[4]=="00")&&(mac_array[5]=="00"))||
		((mac_array[0]=="ff")&&(mac_array[1]=="ff")&&
		 (mac_array[2]=="ff")&&(mac_array[3]=="ff")&&
		 (mac_array[4]=="ff")&&(mac_array[5]=="ff"))||
		((mac_array[0]=="FF")&&(mac_array[1]=="FF")&&
		 (mac_array[2]=="FF")&&(mac_array[3]=="FF")&&
		 (mac_array[4]=="FF")&&(mac_array[5]=="FF")))
		return 1;
	if((mac_array[0].length!=2)||(mac_array[1].length!=2)||
		(mac_array[2].length!=2)||(mac_array[3].length!=2)||
		(mac_array[4].length!=2)||(mac_array[5].length!=2))
		return 1;
	for(i=0;i<mac_addr.length;i++)
		if(isValidMac(mac_addr.charAt(i))==false)
			return 1;
	if( num != "" && num != 0 && num != 1 )
	{
		for( k=1;k<num;k++)
		{
			mac_str=eval('the_mac'+k);
			if( mac_str != "" && mac_str.toLowerCase() == mac_addr.toLowerCase())
			{
				return 3;
			}
		}
	}
	return return_num;
}

function change_sec_to_time(uptime)
{
	var sec=uptime;
	var sec=parseInt(sec);
	var hour_sec=sec%3600;
	if(hour_sec!=sec)
		new_hour=(sec-hour_sec)/3600;
	else
		new_hour=0;
	var min_sec=hour_sec%60;
	if(min_sec!=hour_sec)
		new_min=(hour_sec-min_sec)/60;
	else
		new_min=0;
	var new_sec=min_sec;
	new_hour=new_hour.toString();
	new_min=new_min.toString();
	new_sec=new_sec.toString();
	if(new_hour.length==1)
		new_hour='0'+new_hour;
	if(new_min.length==1)
		new_min='0'+new_min;
	if(new_sec.length==1)
		new_sec='0'+new_sec;
	var new_time=new_hour+':'+new_min+':'+new_sec;
	return new_time;
}

function goTestApply()
{
	var winoptions = "width=640,height=480,menubar=yes,scrollbars=yes,toolbar=yes,status=yes,location=yes,resizable=yes"
	if( run_test == "test")
		window.open('http://www.netgear.com/success/<% get_test_link(); %>',null,winoptions);
		//window.open('BAS_testpage.htm',null,winoptions);
}

function xssprotect(str,flag)
{
	var xss_str;
	if(flag==1)
		xss_str = str.replace(/\&/g, "&amp;").replace(/\#/g, "&#35;").replace(/\</g, "&lt;").replace(/\>/g, "&gt;").replace(/\(/g, "&#40;").replace(/\)/g, "&#41;").replace(/\"/g, "&#34;").replace(/\'/g, "&#39;");
	else
		xss_str = str.replace(/\&/g, "&amp;").replace(/\#/g, "&#35;").replace(/ /g,"&nbsp;").replace(/\</g, "&lt;").replace(/\>/g, "&gt;").replace(/\(/g, "&#40;").replace(/\)/g, "&#41;").replace(/\"/g, "&#34;").replace(/\'/g, "&#39;");
	return xss_str;
}

function isValidMac(digit)
{
	var macVals = new Array("0", "1", "2", "3", "4", "5", "6", "7", "8", "9","A", "B", "C", "D", "E", "F", "a", "b", "c", "d", "e", "f",":");
	var len = macVals.length;
	var i = 0;
	var ret = false;
	for ( i = 0; i < len; i++ )
		if ( digit == macVals[i] )
			break;
	if ( i < len )
		ret = true;
	return ret;
}

function isValidHex(each_char)
{
	var macVals = new Array("0", "1", "2", "3", "4", "5", "6", "7", "8", "9","A", "B", "C", "D", "E", "F", "a", "b", "c", "d", "e", "f");
	var len = macVals.length;
	var i = 0;
	var ret = false;
	for ( i = 0; i < len; i++ )
		if ( each_char == macVals[i] )
			break;
	if ( i < len )
		ret = true;
	return ret;
}

function isValidChar_space(each_char)
{
	if( each_char < 32 || each_char > 127)
		return false;
}

function isValidChar(each_char)
{
	if( each_char < 33 || each_char > 126)
		return false;
}

function isValidChar_all(each_char)
{
	if( each_char < 32 || each_char > 126)
		return false;
}

function isValidCharFolderName(each_char)
{
	if( each_char < 32 || each_char > 126)
		return false;
	else if( each_char == 34 || each_char == 42 || each_char == 47 || each_char == 58 || each_char == 60  || each_char == 62 || each_char == 63 || each_char == 92 || each_char == 124)
		return false;
}

function isValidDdnsHost(each_char)
{
	if (!(((each_char>47) && (each_char<58))||(each_char==45)||(each_char==46)||((each_char>64) && (each_char<91))||((each_char>96) && (each_char<123)) || (each_char==8)||(each_char==0))) 
		return false;
}
function printPage()
{
	if (window.print)
		window.print();
	else
		alert("<%getstr("fun_alert");%>");
}
function top_left_nolink()
{
	parent.topframe.document.forms[0].lang_avi.disabled = true;
	parent.topframe.document.forms[0].apply.disabled = true;
}

function wlan_txctrl(form, tx_power_ctrl, tx_power_ctrl_a, wla_channel, country)
{
	if((netgear_region == "WW" || netgear_region == "") && (country != "3" && country != "10"))
	{
		if(tx_power_ctrl == "0")
			form.wl_tx_ctrl.value="0";
		else if(tx_power_ctrl == "1")
			form.wl_tx_ctrl.value="1";
		else if(tx_power_ctrl == "2")
			form.wl_tx_ctrl.value="2";
		else if(tx_power_ctrl == "3")
			form.wl_tx_ctrl.value="3";

		//for 5G
		if(tx_power_ctrl_a == "0")
			form.wla_tx_ctrl.value="44";
		if(parseInt(wla_channel) >= 36 && parseInt(wla_channel) <= 64)
		{
			if(tx_power_ctrl_a == "1")
				form.wla_tx_ctrl.value="12.5";
			else if(tx_power_ctrl_a == "2")
				form.wla_tx_ctrl.value="8.5";
			else if(tx_power_ctrl_a == "3")
				form.wla_tx_ctrl.value="4";
		}
		else if(parseInt(wla_channel) >= 100)
		{
			if(tx_power_ctrl_a == "1")
				form.wla_tx_ctrl.value="15.5";
			else if(tx_power_ctrl_a == "2")
				form.wla_tx_ctrl.value="10.5";
			else if(tx_power_ctrl_a == "3")
				form.wla_tx_ctrl.value="5";
		}
	}
	else
	{
		if(tx_power_ctrl == "0")
			form.wl_tx_ctrl.value="0";
		else if(tx_power_ctrl == "1")
			form.wl_tx_ctrl.value="1";
		else if(tx_power_ctrl == "2")
			form.wl_tx_ctrl.value="2";
		else if(tx_power_ctrl == "3")
			form.wl_tx_ctrl.value="3";

		//for 5G
		if(tx_power_ctrl_a == "0")
			form.wla_tx_ctrl.value="44";
		if(parseInt(wla_channel) >= 36 && parseInt(wla_channel) <= 48)
		{
			if(tx_power_ctrl_a == "1")
				form.wla_tx_ctrl.value="10.5";
			else if(tx_power_ctrl_a == "2")
				form.wla_tx_ctrl.value="7";
			else if(tx_power_ctrl_a == "3")
				form.wla_tx_ctrl.value="3.5";
		}
		else if(parseInt(wla_channel) >= 52 && parseInt(wla_channel) <= 165)
		{
			if(tx_power_ctrl_a == "1")
				form.wla_tx_ctrl.value="15.5";
			else if(tx_power_ctrl_a == "2")
				form.wla_tx_ctrl.value="10.5";
			else if(tx_power_ctrl_a == "3")
				form.wla_tx_ctrl.value="5";
		}
	}

	//the current values should be changed to (urrent_value+6)*2.
	//form.wl_tx_ctrl.value = ( parseFloat(form.wl_tx_ctrl.value) + 6 ) * 2;
	//form.wla_tx_ctrl.value = ( parseFloat(form.wla_tx_ctrl.value) + 6 ) * 2;

}

String.prototype.checkFolder=function()
{//test string    
	var s = ["\\","\"","\'","?",":","<",">","|","*"];
	for (var i=0; i<s.length; i++)
	{
		if (this.indexOf(s[i]) != -1)
			return true;
	}

	return false;
}
String.prototype.checkShareName=function()
{//test string
	var s = ["\\","\"","\/","?",":","<",">","|","*","\]"];
	for (var i=0; i<s.length; i++)
	{
		if (this.indexOf(s[i]) != -1)
			return true;
	}

	return false;
}


function pop()
{
	if(navigator.userAgent.indexOf("MSIE") != -1)
		window.open('thank_login.htm','thankspage','width=460,height=420,top=240,left=300,status=yes');
	else
		window.open('thank_login.htm','thankspage','width=380,height=380,screenY=250,screenX=300,status=yes');

}
