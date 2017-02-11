<?php require_once("1_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr><td>
<div id="page">
<span class="OTitle" style="font-size: 14pt">Proportional Controller</span><br><br>

<span class="OTitle">Aim</span>

<p style="text-align:justify;" class="Textz">To drive the angular rates to zero by applying a proportional controller torque.</p>

<span class="OTitle">Introduction</span>
<p style="text-align:justify;" class="Textz">When satellite is ejected from launch vehicle, it may have high angular velocities
(also called as angular rates) about its axes. The satellite is required to point
in specific direction for proper functioning(refer the section: Requirement of
control).
The angular motion of satellite in body frame is governed by equation</p>
<img src="images/1.png" align="center" alt=
"IW=tau" height="30" width="80">
<p style="text-align:justify;" class="Textz">
Where I is moment of inertia matrix in body frame and <img src="images/tau.png" align="center" alt="IW=tau" height="15" width="15"> is torque acting on
the body. So as equation suggests, to change the angular velocity of satellite,
torque has to be applied on it. In space environment there are external torques
acting on the satellite. But the main source of the torque is the control torque
applied by actuators of the satellite. This experiment will describe the control
on angular rates using proportional controller. Note that, in this experiment
external torques are neglected for simplicity.</p>
<span class="OTitle">Requirement of Control</span>
<p style="text-align:justify;" class="Textz">Generally, from different requirements (as elaborated below), it is needed that
the satellite should point in a specified direction. Thus if we consider frame definitions according to previous experiment, Euler angles (https://en.wikipedia.
org/wiki/Euler_angles)between orbit frame and body frame should be zero .
This requirement generally arises due to following reasons:
<ul style="text-align:justify;" class="Textz">
<li><b>Communication:</b> Satellite sends and receives the data in form of electromagnetic waves from ground stations on the earth. This communication
can be effective only if antenna and other communication devices on satellite are oriented properly.</li>
<li><b>Payload:</b> Some satellite payloads like optical payload,cameras and remote
sensing devices might require accurate point to receive and collect the
data.</li>
<li><b>Power:</b> To generate the power solar panels has to face sun for sufficient
amount of time.</li>
</ul></p>
<p style="text-align:justify;" class="Textz">
Thus in order to orient the satellite we have to first determine the current orientation of the satellite and bring it to desired orientation with respect to reference frame.
Attitude determination is the process of determining the current orientation of the satellite using sensor data. Control is the process in which control law is executed and actuators modify the satellite orientation accordingly.</p>
<p style="text-align:justify;" class="Textz">
In this experiment we will simulate simplified situation. Instead of stabilizing to desired orientation, we first stabilize the angular rates. In this case we don't bother about the final orientation. It is assumed that satellite is  launched with higher angular rates. The desired value for angular rates is zero. Thus torque is applied accordingly. This simulation uses proportional controller to stabilize angular rates.
</p>

<span class="OTitle">Detumbling and Nominal Mode</span>
<p style="text-align:justify;" class="Textz">
Generally there are two modes in satellites: Detumbling and Nominal.
 Detumbling is the process of stabilizing the angular rate of the satellite after orbital insertion. In detumbling mode, initial rates may be very high as the satellite is ejected from the launch vehicle. In this mode sensors like GPS are not available due to power constraints. Thus attitude of satellite is not known. So to bring down initial angular rates we have to use some coarse controller. In the case Pratham, only magnetometer is ON during detumbling. Using rate of change of magnetic field vector in body frame, we can estimate angular rates. Then proportional controller is applied to bring down the angular rates. This control algorithm is called as B-dot algorithm. If rates are below certain threshold for some time window then control is switched to nominal mode. </p>
 <p style="text-align:justify;" class="Textz">
In nominal mode, rates are low. We use PID controller to determine the attitude of the satellite and stabilize the Euler angles within required limits. The nominal controller is a fine controller.</p>

    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>