
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Virtual Laboratory in Satellite Modeling & Simulation</title>
<link rel="stylesheet" type="text/css" href="css/menu.css" />
<link rel="stylesheet" type="text/css" href="css/main.css" />
<link rel="stylesheet" type="text/css" href="css/index.css" />
<script type="text/javascript" src="js/jquery.min.js"></script>
<script type="text/javascript" src="js/menu.js"></script>
<script type="text/javascript" src="js/main.js"></script>
<script type="text/javascript" src="js/heattransfer.js"></script>
<script type="text/javascript">
ddsmoothmenu.init({
	mainmenuid: "smoothmenu1",
	orientation: 'h', 
	classname: 'ddsmoothmenu', 
	contentsource: "markup"
})
</script>
<script type="text/javascript">
if (document.getElementById){
document.write('<style type="text/css">\n')
document.write('.dropcontent{display:none;}\n')
document.write('</style>\n')
}

function contractall(){
if (document.getElementById){
var inc=0
while (document.getElementById("dropmsg"+inc)){
document.getElementById("dropmsg"+inc).style.display="none"
inc++
}
}
}

function expandone(){
if (document.getElementById){
var selectedItem=document.dropmsgform.dropmsgoption.selectedIndex
contractall()
document.getElementById("dropmsg"+selectedItem).style.display="block"
}
}

if (window.addEventListener)
window.addEventListener("load", expandone, false)
else if (window.attachEvent)
window.attachEvent("onload", expandone)

</script>
</head>

<body bgcolor="#009900" >
<table width="800" border="0" cellspacing="0" cellpadding="0" align="center" bgcolor="#FFFFFF">
  <tr>
    <td height="75" class="Head"><center>
      Virtual Laboratory in Satellite Modeling & Simulation
    </center></td>
  </tr>
  <tr>
		<td>
			<!--<img src="images/index_02.gif" width="1000" height="35" alt="">--><div id="smoothmenu1" class="ddsmoothmenu">
      <ul>
     <li><a href="/pratham/virtuallaboratory/index.php">Home</a></li>
        <li><a href="#">Theory</a>
        <ul>
  			<li><a href="/pratham/virtuallaboratory/thermals.php">Solar Radiation</a></li>
       	 	<li><a href="/pratham/virtuallaboratory/heattransfer.php">Heat Transfer</a></li>
        	<!--<li><a href="#"></a></li>-->
        </ul>
    	</li>
		<li><a href="/pratham/virtuallaboratory/procedure.php">Procedure</a>
        <!--<ul>
    		<li><a href="#">Thermals</a></li>
       	 	<li><a href="#">Controls</a></li>
        	<li><a href="#">Payload</a></li>
        </ul>-->
  		</li>
  		<li><a href="/pratham/virtuallaboratory/experiment/experiment.php">Simulation</a>
        </li>
        <li><a href="/pratham/virtuallaboratory/reference.php">Resources</a>
       	</li>
</ul>
<br style="clear: left" />
</div></td>
	</tr></table>