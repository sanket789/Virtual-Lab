<?php
    include("constants.php");
    include("zipfile.php");
    include("util.php");
	$fhandle0 = fopen("xf0.txt", 'w') or die("can't open file0");
	$fhandle1 = fopen("xf1.txt", 'w') or die("can't open file1");
	$fhandle2 = fopen("xf2.txt", 'w') or die("can't open file2");
	$fhandle3 = fopen("xf3.txt", 'w') or die("can't open file3");
	$fhandle4 = fopen("xf4.txt", 'w') or die("can't open file4");
	$fhandle5 = fopen("xf5.txt", 'w') or die("can't open file5");
	$fhandle00 = fopen("xf00.txt", 'w') or die("can't open file6");
	$fhandle11 = fopen("xf11.txt", 'w') or die("can't open file7");
	$fhandle22 = fopen("xf22.txt", 'w') or die("can't open file8");
	$fhandle33 = fopen("xf33.txt", 'w') or die("can't open file9");
	$fhandle44 = fopen("xf44.txt", 'w') or die("can't open file10");
	$fhandle55 = fopen("xf55.txt", 'w') or die("can't open file11");
	$fhandleinput1 = fopen("input1.txt", 'w') or die("can't open file12");
	$fhandleradius = fopen("radius.txt", 'w') or die("can't open file13");	
    $f_equ = "";
    $f = array("", "", "", "", "", ""); // data from the six files.
    
    $zip = new createZip;
    
    $radius = c_float($_GET['radius']) + RAD_EARTH;
    $angle = c_float($_GET['inclination']) * M_PI / 180;
	$tempomax =  "RADIUS_UNSCALED = ".$radius."; ANGLE =".$angle."; TYPE = 0;";
	fwrite($fhandleradius, $tempomax);
    $sin_d = sin($angle);
    $cos_d = cos($angle);
    
    $time_period = 2 * M_PI * $radius * sqrt($radius / G_ME);
	fwrite($fhandleinput1, 5*$time_period);
    $f_equ .= "Radius from centre of earth, " . $radius . "\n";
    $f_equ .= "Inclination, " . $angle . "\n";
    $f_equ .= "Time period, " . $time_period. "\n";
    
    array_concat($f, "Time, Flux\n");
    
    $omega = 2 * M_PI / $time_period;
    
    for ($i = 0; $i < 1000; $i++) {
        $shadow = 1;
        $time = $time_period * $i / 200;
		$tempomax = $time."\n";
        fwrite($fhandle0, $tempomax);
        fwrite($fhandle1, $tempomax);
        fwrite($fhandle2, $tempomax);
        fwrite($fhandle3, $tempomax);
        fwrite($fhandle4, $tempomax);
        fwrite($fhandle5, $tempomax);
        
		$tempomax = 180/3.14159 * $omega * $time."\n";
		fwrite($fhandle00, $tempomax);
        fwrite($fhandle11, $tempomax);
        fwrite($fhandle22, $tempomax);
        fwrite($fhandle33, $tempomax);
        fwrite($fhandle44, $tempomax);
        fwrite($fhandle55, $tempomax);
		$omega_t = $omega * $time;
        
        array_concat($f, $time . ", ");
        
        $x = $radius * sin($omega_t);
        $y = $radius * $sin_d * cos($omega_t);
        $z = $radius * $cos_d * cos($omega_t);
        
        if ($z < 0) {
            $p = ($x*$x) + ($y*$y);
            if ($p < 6400 * 6400) { // 6400 * 6400, perhaps more 'at-home' in constants.php?
                $shadow = 0;
            }
        }
        
        // assigning $shadow at the front of stack since self-respecting interpreters return zero
        // as soon as they encounter a zero in multiplication, rather than masochistically get on
        // with it. can't say if said criteria fits PHP.
        
        $t1 = $shadow * cos($omega_t) * $cos_d * SOLAR_FLUX;
        $t2 = (-$t1);
        $t3 = $shadow * (-sin($omega_t)) * $cos_d * SOLAR_FLUX;
        $t4 = (-$t3);
        $t5 = $shadow * $sin_d * SOLAR_FLUX;
        $t6 = (-$t5);
/*        
        $f[0] .= ($t1 < 0 ? "0" : $t1);
        $f[1] .= ($t2 < 0 ? "0" : $t2);
        $f[2] .= ($t3 < 0 ? "0" : $t3);
        $f[3] .= ($t4 < 0 ? "0" : $t4);
        $f[4] .= ($t5 < 0 ? "0" : $t5);
        $f[5] .= ($t6 < 0 ? "0" : $t6);
  */
        $f[0] .= ($t1 < 0 ? "0" : $t1);
		$tempomax = ($t1 < 0 ? "0" : $t1)."\n";
		fwrite($fhandle0, $tempomax);
		fwrite($fhandle00, $tempomax);
        $f[1] .= ($t2 < 0 ? "0" : $t2);
		$tempomax = ($t2 < 0 ? "0" : $t2)."\n";
		fwrite($fhandle1, $tempomax);
		fwrite($fhandle11, $tempomax);
        $f[2] .= ($t3 < 0 ? "0" : $t3);
		$tempomax = ($t3 < 0 ? "0" : $t3)."\n";
		fwrite($fhandle2, $tempomax);
		fwrite($fhandle22, $tempomax);
        $f[3] .= ($t4 < 0 ? "0" : $t4);
		$tempomax = ($t4 < 0 ? "0" : $t4)."\n";
		fwrite($fhandle3, $tempomax);
		fwrite($fhandle33, $tempomax);
        $f[4] .= ($t5 < 0 ? "0" : $t5);
		$tempomax = ($t5 < 0 ? "0" : $t5)."\n";
		fwrite($fhandle4, $tempomax);
		fwrite($fhandle44, $tempomax);
        $f[5] .= ($t6 < 0 ? "0" : $t6);
  		$tempomax = ($t6 < 0 ? "0" : $t6)."\n";
		fwrite($fhandle5, $tempomax);
		fwrite($fhandle55, $tempomax);
      
        array_concat($f, "\n");
    }
    $zip -> addFile($f_equ, "equatorial.csv");
    
    $zip -> addFile($f[0], "1.csv");
    $zip -> addFile($f[1], "2.csv");
    $zip -> addFile($f[2], "3.csv");
    $zip -> addFile($f[3], "4.csv");
    $zip -> addFile($f[4], "5.csv");
    $zip -> addFile($f[5], "6.csv");
    
	fclose($fhandle0);
	fclose($fhandle1);
	fclose($fhandle2);
	fclose($fhandle3);
	fclose($fhandle4);
	fclose($fhandle5);
	fclose($fhandle00);
	fclose($fhandle11);
	fclose($fhandle22);
	fclose($fhandle33);
	fclose($fhandle44);
	fclose($fhandle55);
	fclose($fhandleinput1);
	fclose($fhandleradius);
	
    $zipped_data = $zip -> getZippedFile();
if ($_GET["DoWhat"] == 1) {
    header("Content-Type: application/zip");
    header("Content-Disposition: attachment; filename=data.zip;" );
    header("Content-Transfer-Encoding: binary");
    header("Content-Length: ".strlen($zipped_data));
    echo $zipped_data;
	}
	else {
		header( 'Location: plot1.php');
	}
?>
