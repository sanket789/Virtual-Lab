<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Virtual Laboratory in Satellite Modeling & Simulation | Simulation</title>
<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<meta name="description" content="" />
<meta name="keywords" content="" />
<link rel="stylesheet" type="text/css" href="default.css" />
<style type="text/css">
	h1{
		line-height:120%;
		font-family: Georgia, Verdana, Arial, "Sans Serif";
		font-size: 20px;
		color: #323232;
		text-align:center;
	}
	h4{
		line-height:120%;
		font-family: Georgia, Verdana, Arial, "Sans Serif";
		font-size: 16px;
		color: #323232;
		text-align:center;
	}
</style>
</head>
<body id="top" onload="setTimeout('Check()', 5000)">
<div id="wrapper">
<div id="blank">
<div id="main">

<div id="search">
<div id="logo">Virtual Laboratory in Satellite Modeling & Simulation<a href="#"></a></div>
</div>
	<div id="menu">
		<ul>
		<li><a href="index.html">Home</a></li>
		<li><a href="credits.html">Credits</a></li>
		<li><a href="http://www.aero.iitb.ac.in/pratham">About ISSP</a></li>
<li><a href="Documentation.html">Documentation</a></li>
		</ul>

</div>
    <div id="page">
    <script type="text/javascript">
	document.write('<iframe width="1px" height="1px" allowtransparency="1" frameborder="0" src="input_iframe.php"></iframe>');
	</script>
	<script type="text/javascript">
var xmlhttp;
var xmlhttp1;
function loadXMLDoc(url)
{
xmlhttp=null;
if (window.XMLHttpRequest)
  {// code for Firefox, Opera, IE7, etc.
  xmlhttp=new XMLHttpRequest();
  }
else if (window.ActiveXObject)
  {// code for IE6, IE5
  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }
if (xmlhttp!=null)
  {
  xmlhttp.onreadystatechange=state_Change;
  xmlhttp.open("GET",url,true);
  xmlhttp.send(null);
  }
else
  {
  alert("Your browser does not support XMLHTTP.");
  }
}
function loadXMLDoc1(url) {
	xmlhttp1=null;
	if (window.XMLHttpRequest) 	{
		xmlhttp1=new XMLHttpRequest();
	}
	else if (window.ActiveXObject) {
		xmlhttp1=new ActiveXObject("Microsoft.XMLHTTP");
  	}
	if (xmlhttp1!=null) {
		xmlhttp1.onreadystatechange=state_Change1;
		xmlhttp1.open("GET",url,true);
		xmlhttp1.send(null);
  	}
	else {
		alert("Your browser does not support XMLHTTP.");
  	}
}

PERCENTAGE = 0;
RESPONSE_INPUT = "undone";

function state_Change() {
	if (xmlhttp.readyState==4) {// 4 = "loaded"
		if (xmlhttp.status==200) {// 200 = "OK"
		    RESPONSE_INPUT = xmlhttp.responseText;
    	}
		else {
		    alert("Problem retrieving data:" + xmlhttp.statusText);
    	}
  	}
}

function state_Change1() {
	if (xmlhttp1.readyState==4) {
		if (xmlhttp1.status==200) {// 200 = "OK"
			PERCENTAGE= xmlhttp1.responseText;
    	}
		else {
		    alert("Problem retrieving data:" + xmlhttp1.statusText);
		}
  	}
}
i=0;
function Check() {
	name = "status.txt";
	loadXMLDoc(name);
	if (RESPONSE_INPUT == "Done") {
		window.location = "plot2.php";	
	}
	else {
	loadXMLDoc1("status1.txt");
	document.getElementById('Status').innerHTML = "Computation in progress:<br/> Approximately "+ PERCENTAGE + "% done";
		i++;
		setTimeout('Check()',2000);
	}
}
</script>
<div id="DataContainer1"><img src="images/loading.gif" alt="loading"/></div>
<div id="Status"></div>
<a href="Javascript:void(0)" onclick="Check()">Click here to View status</a>
<div id="footer">

IIT Bombay
</div>
</div>
</div>
</div>
</html>
