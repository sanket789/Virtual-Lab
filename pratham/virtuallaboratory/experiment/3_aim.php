<?php require_once("3_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
      <tr>
        <td>&nbsp;</td>
      </tr>
      <tr><td>
<div id="page">
<span class="OTitle" style="font-size: 14pt">Heat Transfer</span><br><br>
<span class="OTitle">Aim</span>

<p style="text-align:justify;" class="Textz">To understand the basic concepts of conduction and radiation as used in satellites.</p>

<span class="OTitle">What is heat transfer?</span>
<p style="text-align:justify;" class="Textz">Heat transfer (or heat) is the exchange of thermal energy in transit due to spatial temperature difference. Whenever there exists a temperature difference in a medium or between media, heat transfer must occur.<br>Modes of heat transfer:</p>
<ul style="text-align:justify;" class="Textz">
    <li>Conduction</li>
    <li>Radiation</li>
    <li>Convection</li>
</ul><figure>
  <img src="images\heat.jpg">
  <figcaption>Fig1. - Heat Transfer</figcaption>
</figure>
<span class="OTitle">Radiation</span>
<p style="text-align:justify;" class="Textz">The process of transmitting or emitting the thermal energy through waves or particles through material medium is known as radiation. The amount of heat energy transmitted is given by <i> Stefan-Boltzmann law</i>.</p>


<p style="text-align:center;" class="Textz">E<sub>b</sub> = σT<sub>s</sub> <sup>4</sup></p>

<p style="text-align:justify;" class="Textz">
Where, T<sub>s</sub> is the absolute temperature (K) of the surface and σ is the Stefan–Boltzmann constant (σ = 5.67 x 108 W/m<sup>2</sup>.K<sup>4</sup>). Such a surface is called an ideal radiator or blackbody.</p>

<p style="text-align:center;" class="Textz">E<sub>b</sub> = ЄσT<sub>s</sub> <sup>4</sup></p>

<p style="text-align:justify;" class="Textz">
Where Є is a radiative property of the surface termed the emissivity. With values in the range 0 ≤ Є ≤ 1, this property provides a measure of how efficiently a surface emits energy relative to a blackbody. </p>

<span class="OTitle" style="font-size:10pt ">Shape factor</span>
<p style="text-align:justify;" class="Textz">Shape factor of an object A with respect to another object B is defined as the proportion of radiant energy emitted by object A to that of the radiant energy imparted on object B.</p>

<p style="text-align:center;" class="Textz">F<sub>A-B</sub> = shape factor of A w.r.t to B</p>

<span class="OTitle">Conduction</span>
<p style="text-align:justify;" class="Textz">The process of transfer of thermal energy by the collision of microscopic molecules is known as conduction. The amount of heat energy transmitted by conduction is given by <i>Fourier’s law of heat conduction</i>. Fourier’s law of heat conduction is valid through solids, liquid and gasses.</p>

<p style="text-align:center;" class="Textz">Q = -k.A.(dT/dx)</p>

<p style="text-align:justify;" class="Textz">Where,<br>
‘Q’ is the heat flow rate by conduction (W) <br>
‘k’ is the thermal conductivity of body material (W·m<sup>−1</sup>·K<sup>−1</sup>)<br> 
‘A’ is the cross-sectional area normal to direction of heat flow (m<sup>2</sup>) and<br>
‘dT/dx’ is the temperature gradient (K·m<sup>−1</sup>).
</p>

<span class="OTitle" style="font-size:10pt ">Thermal Resistance</span>
<p style="text-align:justify;" class="Textz">Analogous to electrical resistance, thermal resistance can be defined as the ratio of temperature difference to the amount of heat conductive heat flow.</p>

<p style="text-align:center;" class="Textz">Thermal resistance = ⧍T/Q = L/kA</p>

<span class="OTitle" style="font-size:10pt ">Heat Equation</span>

<p style="text-align:center;" class="Textz">(∂^2 T)/(∂x^2 )+(∂^2 T)/(∂y^2 )+(∂^2 T)/(∂z^2 )+q ̇/k=1/α   ∂T/∂t</p>

<p style="text-align:justify;" class="Textz">Where,<br>
α = k/ρCp is the thermal diffusivity, <br>
q' = rate of internal heat generation,<br>
This equation can be used for finding the temperature profile in 3 dimensions.
</p>

    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>