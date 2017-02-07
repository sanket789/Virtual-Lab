<?php require_once("2_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr><td>
<div id="page">
<span class="OTitle" style="font-size: 14pt">Reference Frames and Transformations</span><br><br>
<span class="OTitle">Aim</span>

<p style="text-align:justify;" class="Textz">To analyze the transformation of sun-vector and magnetic field vector in different reference frames.</p>

<span class="OTitle">Introduction</span>
<p style="text-align:justify;" class="Textz">The motion of rigid body is specified using its position, velocity, acceleration etc.
These vector quantities are specified in some frame of reference. Thus equations
of motion are also written with respect to that frame. As you might know, the
same motion can be analyzed with respect to different frames of reference. The
use of different frames simplifies understanding of motion. Sometimes it eases
calculations and helps in visualizing various aspects of motion. In order to go
from one frame to another frame we have to transform corresponding vectors
using transformation law.<br>
The satellite dynamics can also be studied in different frames.In this experiment
different frames associated with satellite motion will be explained.</p>

<ul style="text-align:justify;" class="Textz">
<li>ECIF(Earth Centered Inertial Frame)</li>
<li>Orbit frame</li>
<li>Body frame</li>
</ul>
<p style="text-align:justify;" class="Textz">After that linear transformation from ECIF to orbit frame will be discussed. In
last part of the experiment, simulation for sun vector and magnetic field vector
transformation will be provided.</p>
<span class="OTitle">ECIF (Earth Centered Inertial Frame)</span>
<p style="text-align:justify;" class="Textz">ECI frame has its origin at the center of mass of the earth. Axes of ECI frame
are as follows:</p>
<ul style="text-align:justify;" class="Textz">
<li><b>X → First point of Aries:</b> On the day of March equinox(equal day
equal night) i.e. 21st of March, sun is in this constellation, observed from
the earth. This direction is vernal equinox which point toward first point
of Aries. This direction remains constant as the earth revolves around the
sun.</li>
<li><b>Z </b>→ Axis of rotation of earth with positive direction along north pole</li>
<li><b>Y → Z × X</b></li></ul>
<p style="text-align:justify;" class="Textz">
Since the center of mass of earth is itself accelerating around the sun, ECI frame
is not exactly inertial frame. But for specifying the orbital motion of satellite
it is assumed to be inertial without any adverse effect.</p>
<figure>
  <img src="ecif.png" alt="ECIF" width="304" height="228">
  <figcaption>Fig1. - ECIF Co-ordinates.</figcaption>
</figure>

<span class="OTitle">Orbit Frame</span>
<p style="text-align:justify;" class="Textz">Orbit frame is the frame revolving around earth along with satellite. This frame
is non-inertial frame of reference since its accelerating with respect to inertial
frame. Its is centered at center of mass of the satellite. Axes of orbit frame are
defined as:</p>
<ul style="text-align:justify;" class="Textz">
<li><b>X </b>→ In the plane of orbit along the velocity direction</li>
<li><b>Z </b>→ Towards earth center</li>
<li><b>Y → Z × X</b></li></ul>
<span class="OTitle">Body Frame</span>
<p style="text-align:justify;" class="Textz">Body frame is the frame attached to the satellite itself. This frame translates
and rotates along with the satellite. The satellite is stationary with respect to
body frame. In special case, its axes are aligned with principal body axes of
satellite. The goal of control is to orient the satellite body frame with respect
to orbit frame in desired manner. In case of Pratham, goal of controller is to
align body frame with orbit frame.
These three frames can be visualized as shown in the following figure:
<figure>
  <img src="allFrames" alt="allFrames" width="304" height="228">
  <figcaption>Fig2. - I: ECIF, R: Orbit frame, B:Body frame.</figcaption>
</figure>
    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>