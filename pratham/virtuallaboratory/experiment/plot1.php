<?php require_once("header.php"); ?>
<script src="scripts/jquery.js" type="text/javascript"></script>
<script type="text/javascript">
<?php 	$fhandleradius = fopen("radius.txt", 'r') or die("can't open file"); echo fgets($fhandleradius); ?>;

if (RADIUS_UNSCALED>15150) RADIUS_UNSCALED = 15150;
else if (RADIUS_UNSCALED<6650) RADIUS_UNSCALED = 6650;

RADIUS = RADIUS_UNSCALED*96/6400;

</script>
<script src="scripts/animation.js" type="text/javascript"></script>
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
	#Animation{
		width:590px;
		height:600px;
		background:#EFEFEF url(images/earth.gif) no-repeat 197px 203px;
	}
	#Sate{
		width:72px;
		height:89px;
		background:url(images/sate.gif) no-repeat;
		margin-left:262px;
		margin-top:270px;
		position:absolute;
	}
	#Slider{
		height:20px;
		width:540px;
		margin-left:38px;
		background:#CCCCCC;
		z-index:12;
	}
	.placeholderclass{
		background:url(images/ylabel.jpg) no-repeat left;
		margin-left:-10px;
		padding-left:10px;
	}
	.xlabel{
		background:url(images/xlabel.jpg) no-repeat center;
		height:20px;
	}	
</style>
</head>
<body id="top" onLoad="PlaceSatAnimate()">
<table width="800" border="0" cellspacing="0" cellpadding="0" align="center" bgcolor="#FFFFFF">
  <tr><td><table width="590" border="0" cellspacing="0" cellpadding="0" align="center">
  	<tr><td>&nbsp;</td></tr>
    <tr><td>
	 <?php include "plot.php"?>
	<!--<div style="text-align:center"><a href="simulation.html" title="Simulation"><img src="images/next.jpg" border="0"/></a></div></div>--></td></tr>
    <tr><td>
   
  <div id="page">
    <div id="Animation">
    	<div id="Sate">
        </div>
    </div>
    <div style="font-family:Georgia, 'Times New Roman', Times, serif; font-size:16px; color:#0099FF; background-color:#EFEFFF; padding:5px; border:thin #666666 solid; width:300px; margin-left:auto; margin-right:auto; text-align:center"><a onClick="SetPause(0)" href="Javascript:void(0);" style="color:#0099CC">PLAY</a> | <a onClick="SetPause(1)" href="Javascript:void(0);" style="color:#0099CC">PAUSE</a></div></div></td></tr></table></td></tr></table>
<?php require_once("footer.php");?>