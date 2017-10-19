function load_default(step){
    if (parent.frames['stepframe']){
        for(var i=1;i<=5;i++){
            eval('top.stepframe.document.getElementById("IA_menu_'+i+'")').className ="left_nav_headers";			
        }
        eval('top.stepframe.document.getElementById("IA_menu_'+step+'")').className ="left_nav_headers_current_state";		
    }
}

function get_browser()
{
        if(navigator.userAgent.indexOf("MSIE") != -1)
                return "IE";
        else if(navigator.userAgent.indexOf("Firefox") != -1)
                return "Firefox";
    else if(navigator.userAgent.indexOf("Chrome") != -1 )
                return "Chrome";		
        else if(navigator.userAgent.indexOf("Safari") != -1 )
                return "Safari";
        else if(navigator.userAgent.indexOf("Camino") != -1)
                return "Camino";
        else if(navigator.userAgent.indexOf("Gecko/") != -1)
                return "Gecko";
        else
                return "";
}

function CloseWindow()
{
    if(get_browser() != "Firefox"){
        if (confirm(ca_close_window)){
       	top.window.opener = null;
        top.window.open('','_self',''); 
        top.window.close();
        }
    }
}

function addfavorite()
{
   if (document.all)
   {
      window.external.addFavorite('http://www.mywifiext.net','WN2000RPT Configuration');
   }
   else if (window.sidebar)
   {
      window.sidebar.addPanel('WN2000RPT Configuration', 'http://www.mywifiext.net', "");
   }
}

function msg_close()
{
    var ca_add_bookmark="Do you want to add \"WN2000RPT Configuration\" as a bookmark?";
    var ca_finish="You may close the browser window now. ";
    
    if( get_browser() == "IE" || get_browser() == "Firefox")
    {
        if (confirm(ca_add_bookmark))
            addfavorite();
    }
    if( get_browser() == "Firefox")
        alert(ca_finish);
    else
        CloseWindow();
}
