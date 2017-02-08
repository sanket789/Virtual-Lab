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
<p style="text-align:justify;" class="Textz">In satellite, there are different types of sensors to measure the external environ-mental parameters. In satellite Pratham there are three sensors: Magnetometer
(to measure earth’s magnetic field), Sun sensor (to get the direction of sun with
respect to satellite) and GPS. These sensors give some voltages as their output as result of the measurement. We can interpret these voltages as vector
quantities. For purpose of computation, it might be required to transform these
vectors in different frames.<br><br>

Following procedure can be applied to perform co-ordinate transformation.</p>
<span class="OTitle">Vector measurements in different frames</span>
<p style="text-align:justify;" class="Textz">
From the definition of frames given in the previous section, transformation matrix between inertial and
orbit frame can be easily found as follows:.
Let V I be the vector in inertial frame and V R be the same vector in orbit frame.Then
V I = M IR V R
where M IR is the transformation matrix from orbit frame to inertial frame.
Transformation matrix transforms one frame into another. If m ij are compo-
nents of this matrix, then m ij is cosine of the angle between i th axis of second
frame and j th axis of initial frame. These components are also known as direc-
tion cosines. Now assume that position r and velocity v of satellite in inertial
frame is known. Then using definition of orbit frame we can find images of its
basis vectors in transformed frame. This means X R → a, Y R → b, Z R → c. We
know from linear algebra that columns of transformation matrix are the images
of basis vectors in transformed frame. Thus


a 1 b 1 c 1
M IR = [ a b c ] ≡  a 2 b 2 c 2 
(1)
a 3 b 3 c 3
where
a =
v
|v|
(2)
r
v
×
|r| |v|
r
c = −
|r|
b = −
(3)
(4)
(5)
Inverse transformation is also easy, since rotation matrices being orthogonal,
satisfy M RI = M IR −1 = M IR T .</p>


</div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>


