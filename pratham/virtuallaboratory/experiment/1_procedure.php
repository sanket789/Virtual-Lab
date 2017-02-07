<?php require_once("1_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
      <tr>
        <td>&nbsp;</td>
      </tr>
      <tr><td>
<div id="page">

<span class="OTitle">Procedure</span>
<p style="text-align:justify;" class="Textz">In proportional controller, controller output is proportional to the difference between reference value and current value of the variable. This term is also called as the error signal.
In this case $\omega_{ref} = 0$ is desired (reference) value of angular rates. Thus at each step error term in angular rates i.e. &E = &omega - &omega_{ref} will be calculated. Then output of controller will be $K_P \times E$. This control torque will then drive the angular rates accordingly. 
</p>
<p style="text-align:justify;" class="Textz">In this experiment, simple proportional controlled is applied to reduce the angular rates of the satellite. </p>

</div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>


