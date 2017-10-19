//public message
var msg_blank = "%s <%getstr("trigger_null");%>";
var msg_space = "<%getstr("msg_space");%> %s\n";
var msg_blank_in = "<%getstr("msg_blank_in");%> %s\n";
var msg_invalid = "\n<%getstr("msg_invalid");%> %s\n<%getstr("msg_invalid1");%>: \n%s\n\n";
var msg_check_invalid = "%s <%getstr("msg_check_invalid");%>";
var msg_greater = "%s <%getstr("msg_greater");%> %s";
var msg_less = "%s <%getstr("msg_less");%> %s";
var current_gui_language = "<% nvram_get("gui_region"); %>";

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
