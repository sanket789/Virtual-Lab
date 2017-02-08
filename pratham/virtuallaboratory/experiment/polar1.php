<?php require_once("header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr><td>
<div id="page">

<span class="OTitle">Thermals Experiment for Polar Orbit</span>

<p style="text-align:justify;" class="Textz">The orbits at go around the Earth’s Poles are called Polar Orbit. The Polar Sunsynchoronous Orbit is a special class of Polar Orbit, where the Satellite always passes over any region on Earth at the same local time. Hence defining the local time, will define the entire orbit for this Satellite. These orbits are used extensively by spy Satellites. Most of the Satellites are launched in Low Earth Orbit, with altitudes within 400km to 1500km.</p>

<div align="center"><!--<span  class="Textz">Polar Orbit </span><br />-->

    <img src="images/image7.jpg" alt="Image 7" />

</div>

<hr>

<span class="OTitle">To Set up an Experiment Choose An Orbit</span>

<form action="polar.php" method="get">

	<input type="hidden" name="orbit" value="Polar" />

<table border="0" align="center" style="text-align:left">

    <tr>

    <td class="Textz">Altitude(In Kms)</td>

    <td class="Textz"><input name="radius" value="0" type="text" /></td>

    </tr>

    <tr>

    <td class="Textz">Inclination (In degrees)</td>

    <td class="Textz"><input name="inclination" value="0" type="text" /></td>

    </tr>

	<tr>

		<td class="Textz"><input type="Radio" name="DoWhat" value="1" CHECKED /> Get Values</td>

		<td class="Textz"><input type="Radio" name="DoWhat" value="2" /> Show Graph</td>

    </table><br />

    <div style="text-align:center">

    <input type="submit" value="Submit" id="submit" /></div>

</form>

    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>