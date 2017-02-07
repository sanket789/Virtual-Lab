<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Manas | Take Action</title>
<style type="text/css">
body{
	margin:0;
	padding:0;
	background:#CCCCCC;
}
#wrapper{
	width:700px;
	height:400px;
	margin-top:-200px;
	margin-left:-350px;
	top:50%;
	left:50%;
	position:absolute;
	font-family:Georgia, "Times New Roman", Times, serif;
	font-size:20px;
	text-align:center;
	background-color:#000000;
	color:#CCCCCC;
	border:3px #666666 solid;
}
#submit{
	height:50px;
	width:80px;
}
.time{
width:40px;
</style>
</head>

<body>
<div id="wrapper">
<?php 
$orbit = $_GET["orbit"];
if ($orbit == "Equitorial") {
	$radius = $_GET["radius"];
	$incli = $_GET["inclination"];
	//Put Code one here...I am just printing inputs
	echo $orbit."<br>".$radius."<br>".$incli."<br>";
}
elseif ($orbit == "Polar") {
	$radius = $_GET["radius"];
	$mins = $_GET["mins"];
	$secs = $_GET["secs"];
	//Put Code one here...I am just printing inputs
	echo $orbit."<br>".$radius."<br>".$mins."<br>".$secs."<br>";
}
?>
<a href="index.html" title="Choose orbit again" style="color:#0066FF">&laquo; Back to homepage</a>
</div>
</body>
</html>
