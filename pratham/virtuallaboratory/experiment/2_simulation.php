<?php require_once("2_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr><td>
<div id="page">

<span class="OTitle">Simulation</span>

<p style="text-align:justify;" class="Textz"><b>Sun Vector</b><br />
Sun vector is the direction of sun with respect to the frame in question. Here
we show the time evolution of the sun vector in inertial frame and orbit frame.
Sun vector in inertial frame remains almost constant which is obtained from
sun model. User can provide the orbit parameters which will define the orbit
frame. Using frame transformation law given by equation (1), sun vector can
be plotted in orbit frame.</p>

<p style="text-align:justify;" class="Textz"><b>Magnetic field vector:</b><br />
Earth magnetic field at orbit position is sensed using three-axis magnetometer.
In simulation we use International Geomagnetic Reference Field (IGRF - http:
//www.geomag.bgs.ac.uk/data_service/models_compass/igrf.html) model
to find magnetic field of the earth in inertial frame. This can again be converted
in orbit frame using same transformation.</p>



    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>