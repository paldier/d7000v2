<!-- 
function check_top_url()
{
    if(window.location.href.indexOf("www.routerlogin.com") > 0)
        return "www.routerlogin.com";
    else if (window.location.href.indexOf("www.routerlogin.net") > 0)
        return "www.routerlogin.net";
    else if(window.location.href.indexOf("routerlogin.com") > 0)
        return "routerlogin.com";
    else if (window.location.href.indexOf("routerlogin.net") > 0)
        return "routerlogin.net";
    else
        return "";
}

function change_url(file_name)
{
    alert(file_name);
    if("www.routerlogin.com" == check_top_url())
        window.location.href = "http://www.routerlogin.net" + "/" + file_name;
    else if("www.routerlogin.net" == check_top_url())
        window.location.href = "http://routerlogin.com" + "/" + file_name;
    else if("routerlogin.com" == check_top_url())
        window.location.href = "http://routerlogin.net" + "/" + file_name;
    else if("routerlogin.net" == check_top_url())
        window.location.href = "http://www.routerlogin.com" + "/" + file_name;
    else 
        window.location.href = "http://routerlogin.net" + "/" + file_name;
}


//-->
