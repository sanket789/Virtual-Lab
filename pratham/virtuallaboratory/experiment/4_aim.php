<?php require_once("4_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr><td>
<div id="page">
<span class="OTitle" style="font-size: 14pt">Doppler Shift in Signal Frequency</span><br><br>

<span class="OTitle">Aim</span>

<p style="text-align:justify;" class="Textz">To calculate the Doppler frequency for elevation angles varying from 0 to 90 degrees. </p>

<span class="OTitle">Introduction</span>
<p style="text-align:justify;" class="Textz">In classical physics, it has been observed that when a signal wave is generated
from a source which has a relative motion with the observer then there is a
change in wavelength or frequency of the signal wave.
The above can be well related to a scene where you are standing along the
roadside and a speeding car passes in front of you. When the car is moving towards you, you can easily figure out an increase in frequency making it highly pitched and as it goes away from you, the observed frequency is reduced.</p>
<figure>
  <img src="images/police.png" alt="Doppler effect" width="325" height="200">
  <figcaption>Fig1. - Doppler effect of a passing by Police car</figcaption>
</figure>
<span class="OTitle">Classical Doppler Effect</span>
<p style="text-align:justify;" class="Textz">
As we have seen that the relative motion of the source and observer is the fundamental cause for the change in wavelength and hence the frequency of the original signal wave generated from the source. When the relative distance between the source and the observer decreases, each successive wave crest is transmitted from the position which is more closer to the observer. Hence, the time between the arrival of successive wave crests at the observer is reduced, causing an decrease in the wavelength ad increase in the frequency. This particularly can happen when the source is moving towards the observer or the observer is moving towards from the source.</p>
<figure>
  <img src="images/signal.png" alt="Relative motion of signal" width="400" height="150">
  <figcaption>Fig2. - Fundamental effect of relative motion on signal generated</figcaption>
</figure>
<p style="text-align:justify;" class="Textz">
Similarly, when the relative distance between the source ans the observer
increases, each wave is emitted from a position farther from the observer than
the previous wave. So the arrival time between successive waves is increased,
increasing the wavelength and reducing the frequency. This can be the case
when the source is moving away from the observer or the observer is moving
away from the source.</p>
<figure>
  <img src="images/distance.png" alt="Distance approach " width="500" height="280">
  <figcaption>Fig3. - Distance approach of Doppler effect</figcaption>
</figure>
<span class="OTitle">Doppler Effect Formulation</span>
<p style="text-align:justify;" class="Textz">The above observations can be deduced into simple formulations using the
wavelength and frequency relation. The formula for Doppler effect is as
follows-<br></p>
<img src="images/dop.png" align="center" alt=
"IW=tau" height="60" width="150">
<p style="text-align:justify;" class="Textz">
where,<br>
f = Original frequency emitted by the source<br>

f’ = Frequency (after Doppler shift) observed by the observer<br>
v = Velocity of wave in the medium<br>
vr = Velocity of receiver relative to the medium; positive if the receiver is moving towards the source (and negative in the other direction)<br>
vs = Velocity of source relative to the medium; positive if the source is moving away from the receiver (and negative in the other direction)<br>
If the speeds vs and vs are small compared to the speed of the wave, the
relationship observed between observed frequency f’ and emitted frequency
f is approximately -<br>
<b>Observed Frequency:</b><br></p>
<img src="images/obs.png" align="center" alt=
"IW=tau" height="50" width="150">
<p style="text-align:justify;" class="Textz">
<b>Change in Frequency:</b><br></p>
<img src="images/change.png" align="center" alt=
"IW=tau" height="50" width="150">
<p style="text-align:justify;" class="Textz">
where,</p>
<img src="images/del.png" align="center" alt=
"IW=tau" height="50" width="150">
<p style="text-align:justify;" class="Textz">
∆v is the velocity of the receiver relative to the source; it is positive when the source and the receiver are moving towards each other.</p>	


    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>