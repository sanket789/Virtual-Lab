<?php require_once("experiment/header.php"); ?>
<table width="800" border="0" cellspacing="0" cellpadding="0" align="center" bgcolor="#FFFFFF">
  <tr><td><table width="770" border="0" cellspacing="0" cellpadding="0" align="center">
  	    <tr><td>&nbsp;</td></tr>
        <tr><td class="OTitle">Procedure</td>
        </tr>
        <tr><td>&nbsp;</td></tr>
        <tr><td><ul>
              <li class="Textz">With this background knowledge, now you should  be able to understand the simulation results in a better fashion</li><br />
              <li class="Textz">The code can compute temperatures for a cube  satellite whose dimensions can be increased in steps of 5 cms upto 30 cms only.  A typical cube satellite is a cube of 10cm</li><br />
              <li class="Textz">Enter orbital parameters: These are required to  determine the orbit of the satellite. Once the orbit is known, we know the  solar radiation density incident on the 6 faces of the satellite as a function  of time. For specifying  the orbit, you  need to specify whether the orbit is polar/equatorial, the altitude of the  orbit from the surface of the earth and inclination of the orbit with respect  to the polar and equatorial plane respectively</li><br />
              <li class="Textz">Once the orbit is determined, you need to feed  in the geometric parameters which will define the geometry being simulated. As  mentioned earlier, the code is capable of computing temperatures for cube  satellites only. So here you would need to specify the length of the side and  also the thickness of the material used. The default values mentioned in the  textboxes are those of Pratham. In case of doubt do not change those values</li><br />
              <li class="Textz">After defining the geometric parameters, you  need to specify the material properties and the internal and external surface  properties which are required for computation of different loads like  conduction and radiation</li><br />
              <li class="Textz">The code can also take additional constant flux  density as an input. This is essentially for modeling the circuits which go on  board the satellite and dissipate heat. Typical values of heat dissipated for  small satellites are of the order of 1 W. It is assumed that this flux density  is uniformly applied on the face. The user can enter 6 such values, 1 for each  face. </li><br />
            </ul>
            </td></tr>
        <tr><td>&nbsp;</td></tr>
         <tr><td height="100">&nbsp;</td></tr>
</table>
</td></tr>
</table>
<?php require_once("footer.php");?>