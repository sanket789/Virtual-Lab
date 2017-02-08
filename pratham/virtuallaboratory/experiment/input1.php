<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Manas | Input</title>
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
$temp = $_GET["size"]/100;
$output = $temp."\n";
$output .= $_GET["conductivity"]."\n";
$output .= $_GET["specificheat"]."\n";
$output .= $_GET["density"]."\n";
$temp = $_GET["thickness"]/1000;
$output .= $temp."\n";
$output .= $_GET["Ex_absorptivity"]."\n";
$output .= $_GET["Ex_emissivity"]."\n";
$output .= $_GET["In_absorptivity"]."\n";
$output .= $_GET["In_emissivity"]."\n";
$output .= $_GET["face1"]."\n";
$output .= $_GET["face2"]."\n";
$output .= $_GET["face3"]."\n";
$output .= $_GET["face4"]."\n";
$output .= $_GET["face5"]."\n";
$output .= $_GET["face6"];
	$fhandle0 = fopen("input.txt", 'w') or die("can't open file");
    fwrite($fhandle0, $output);
	fclose($fhandle0);
echo exec('./satellite2');

?>
<a href="index.html" title="Choose orbit again" style="color:#0066FF">&laquo; Back to homepage</a>
</div>
</body>
</html>
