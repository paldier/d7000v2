#!/bin/sh
nvram=/bin/config
CONSOLE=/dev/console


GUI_Region=$($nvram get GUI_Region)

print_charset()
{
        CHARSET="UTF-8"
        echo -n  "$CHARSET"
}

print_language_js()
{
	lang_file="language/$GUI_Region.js"
	path="/www/$lang_file"

	if [ -f $path ]; then
		echo "<script language=javascript type=text/javascript src='./../$lang_file'></script>"
	else
		echo "<script language=javascript type=text/javascript src='./../language/English.js'></script>"
	fi

}

print_cgi_header() # $1: content_type
{
        time_stamp_dni=$(cat /proc/uptime)
        local content_type date

        content_type="$1"
        [ "x$content_type" = "x" ] && content_type="text/html"
        date=`date -u '+%a, %d %b %Y %H:%M:%S %Z'`

cat <<EOF
Content-type: $content_type

EOF
}


print_menu_header()
{
    echo '<HTML><HEAD><TITLE>WNR2000</TITLE>'
    echo "<META http-equiv=content-type content='text/html;charset=UTF-8'>"
    echo '<META content="MSHTML 6.00.2800.1141" name=GENERATOR>'
    echo "<script language=javascript type=text/javascript src='/languages-en.js'></script>"
}

print_http_refresh () # $1: page to be refresh, $2: delay_time
{
        local delay_time
        delay_time="$2"
        [ "x$delay_time" = "x" ] && delay_time="0"

		local url="$1"
		
cat <<EOF
<HTML>
<HEAD><meta http-equiv="Refresh" content="$delay_time; url=$url">
<Meta http-equiv="Pragma" Content="no-cache">
<META HTTP-equiv="Cache-Control" content="no-cache">
<Meta http-equiv="Expires" Content="0">
<META http-equiv='Content-Type' content='text/html; charset=$(print_charset)'>
EOF
print_language_js
cat <<EOF
<link rel="stylesheet" href="/form.css">
</HEAD>
<BODY bgcolor=#ffffff>
<tr><td colspan=2><br><img src=/liteblue.gif width=100% height=12></td></tr>
<script>window.location.href="$url"</script>
</BODY>
</HTML>
EOF
}

print_wait_message () 
{
cat <<EOF
<HTML>
<HEAD><meta http-equiv="Refresh">
<Meta http-equiv="Pragma" Content="no-cache">
<META HTTP-equiv="Cache-Control" content="no-cache">
<Meta http-equiv="Expires" Content="0">
<META http-equiv='Content-Type' content='text/html; charset=$(print_charset)'>
EOF
print_language_js
cat <<EOF
<link rel="stylesheet" href="/form.css">
</HEAD>
<BODY bgcolor=#ffffff>
<tr><td colspan=2><br><img src=/liteblue.gif width=100% height=12></td></tr>
<script>document.write(wait_message)</script>
</BODY>
</HTML>
EOF
}
