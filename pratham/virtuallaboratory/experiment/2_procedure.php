<?php require_once("2_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
      <tr>
        <td>&nbsp;</td>
      </tr>
      <tr><td>
<div id="page">

<span class="OTitle">Procedure</span>
<p style="text-align:justify;" class="Textz">In satellite, there are different types of sensors to measure the external environmental parameters. In satellite Pratham there are three sensors: Magnetometer
(to measure earth’s magnetic field), Sun sensor (to get the direction of sun with
respect to satellite) and GPS. These sensors give some voltages as their output as result of the measurement. We can interpret these voltages as vector
quantities. For purpose of computation, it might be required to transform these
vectors in different frames.<br><br>

Following procedure can be applied to perform co-ordinate transformation.</p>
<span class="OTitle">Vector measurements in different frames</span>
<p style="text-align:justify;" class="Textz">
From the definition of frames given in the previous section, transformation matrix between inertial and
orbit frame can be easily found as follows:<br>
Let <img src="images/vi.png" align="center" alt="v_i" height="20" width="20"> be the vector in inertial frame and <img src="images/vr.png" align="center" alt="v_r" height="20" width="20"> be the same vector in orbit frame.Then<br>
<img src="images/vmv.png" align="center" alt="v_i =m*v_r" height="20" width="100"><br>
where M<sub>IR</sub> is the transformation matrix from orbit frame to inertial frame.
Transformation matrix transforms one frame into another. If m<sub>ij</sub> are components of this matrix, then m<sub>ij</sub> is cosine of the angle between i<sup>th</sup> axis of second frame and j<sup>th</sup> axis of initial frame. These components are also known as direction cosines. Now assume that position <bar>r</bar> and velocity <bar>v</bar> of satellite in inertial frame is known. Then using definition of orbit frame we can find images of its
basis vectors in transformed frame. This means X<sub>R</sub> → a, Y<sub>R</sub> → b, Z<sub>R</sub> → c. We know from linear algebra that columns of transformation matrix are the images of basis vectors in transformed frame. Thus</p>
<img src="images/formula.png" align="center" alt=
"IW=tau" height="200" width="410">
<p style="text-align:justify;" class="Textz">
Inverse transformation is also easy, since rotation matrices being orthogonal,
satisfy M<sub>RI</sub> = M<sub>IR</sub> −1 = M<sub>IR</sub> <sup>T</sup> .</p>


</div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>


