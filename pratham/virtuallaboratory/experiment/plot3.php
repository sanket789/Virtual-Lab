    <link href="plot_files/layout.css" rel="stylesheet" type="text/css">
    <!--[if IE]><script language="javascript" type="text/javascript" src="scripts/excanvas.pack.js"></script><![endif]-->
    <script language="javascript" type="text/javascript" src="scripts/jquery.js"></script>
    <script language="javascript" type="text/javascript" src="scripts/jquery.flot.js"></script>
    <div id="AllGraphs" style="width: 575px; margin-left:auto; margin-right:auto;">
    <h3>Face 1: Zenith</h3>
        <div class="placeholderclass" id="placeholder0" style="width: 575px; height: 200px; position: relative;"></div>
        <div class="xlabel"></div>
    <h3>Face 2: Nadir</h3>
        <div class="placeholderclass" id="placeholder1" style="width: 575px; height: 200px; position: relative;"></div>
        <div class="xlabel"></div>
    <h3>Face 3: Leading</h3>
        <div class="placeholderclass" id="placeholder2" style="width: 575px; height: 200px; position: relative;"></div>
        <div class="xlabel"></div>
    <h3>Face 4: Lagging</h3>
        <div class="placeholderclass" id="placeholder3" style="width: 575px; height: 200px; position: relative;"></div>
        <div class="xlabel"></div>
    <h3>Face 5: Sun Side</h3>
        <div class="placeholderclass" id="placeholder4" style="width: 575px; height: 200px; position: relative;"></div>
        <div class="xlabel"></div>
    <h3>Face 6: Anti Sun Side</h3>
        <div class="placeholderclass" id="placeholder5" style="width: 575px; height: 200px; position: relative;"></div>
        <div class="xlabel"></div>
    </div>
<script id="source" language="javascript" type="text/javascript">
$(function () {
	var d0 = [
	<?php 	
			$input1 = "input2.txt";
			$filehandle2 = fopen($input1,'r');
			$imax = fgets($filehandle2); 
			$myFile = "of1.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<$imax;$i++) {
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
	$.plot($("#placeholder0"), [ d0 ], {yaxis: { max: 350}});
});
$(function () {
	var d1 = [
	<?php 	$myFile = "of2.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<$imax;$i++) {
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
	$.plot($("#placeholder1"), [ d1 ], {yaxis: { max: 350 }});
});
$(function () {
	var d2 = [
	<?php 	$myFile = "of3.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<$imax;$i++) {
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
	$.plot($("#placeholder2"), [ d2 ], {yaxis: { max: 350 }});
});
$(function () {
//    var d2 = [[0, 3], [4, 8], [8, 5], [9, 13]];
	var d3 = [
	<?php 	$myFile = "of4.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<$imax;$i++) {
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
    $.plot($("#placeholder3"), [ d3 ], { yaxis:{max:350}});
});
$(function () {
//    var d2 = [[0, 3], [4, 8], [8, 5], [9, 13]];
	var d4 = [
	<?php 	$myFile = "of5.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<$imax;$i++) {
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
	$.plot($("#placeholder4"), [ d4 ], {yaxis: { max: 350}});
});
$(function () {
//    var d2 = [[0, 3], [4, 8], [8, 5], [9, 13]];
	var d5 = [
	<?php 	$myFile = "of6.txt"; 
			$fh = fopen($myFile, 'r');
			for ($i=0; $i<$imax;$i++) {
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
	$.plot($("#placeholder5"), [ d5 ], {yaxis: {max: 350}});
});
</script>