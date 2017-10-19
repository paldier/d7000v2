var HelpOptionsVar = "width=480,height=420,scrollbars,toolbar,resizable,dependent=yes";
var GlossOptionsVar = "width=420,height=180,scrollbars,toolbar,resizable,dependent=yes";
var bigsub   = "width=540,height=440,scrollbars,menubar,resizable,status,dependent=yes";
var smallsub = "width=440,height=320,scrollbars,resizable,dependent=yes";
var sersub   = "width=500,height=380,scrollbars,resizable,status,dependent=yes";
var memsub   = "width=630,height=320,scrollbars,menubar,resizable,status,dependent=yes";
var helpWinVar = null;
var glossWinVar = null;
var datSubWinVar = null;
var ValidStr = 'abcdefghijklmnopqrstuvwxyz-';
var ValidStr_ddns = 'abcdefghijklmnopqrstuvwxyz-1234567890';
var hex_str = "ABCDEFabcdef0123456789";

if (document.layers) document.captureEvents(Event.KEYPRESS);
    document.onkeypress = checkKey;
function checkKey(evt)
{
    var lastkeypressed;
    evt = (evt) ? evt : ((window.event) ? window.event : null);
    if (evt)
        lastkeypressed = (evt.keyCode) ? evt.keyCode : (evt.which ) ? evt.which : null;
    else
        lastkeypressed = null;
    
    if ((lastkeypressed == 27)) /* ESC */
    {
        if (document.forms[0].elements[0].focus)
            document.forms[0].elements[0].focus();
        
        return false;
    }

    return true;
}

function showMsg()
{
	var msgVar=document.forms[0].message.value;
	if (msgVar.length > 1) 
		alert(msgVar);
}

function closeWin(win_var)
{
	if ( ((win_var != null) && (win_var.close)) || ((win_var != null) && (win_var.closed==false)) )
		win_var.close();
}

function openHelpWin(file_name)
{
	helpWinVar = window.open(file_name,'help_win',HelpOptionsVar);
	if (helpWinVar && helpWinVar.focus)
		setTimeout('helpWinVar.focus()',200);
}

function openGlossWin()
{
	glossWinVar = window.open('','gloss_win',GlossOptionsVar);
	if (glossWinVar && glossWinVar.focus)
		setTimeout('glossWinVar.focus()',200);
}

function openDataSubWin(filename,win_type)
{
	datSubWinVar = window.open(filename,'datasub_win',win_type);
	if (datSubWinVar && datSubWinVar.focus)
		setTimeout('datSubWinVar.focus()',200); 
}

function closeSubWins()
{
	if (helpWinVar)
		closeWin(helpWinVar);
	if (glossWinVar)
		closeWin(glossWinVar);
	if (datSubWinVar)
		closeWin(datSubWinVar);
}

function checkBlank(fieldObj, fname)
{
	var msg = "";
	if (fieldObj.value.length < 1){
		msg = addstr(msg_blank,fname);
	}
	return msg;
}

function checkNoBlanks(fObj, fname)
{
	var space = " ";
	if (fObj.value.indexOf(space) >= 0 )
			return msg_space;
	else return "";
}

function checkValid(text_input_field, field_name, Valid_Str, max_size, mustFill)
{
	var error_msg= "";
	var size = text_input_field.value.length;
	var str = text_input_field.value;

	if ((mustFill) && (size != max_size) )
		error_msg = addstr(msg_blank_in,field_name);
	for (var i=0; i < size; i++)
	{
	if (!(Valid_Str.indexOf(str.charAt(i)) >= 0))
	{
			error_msg = addstr(msg_invalid,field_name,Valid_Str);
			break;
	}
	}
	return error_msg;
}
function checkInt(text_input_field, field_name, min_value, max_value, required)
{
	var str = text_input_field.value;
	var error_msg= "";
	
	if (text_input_field.value.length==0)
	{
		if (required)
			error_msg = addstr(msg_blank,field_name);
	}
	else
	{
		for (var i=0; i < str.length; i++)
		{
			if ((str.charAt(i) < '0') || (str.charAt(i) > '9'))
				error_msg = addstr(msg_check_invalid,field_name);
		}
		if (error_msg.length < 2)
		{
			var int_value = parseInt(str,10);
			if (int_value < min_value)
			{
				if(current_gui_language == "Japanese")
					error_msg = addstr(msg_greater,field_name, min_value);
				else
				    error_msg = addstr(msg_greater,field_name,(min_value - 1));
			}
			if (int_value > max_value)
				error_msg = addstr(msg_less,field_name,(max_value + 1));
		}
	}
	if (error_msg.length > 1)
		error_msg = error_msg + "\n";
	return(error_msg);
}
function chkMacLen(mac){
	if((mac.value.length != 12) || (mac.value=="000000000000")){
		alert("<%getstr("invalid_mac");%>");
		mac.value = "";
		return false;
	}
	else
	{
	  return true;
	}
}
function sumvalue(F)
{    
	if (F.MACAssign[2].checked)
	{
		if ((F.Spoofmac.value.indexOf(':')!=-1)||(F.Spoofmac.value.indexOf('-')!=-1))
		{
			if (MACAddressBlur(F.Spoofmac))
			{
				return true;
			}
			else
				return false;
		} 
		else    
		{
			if (chkMacLen(F.Spoofmac))
			{
				return true;
			}
			else
				return false;
		}
	}
	return true;
}
function sumvalue1(F)
{    
		if ((F.Spoofmac.value.indexOf(':')!=-1)||(F.Spoofmac.value.indexOf('-')!=-1))
		{
			if (MACAddressBlur(F.Spoofmac))
			{
				return true;
			}
			else
				return false;
		} 
		else    
		{
			if (chkMacLen(F.Spoofmac))
			{
				return true;
			}
			else
				return false;
		}
	return true;
}
function MACAddressBlur(address)
{
	var MAC = address.value;
	MAC = MAC.replace(/:/g,"");
	MAC = MAC.replace(/-/g,"");
	address.value = MAC;
	if ((address.value.length != 12) || (address.value=="000000000000"))
	{
		alert("<%getstr("invalid_mac");%>");
		return false;
	}
	else
	{
		return true;
	}
}
function loadhelp(fname,anchname)
{
	if (top.helpframe)
	{
		if ((loadhelp.arguments.length == 1 ) || (anchname == "" ))
			top.helpframe.location.href=fname+"_h.htm";
		else
			top.helpframe.location.href=fname+"_h.htm#" + anchname;
	}
}

/* jump to next text for IPv6 */
function jumpcheckv6(txtobj,isEnd)
{
	if (txtobj.value.length>3 || txtobj.value.indexOf(":")>=0)
	{
		if (txtobj.value.indexOf(":")>=0)
		{
			txtobj.value= txtobj.value.replace(":","");
		}
		if (isEnd || txtobj.value.length==0)
			return true;
		for (i=0;i<document.forms[0].elements.length;i++)
		{
			if (document.forms[0].elements[i]==txtobj)
			{
				document.forms[0].elements[i+1].select();
				document.forms[0].elements[i+1].focus();
			}
		}
	}
	return true;
}

var need_to_switch;
/* jump to next text for IPv4 */
function jumpcheck(txtobj,isEnd)
{
    //return true;
	if (txtobj.value.length>2 || txtobj.value.indexOf(".")>=0)
	{
		if (txtobj.value.indexOf(".")>=0)
		{
			txtobj.value= txtobj.value.replace(".","");
		}
		if (isEnd || txtobj.value.length==0 ||  need_to_switch==0)
			return true;
		for (i=0;i<document.forms[0].elements.length;i++)
		{
			if (document.forms[0].elements[i]==txtobj)
			{
				document.forms[0].elements[i+1].select();
				document.forms[0].elements[i+1].focus();
			}
		}
	}
	return true;
}

/* check backspace */
function bscheck(e,txtobj,isStart)
{
	var keynum;

	if(window.event)
	{
	keynum = e.keyCode
	}
	else if(e.which) 
	{
	keynum = e.which
	}
	
	if (keynum == 8 && txtobj.value.length==0) 
	{
		if (isStart)
			return true;
		for (i=0;i<document.forms[0].elements.length;i++)
		{
			if (document.forms[0].elements[i]==txtobj && document.forms[0].elements[i-1].disabled!=true)
			{
				document.forms[0].elements[i-1].select();
				document.forms[0].elements[i-1].focus();
			}
		}

	}
    
	if (e.keyCode==9 ) /* tab key */
        need_to_switch = 0;
    else
        need_to_switch = 1;    
        
	return true;
}

function setDisabled(OnOffFlag,formFields)
{
	for (var i = 1; i < setDisabled.arguments.length; i++)
		setDisabled.arguments[i].disabled = OnOffFlag;
}


function checkFiled(fieldObj)
{
    /*I don't know how to check the ip if invalid ...
    if(fieldObj.value.match( /[^\x30-\x39]/ ) && fieldObj.value.match( /[^\x41-\x46]/ ) && fieldObj.value.match( /[^\x61-\x66]/ ))*/
    var temp = fieldObj.value;
    
    var tmp;
    if (fieldObj.value == "")
    {
        temp = "0000";
    }
    else
    {
        if (fieldObj.value.length < 4)
        {
            if (fieldObj.value.length == 1)
            {
                tmp = '000'+fieldObj.value;
            }   
            else if (fieldObj.value.length == 2)
            {
                tmp = '00'+fieldObj.value;
            }
            else if (fieldObj.value.length == 3)
            {
                tmp = '0'+fieldObj.value;
            }
            temp = tmp;
        }
        else 
        {
            temp = fieldObj.value;
        }
    }
    
    for(i=0; i<fieldObj.value.length;i++)
    {
        var c = fieldObj.value.substring(i, i+1);
        if(("0" <= c && c <= "9") || ("a" <= c && c <= "f") || ("A" <= c && c <= "F"))
        {
            continue;
        }
        else 
            return true;
    }

    fieldObj.value = temp.toUpperCase();

    return false;
}

function checkUnicast(fieldObj)
{    
    var c = fieldObj.value.substring(0, 1);
    
    if("2" == c || c == "3")
    {
        return false;
    }
    else 
        return true;
}

function isIPv6Equals(src,des)
{
    var srcArr=convert2CompleteIpV6(src).split(":");
    var desArr=convert2CompleteIpV6(des).split(":");
    for(var i=0;i<8;i++)
    {
        if(parseInt(srcArr[i],16)!=parseInt(desArr[i],16))
        {
            return false;
        }
    }
    return true;
}

function convert2CompleteIpV6(ip)
{
    var ipV6=ip;
    var index=ip.indexOf("::");
    if(index>0)
    {
        var size=8-(ip.split(":").length-1);
        var tmp="";
        for(var i=0;i<size;i++)
        {
            tmp+=":0";
        }
        tmp+=":";
        ipV6=ip.replace("::",tmp);
    }
    else if(index==0)
    {
        ipV6=ip.replace("::","0:0:0:0:0:0:0:");
    }
    return ipV6;
}

