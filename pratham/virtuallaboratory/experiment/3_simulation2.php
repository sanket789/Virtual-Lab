<?php require_once("3_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr><td>
<div id="page">


<span class="OTitle">Input the dimensions and initial temperature of the plates.</span>

<center><figure>
  <img src="images\exp3.png">
  <figcaption>Fig1.</figcaption>
</figure></center>


<form id="form1">


<table border="0" align="center" style="text-align:left">

    <tr>
    <td class="Textz">X (in meters):</td>
    <td class="Textz"><input name="X" value="0" type="number" max="100" /></td>
    </tr>

    <tr>
    <td class="Textz">Y (in meters):</td>
    <td class="Textz"><input name="Y" value="0" type="number" max="100" /></td>
    </tr>

	<tr>
    <td class="Textz">Z (in meters):</td>
    <td class="Textz"><input name="Z" value="0" type="number" max="100" /></td>
    </tr>

    <tr>
    <td class="Textz">T<sub>1</sub> (Temp. of plate 1 in Kelvin):</td>
    <td class="Textz"><input name="T1" value="0" type="number" max="100" /></td>
    </tr>

    <tr>
    <td class="Textz">T<sub>2</sub> (Temp. of plate 1 in Kelvin):</td>
    <td class="Textz"><input name="T2" value="0" type="number" max="100" /></td>
    </tr>

    </table><br />

    <div style="text-align:center">
    <input type="button" value="Submit" onclick="prop()" />
  	<input type="reset"></div>

</form>

<p id="sol1"></p>
<p id="sol2"></p>

<script type="text/javascript" >
		
	function prop(){
		var x = document.getElementById("form1");
    
    	var X = (+x[0].value);
    	var Y = (+x[1].value);
    	var Z = (+x[2].value);
    	var T1 = (+x[3].value);
    	var T2 = (+x[4].value);
    	var H = Z/X;
    	var W = Y/X;
    	var d = ((H*H)+(W*W));
    	var a = Math.pow([(W*W)*(1+d)/((1+W*W)*d)],(W*W));
    	var b = Math.pow([(H*H)*(1+d)/((1+H*H)*d)],(H*H));
    	var c= "Shape Factor:  ";
    	var e= "Rate of Heat Flow: "

    	var F12 = (1/(Math.PI*W))*[(W*Math.atan(1/W))+(H*Math.atan(1/H))-(Math.sqrt(d)*Math.atan(1/(Math.sqrt(d))))+(1/4)*Math.log([(1+(W*W))*(1+(H*H))*a*b]/(1+(d)))];

    	var q = .00000005670367*F12*X*Z*[(Math.pow(T1,4))-(Math.pow(T2,4))];

		document.getElementById("sol1").innerHTML = c + F12;
		document.getElementById("sol2").innerHTML = e + q;
	}

    </script>




    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>