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
var invalidMSNameStr = "\"/\\[<]>.:;,|=+*?";

function tmdashboard()
{
    window.open("setup.cgi?todo=save&next_file=tmdashboard.htm&this_file=tmservice.htm&h_tmss=enable&h_tmp_enable=always");
    //window.open("http://tmss.trendmicro.com/dashboard/dashboard.aspx?ABCDEDFGBFB5A72BCE20DEACDERYYYHUCUUIO", "tmd", "width=800, height=550, left=10, top=10, scrollbars=yes, toolbar=no, resizable=yes, menubar=no, status=yes");

}


//  display
var showit = "block";
var hideit = "none";

function setDisplay(el,shownow)  // IE & NS6; shownow = true, false
{
        if (document.all)
                document.all(el).style.display = (shownow) ? showit : hideit ;
        else if (document.getElementById)
                document.getElementById(el).style.display = (shownow) ? showit : hideit ;
}



function showMsg()
{
        var msgVar=document.forms[0].message.value;
        if (msgVar.length > 1) 
                alert(msgVar);
}

function closeWin(win_var)
{
        if(document.layers)
                return;
        if ( ((win_var != null) && (win_var.close)) || ((win_var != null) && (win_var.closed==false)) )
                win_var.close();
}

function openHelpWin(file_name)
{
   helpWinVar = window.open(file_name,'help_win',HelpOptionsVar);
   if (helpWinVar.focus)
                setTimeout('helpWinVar.focus()',200);
}

function openGlossWin()
{
        glossWinVar = window.open('','gloss_win',GlossOptionsVar);
        if (glossWinVar.focus)
                setTimeout('glossWinVar.focus()',200);
}

function openDataSubWin(filename,win_type)
{
        closeWin(datSubWinVar);
        datSubWinVar = window.open(filename,'datasub_win',win_type);
        if (datSubWinVar.focus)
                setTimeout('datSubWinVar.focus()',200); 
}

function closeSubWins()
{
        closeWin(helpWinVar);
        closeWin(glossWinVar);
        closeWin(datSubWinVar);
}

function loadhelp(fname,anchname) {
if(top.frames.length > 0)
  {
        if ((loadhelp.arguments.length == 1 ) || (anchname == "" ))
                top.helpframe.location.href="h"+fname+".htm";
        else
                top.helpframe.location.href="h"+fname+".htm#" + anchname;
  }
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

        if(str.charAt(0) == '0')
        {
                error_msg = addstr(msg_outofrange,field_name,"100","FFF");
                error_msg += "\n";
                return error_msg;
        }

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

function isValidStr(inputStr,validChars,len)  // returns true or false, no msg
{
        if (len <= 0) // no set length
                ;
        else if (inputStr.length != len)
                return false;
    for(i=0; i < inputStr.length; i++) 
        {
        var c = inputStr.charAt(i);
                if (validChars.indexOf(c) == -1 )
                        return false;
    }
    return true;
}

function checkInt(text_input_field, field_name, min_value, max_value, required)
// NOTE: Doesn't allow negative numbers, required is true/false
{
        var str = text_input_field.value;
        var error_msg= "";

        if (text_input_field.value.length==0) // blank
        {
                if (required)
                        error_msg = addstr(msg_blank,field_name);
        }
        else // not blank, check contents
        {
                for (var i=0; i < str.length; i++)
                {
                        if ((str.charAt(i) < '0') || (str.charAt(i) > '9'))
                                error_msg = addstr(msg_check_invalid,field_name);
                }
                if (error_msg.length < 2) // don't parse if invalid
                {
                        var int_value = parseInt(str);
                        if (int_value < min_value || int_value > max_value)
                                error_msg = addstr(msg_outofrange,field_name,min_value,max_value);
                }
        }
        if (error_msg.length > 1)
                error_msg = error_msg + "\n";
        return(error_msg);
}


function sumvalue(F)
{    
        alert("Called sumvalue(), but should not.\nUse badMacField instead");

}
function MACAddressBlur(address)
{
        alert("Called MACAddressBlur(), but should not.\nUse badMacField instead");
}

// =============================   msg.js
//public message
var msg_blank = "%s can not be blank.\n";
var msg_space = "Blanks or spaces are not allowed in %s\n";
var msg_blank_in = "Blanks are not allowed in %s\n";
var msg_invalid = "\nInvalid character or characters in %s\nValid characters are: \n%s\n\n";
var msg_check_invalid = "%s contains an invalid number.";
var msg_greater = "%s must be greater than %s";
var msg_less = "%s must be less than %s";
var msg_outofrange = "%s is out of range [%s ~ %s]";

var msg_first = "First";
var msg_second = "Second";
var msg_third = "Third";
var msg_fourth = "Fourth";

function addstr(input_msg)
{
        var last_msg = "";
        var str_location;
        var temp_str_1 = "";
        var temp_str_2 = "";
        var str_num = 0;
        temp_str_1 = addstr.arguments[0];
        while(1)
        {
                str_location = temp_str_1.indexOf("%s");
                if(str_location >= 0)
                {
                        str_num++;
                        temp_str_2 = temp_str_1.substring(0,str_location);
                        last_msg += temp_str_2 + addstr.arguments[str_num];
                        temp_str_1 = temp_str_1.substring(str_location+2,temp_str_1.length);
                        continue;
                }
                if(str_location < 0)
                {
                        last_msg += temp_str_1;
                        break;
                }
        }
        return last_msg;
}

// =============================   browser.js

function isIE(){
    var browser = new Object();
    browser.version = parseInt(navigator.appVersion);
    browser.isNs = false;
    browser.isIe = false;
    if(navigator.appName.indexOf("Netscape") != -1)
        browser.isNs = true;
    else if(navigator.appName.indexOf("Microsoft") != -1)
        browser.isIe = true;
    if(browser.isNs) return false;
    else if (browser.isIe) return true;
}

function add(out,in1,in2,in3,in4) {
    var Total;
    Total=in1.value+"."+in2.value+"."+in3.value+"."+in4.value;
    out.value=Total; 
}

function load4(Mydata,ip1,ip2,ip3,ip4) {
    var len; var ad; var temp;
    var Myall;
    Myall=Mydata.value;    //ip1 
    len=Myall.length;
    temp=Myall.indexOf(".");
    ad=Myall.substring(0,temp); 
    ip1.value=ad;
    //ip2 
    Myall=Myall.substring(temp+1,len);
    len=Myall.length;
    temp=Myall.indexOf(".");
    ad=Myall.substring(0,temp);
    ip2.value=ad;
    //ip3 
    Myall=Myall.substring(temp+1,len);
    len=Myall.length;
    temp=Myall.indexOf(".");
    ad=Myall.substring(0,temp);
    ip3.value=ad;
    //ip4 
    Myall=Myall.substring(temp+1,len);
    ad=Myall; ip4.value=ad;
} 

// =============================   utility.js
var msg_invalid_ip = "Invalid IP, please enter again!\n";
function isIPaddr(addr) {
    var i;
    var a;
    if(addr.split) {
        a = addr.split(".");
    }else {
        a = cdisplit(addr,".");
    }
    if(a.length != 4) {
        return false;
    }
    for(i = 0; i<a.length; i++) {
        var x = a[i];
        if( x == null || x == "" || !_isNumeric(x) || x<0 || x>255 ) {
            return false;
        }
    }
    return true;
}

function isIntStr(str) {
    var i;
    if(str.length < 1)
        return false;
    for(i = 0; i<str.length; i++) {
        var c = str.substring(i, i+1);
        if("0" <= c && c <= "9") {
            continue;
        }
        return false;
    }
    return true;
}

function isHexStr(str) {
    var i;
    for(i = 0; i<str.length; i++) {
        var c = str.substring(i, i+1);
        if(("0" <= c && c <= "9") || ("a" <= c && c <= "f") || ("A" <= c && c <= "F")) {
            continue;
        }
        return false;
    }
    return true;
}

function checkMacStr(macField) 
{
        var MacStrOrg = macField.value;
        var MacStrNoSep = MacStrOrg;
        var macArray; var c; var i;

        if(MacStrOrg.indexOf(":") > -1)
                c = ":";
        else if(MacStrOrg.indexOf("-") > -1)
                c = "-";
        else 
                return isValidStr(MacStrOrg,hex_str,12);
        macArray = MacStrOrg.split(c);
        if(macArray.length != 6)
                return false;
        for ( i = 0; i < macArray.length; i++)
        {

                if (macArray[i].length != 2 )
                        return false;
        }
        MacStrNoSep =  MacStrNoSep.replace(/:/g,"");
        MacStrNoSep =  MacStrNoSep.replace(/-/g,"");
        return isValidStr(MacStrNoSep,hex_str,12);
}

/* Check Numeric*/
function isNumeric(str, max) {
    if(str.value.length == 0 || str.value == null || str.value == "") {
        if (str.focus)
            str.focus();
        return true;
    }
    
    var i = parseInt(str.value,10);
    if(i>max) {
        if (str.focus)
            str.focus();
        return true;
    }
    for(i=0; i<str.value.length; i++) {
        var c = str.value.substring(i, i+1);
        if("0" <= c && c <= "9") {
            continue;
        }
        if (str.focus)
            str.focus();
        return true;
    }
    return false;
}

/* Check IP Address Format*/
function checkIPMain(ip,max) {
    if( isNumeric(ip, max) ) {
        if (ip.focus)
            ip.focus();
        return true;
    }
}
function badLANIP(ip1, ip2, ip3, ip4,max) {
    if(checkIPMain(ip1,223)) return true; 
    if(checkIPMain(ip2,255)) return true;
    if(checkIPMain(ip3,255)) return true;
    if(checkIPMain(ip4,max)) return true;
    if((parseInt(ip1.value)==0)||(parseInt(ip1.value)==0)&&(parseInt(ip2.value)==0)&&(parseInt(ip3.value)==0)&&(parseInt(ip4.value)==0))
        return true;
    return false;
}

function badIP(ip1, ip2, ip3, ip4,max) {
    if(checkIPMain(ip1,255)) return true; 
    if(checkIPMain(ip2,255)) return true;
    if(checkIPMain(ip3,255)) return true;
    if(checkIPMain(ip4,max)) return true;
    if((parseInt(ip1.value)==0)||(parseInt(ip1.value)==0)&&(parseInt(ip2.value)==0)&&(parseInt(ip3.value)==0)&&(parseInt(ip4.value)==0))
        return true;
    return false;
}


/* Check Blank*/
function isBlank(str) {
    if(str.value == "") {
        if (str.focus)
            str.focus();
        return true;
    } else 
        return false;
}

/* Check Phone Number*/
function isPhonenum(str) {
    var i;
    if(str.value.length == 0) {
        if (str.focus)
            str.focus();
        return true;
    }
    for (i = 0; i<str.value.length; i++) {
        var c = str.value.substring(i, i+1);
        if (c>= "0" && c <= "9")
            continue;
        if ( c == '-' && i !=0 && i != (str.value.length-1) )
            continue;
        if ( c == ',' ) continue;
        if (c == ' ') continue;
        if (c>= 'A' && c <= 'Z') continue;
        if (c>= 'a' && c <= 'z') continue;
        if (str.focus)
            str.focus();
        return true;
    }
    return false;
}

/* 0:close 1:open*/
function openHelpWindow(filename) {
    helpWindow = window.open(filename,"thewindow","width=300,height=400,scrollbars=yes,resizable=yes,menubar=no");
}

function checkSave() {
    answer = confirm(did_you_save);
    if (answer !=0) {
        return true;
    } else return false;
}

function alertPassword(formObj) {
    alert(re_confirm_ps);
    if (formObj.focus)
        formObj.focus();
}
function isEqual(cp1,cp2)
{
	if(parseInt(cp1.value,10) == parseInt(cp2.value,10))
        {
		if (cp2.focus)
			cp2.focus();
                return true;
        }
        else return false;
}
function setDisabled(OnOffFlag,formFields)
{
        for (var i = 1; i < setDisabled.arguments.length; i++)
                setDisabled.arguments[i].disabled = OnOffFlag;
}

function cp_ip(from1,from2,from3,from4,to1,to2,to3,to4)
//true invalid from and to ip;  false valid from and to ip;
{
    var total1 = 0;
    var total2 = 0;
    
    total1 += parseInt(from4.value,10);
    total1 += parseInt(from3.value,10)*256;
    total1 += parseInt(from2.value,10)*256*256;
    total1 += parseInt(from1.value,10)*256*256*256;
    
    total2 += parseInt(to4.value,10);
    total2 += parseInt(to3.value,10)*256;
    total2 += parseInt(to2.value,10)*256*256;
    total2 += parseInt(to1.value,10)*256*256*256;
    if(total1 > total2)
        return true;
    return false;
}

function pi(val)
{
    return parseInt(val,10);
}    
function alertR(str)    
{
    alert(str);
    return false;
}    



function blankIP(f1,f2,f3,f4) // true if 0 or blank
{
        if( containStr(f1,"") && containStr(f2,"") && containStr(f3,"") && containStr(f4,"") )
                return true;
        if( containStr(f1,"0") && containStr(f2,"0") && containStr(f3,"0") && containStr(f4,"0") )
                return true;
        return false;
}


function containStr(fn,str) 
{
        return  (fn.value == str);
}


// =====  end  utility.js


function checkIntStr(str,minval,maxval)
{
        if(!(isIntStr(str)))
                return false;
        var ival = parseInt(str);
        if(ival < minval || ival > maxval)
                return false;
        else return true;
}


function isIpStr(addrStr) 
{
    var i;
    var a = addrStr.split(".");
    if(a.length != 4) 
        return false;
    if(!checkIntStr(a[0],1,254))
                return false;
    if(!checkIntStr(a[1],0,255))
                return false;
    if(!checkIntStr(a[2],0,255))
                return false;
    if(!checkIntStr(a[3],1,254))
                return false;
    return true;
}

function checkIP(ip1, ip2, ip3, ip4,max) {
    if(checkIPMain(ip1,255)) return true; 
    if(checkIPMain(ip2,255)) return true;
    if(checkIPMain(ip3,255)) return true;
    if(checkIPMain(ip4,max)) return true;
     
    if((ip1.value.charAt(0)=="0" && ip1.value.length!=1) ||
       (ip2.value.charAt(0)=="0" && ip2.value.length!=1) ||
       (ip3.value.charAt(0)=="0" && ip3.value.length!=1) ||
       (ip4.value.charAt(0)=="0" && ip4.value.length!=1)) 
        return true; 

    if((parseInt(ip1.value)==0)||
       ((parseInt(ip1.value)==0)&&(parseInt(ip2.value)==0)&&
        (parseInt(ip3.value)==0)&&(parseInt(ip4.value)==0)))
        return true;
    var loopback_ip_start   = (127 << 24)  |   (0 << 16)   |   (0 << 8)   |   (0);
    var loopback_ip_end     = (127 << 24)  |  (255 << 16)  |  (255 << 8)  | (255);
    var groupcast_ip_start  = (224 << 24)  |   (0 << 16)   |   (0 << 8)   |   (0);
    var groupcast_ip_end    = (239 << 24)  |  (255 << 16)  |  (255 << 8)  | (255);
    var dhcpresv_ip_start   = (169 << 24)  |  (254 << 16)  |   (0 << 8)   |   (0);
    var dhcpresv_ip_end     = (169 << 24)  |  (254 << 16)  |  (255 << 8)  | (255);
    var ip_addr = (ip1.value << 24) | (ip2.value << 16) | (ip3.value << 8) | (ip4.value);
    if((ip_addr >= loopback_ip_start)&&(ip_addr <= loopback_ip_end))
        return true;
    if((ip_addr >= groupcast_ip_start)&&(ip_addr <= groupcast_ip_end ))
        return true;
    if((ip_addr >= dhcpresv_ip_start)&&(ip_addr <= dhcpresv_ip_end))
        return true;
    return false;
}

function isDecimalNumber(str)
{
    if ((str.charAt(0)=='0') && (str.length != 1))
         return false;
    for(var i=0;i<str.length;i++)
    {
         if(str.charAt(i)<'0'||str.charAt(i)>'9')
         return false;
    }
    return true;
}
function _isNumeric(str) {
    var i;

    if(str.length == 0 || str == null || str == "" || !isDecimalNumber(str)) {
        return false;
    }

    for(i = 0; i<str.length; i++) {
        var c = str.substring(i, i+1);
        if("0" <= c && c <= "9") {
            continue;
        }
        return false;
    }
    return true;
}


function isValidIPaddr(addr) {
    var i;
    var a;
    if(addr.split) {
        a = addr.split(".");
    }else {
        a = cdisplit(addr,".");
    }
    if(a.length != 4) {
        return false;
    }
    for(i = 0; i<a.length; i++) {
        var x = a[i];
        if( x == null || x == "" || !_isNumeric(x) || x<0 || x>255 ) {
            return false;
        }
    }
    
    var ip1 = new String("");
    var ip2 = new String("");
    var ip3 = new String("");
    var ip4 = new String("");
    ip1.value = a[0];
    ip2.value = a[1];
    ip3.value = a[2];
    ip4.value = a[3];
    if(checkIP(ip1,ip2,ip3,ip4,254)||(parseInt(ip4.value,10)==0))
        return false;
    
    return true;
}

function isNetmask(mask1,mask2,mask3,mask4)
{
    var netMask;
    var i;
    var bit;
    var isChanged = 0;

    netMask = (mask1.value << 24) | (mask2.value << 16) | (mask3.value << 8) | (mask4.value);
    
    /* Check most byte (must be 255) and least significant bit (must be 0) */
    bit = (netMask & 0xFF000000) >>> 24;
    if (bit != 255)
        return false;
    
    bit = netMask & 1;
    if (bit != 0)
        return false;

    /* Now make sure the bit pattern changes from 0 to 1 only once */
    for (i=1; i<31; i++)
    {
        netMask = netMask >>> 1;
        bit = netMask & 1;

        if (bit != 0)
        {
            if (isChanged == 0)
                isChanged = 1;
        }
        else
        {
            if (isChanged == 1)
                return false;
        }
    }

    return true;
}

function chkIP_MSname(fobj,msg) // input could be ip or name
{
        var a = fobj.value.split(".");
        if  (fobj.value.length == 0)
                return msg;
        if ((a.length == 4) && (!(isIPaddr(fobj.value))))
                return msg;
        if (isIPaddr(fobj.value))
                return "";
        if (checkInvalidChars(fobj.value,invalidMSNameStr))
                return "";
        else return msg;
}

function subnet1isinsubnet2(ip1, netmask1, ip2, netmask2) 
{
    var ip_1 = ip1.split(".");
    var ip_2 = ip2.split(".");
    var netmask_1 = netmask1.split(".");
    var netmask_2 = netmask2.split(".");
    
    var cmp1;
    var cmp2;    
    
    var ip_1_long = (ip_1[0] << 24) | (ip_1[1] << 16) | (ip_1[2] << 8)| (ip_1[3]);
    var ip_2_long = (ip_2[0] << 24) | (ip_2[1] << 16) | (ip_2[2] << 8)| (ip_2[3]);
    var net_mask1_long = (netmask_1[0] << 24) | (netmask_1[1] << 16) | (netmask_1[2] << 8)| (netmask_1[3]);
    var net_mask2_long = (netmask_2[0] << 24) | (netmask_2[1] << 16) | (netmask_2[2] << 8)| (netmask_2[3]);    
    if(net_mask1_long >= net_mask2_long)
    {
        cmp1 = ip_1_long & net_mask1_long;
        cmp2 = ip_2_long & net_mask1_long;
        
        if(cmp1 == cmp2)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    else
    {
        cmp1 = ip_1_long & net_mask2_long;
        cmp2 = ip_2_long & net_mask2_long;
        if(cmp1 == cmp2)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
}

