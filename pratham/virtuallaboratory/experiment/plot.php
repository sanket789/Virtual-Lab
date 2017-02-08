    <link href="plot_files/layout.css" rel="stylesheet" type="text/css">
    <link rel="stylesheet" type="text/css" href="css/main.css" />
	<link rel="stylesheet" type="text/css" href="css/index.css" />
    <!--[if IE]><script language="javascript" type="text/javascript" src="scripts/excanvas.pack.js"></script><![endif]-->
    <script language="javascript" type="text/javascript" src="scripts/jquery.flot.js"></script>
    <div id="Slider" style="width: 550px; margin-left:75x; margin-right:auto;">
   	  <div id="SetPosition"><img src="images/marker.jpg" alt="|" height="1000" width="10"></div>
    </div>
    <div id="AllGraphs" style="width: 575px; margin-left:auto; margin-right:auto;">    <span class="Names">Face 1: Zenith</span>
    <div class="placeholderclass" id="placeholder0" style="width: 575px; height: 125px; position: relative;"></div>
        <div class="xlabel"></div>
        <span class="Names">Face 2: Nadir</span>
    <div class="placeholderclass" id="placeholder1" style="width: 575px; height: 125px; position: relative;"></div>
        <div class="xlabel"></div>
        <span class="Names">Face 3: Leading</span>
    <div class="placeholderclass" id="placeholder2" style="width: 575px; height: 125px; position: relative;"></div>
        <div class="xlabel"></div>
        <span class="Names">Face 4: Lagging</span>
    <div class="placeholderclass" id="placeholder3" style="width: 575px; height: 125px; position: relative;"></div>
        <div class="xlabel"></div>
        <span class="Names">Face 5: Sun Side</span>
    <div class="placeholderclass" id="placeholder4" style="width: 575px; height: 125px; position: relative;"></div>
        <div class="xlabel"></div>
        <span class="Names">Face 6: Anti Sun Side</span>
    <div class="placeholderclass" id="placeholder5" style="width: 575px; height: 125px; position: relative;"></div>
        <div class="xlabel"></div>
    </div>
<script id="source" language="javascript" type="text/javascript">

$(function () {
	var d0 = [
	<?php 	$myFile = "xf00.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<200;$i++) {
				$x = fgets($fh);
				$y = fgets($fh);
				echo "[".$x.", ".$y."], ";
				}
			$x = fgets($fh);
			$y = fgets($fh);
			echo "[".$x.", ".$y."]";
			fclose($fh);
			echo $theData;
 	?>];
	$.plot($("#placeholder0"), [ d0 ], {yaxis: { max: 1375 }});
});
$(function () {
	var d1 = [
	<?php 	$myFile = "xf11.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<200;$i++) {
				$x = fgets($fh);
				$y = fgets($fh);
				echo "[".$x.", ".$y."], ";
				}
			$x = fgets($fh);
			$y = fgets($fh);
			echo "[".$x.", ".$y."]";
			fclose($fh);
			echo $theData;
 	?>];
	$.plot($("#placeholder1"), [ d1 ], {yaxis: { max: 1375 }});
});
$(function () {
	var d2 = [
	<?php 	$myFile = "xf22.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<200;$i++) {
				$x = fgets($fh);
				$y = fgets($fh);
				echo "[".$x.", ".$y."], ";
				}
			$x = fgets($fh);
			$y = fgets($fh);
			echo "[".$x.", ".$y."]";
			fclose($fh);
			echo $theData;
 	?>];
/*    $.plot($("#placeholder2"), [ d2 ], {
						 yaxis: {
						 	max:1300 }
							});
							*/
	$.plot($("#placeholder2"), [ d2 ], {yaxis: { max: 1375 }});
});
$(function () {
//    var d2 = [[0, 3], [4, 8], [8, 5], [9, 13]];
	var d3 = [
	<?php 	$myFile = "xf33.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<200;$i++) {
				$x = fgets($fh);
				$y = fgets($fh);
				echo "[".$x.", ".$y."], ";
				}
			$x = fgets($fh);
			$y = fgets($fh);
			echo "[".$x.", ".$y."]";
			fclose($fh);
			echo $theData;
 	?>];
    $.plot($("#placeholder3"), [ d3 ], { yaxis:{max:1375}});
});
$(function () {
//    var d2 = [[0, 3], [4, 8], [8, 5], [9, 13]];
	var d4 = [
	<?php 	$myFile = "xf44.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<200;$i++) {
				$x = fgets($fh);
				$y = fgets($fh);
				echo "[".$x.", ".$y."], ";
				}
			$x = fgets($fh);
			$y = fgets($fh);
			echo "[".$x.", ".$y."]";
			fclose($fh);
			echo $theData;
 	?>];
	$.plot($("#placeholder4"), [ d4 ], {yaxis: { max: 1375 }});
});
$(function () {
//    var d2 = [[0, 3], [4, 8], [8, 5], [9, 13]];
	var d5 = [
	<?php 	$myFile = "xf55.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<200;$i++) {
				$x = fgets($fh);
				$y = fgets($fh);
				echo "[".$x.", ".$y."], ";
				}
			$x = fgets($fh);
			$y = fgets($fh);
			echo "[".$x.", ".$y."]";
			fclose($fh);
			echo $theData;
 	?>];
	$.plot($("#placeholder5"), [ d5 ], {yaxis: {max: 1375 }});
});
</script>