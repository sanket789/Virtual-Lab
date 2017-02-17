<?php require_once("header.php"); ?>
<script type="text/javascript">
function checkError(thisform)
{
	if(thisform.radius.value<0 || thisform.radius.value>50000)
	{
		alert("Orbit limits is 0km to 50000 kms");
		return false;
	}
	if(thisform.inclination.value<-90 || thisform.inclination.value>90)
	{
		alert("Inclination limits is -90 to 90 degrees");
		return false;
	}
}
</script>
<table width="800" border="0" cellspacing="0" cellpadding="0" align="center" bgcolor="#FFFFFF">
  <tr><td><table width="770" border="0" cellspacing="0" cellpadding="0" align="center">
  	<tr><td>&nbsp;</td>
  	</tr>
    <tr><td class="OTitle">Thermals Experiment for Equatorial Orbit</td>
    </tr>
    <tr><td>&nbsp;</td></tr>
   <!-- <tr><td class="Textz">When the Satellite is traveling along the Equator of the Earth, it called an Equatorial Orbit. The angle made by the plane of the orbit with the plane of the Equator is called the angle of inclination. Usually Equatorial Orbits have low inclination, about 10deg to 30deg.<br /><br />

Most of the Satellites are launched in Low Earth Orbit, with altitudes within 400km to 1500km. The Geostationary Earth Orbits (GEO) is a special case of Equatorial Orbits since they are always placed at 0deg inclination and at the particular distance of 36000km. This is because the time period of this Satellite is same as that of Earth’s rotation; hence this Satellite remains stationary in the sky. These Satellites are used extensively for communication purposes.</td>
    </tr>-->
    <tr><td>&nbsp;</td></tr>
    <tr>
      <td align="center"><div align="center"><span class="Textz">Geosynchronous Orbit:</span><br /><img src="images/geo.gif" alt="Image 6" /></div></td>
    </tr>
    <tr><td><br /><br /><hr><br /><br /></td></tr>
    <tr>
    <tr><td class="OTitle">To Set up an Experiment Choose An Orbit</td>
    </tr>
      <td><form name="experiment" id="experiment" action="equatorial.php" method="get" onsubmit="return checkError(experiment);">

	<input type="hidden" name="orbit" value="Equitorial" />

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

	<!--	<td class="Textz"><input type="Radio" name="DoWhat" value="1" CHECKED /> Get Values</td>

		<td class="Textz"><input type="Radio" name="DoWhat" value="2" /> Show Graph</td>-->

    </table>
	<br />
    <div style="text-align:center">

    <input type="image" src="images/submit.gif" value="Submit" id="submit" /></div>

</form></td>
    </tr>
    <tr>
      <td>&nbsp;</td>
    </tr>
    <tr>
      <td>&nbsp;</td>
    </tr>
</table>
</td></table>
<?php require_once("footer.php");?>
