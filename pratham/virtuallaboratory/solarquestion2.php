<?php require_once("header.php"); ?>
    <table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr>
  		  <td class="OTitle">Solar Radiation</td>
		  </tr>
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><div align="justify">This tutorial gives an introduction for computing solar radiation incident on a satellite. To begin with let us consider a satellite that is a cuboid in shape and has six sides.  Total solar radiation incident on the satellite will depend on location of the satellite with respect to Earth & Sun.  It will also depend on its attitude, ie the angular orientation it has for its 6 sides with respect to the Sun.    This tutorial will help you understand this dependency in a step-by-step manner.</div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><div align="justify">Since the sun is very far from the earth, its rays can be considered to be parallel.  Solar radiation incident on unit area is designated as flux and is measured in Watts/m<sub>2</sub> (or W/m<sub>2</sub> in short).  We will begin by understanding flux incident on 1m<sub>2</sub> area that is normal to solar radiation.</div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><div align="justify">Q1) What do you think is the solar radiation falling on 1m<sub>2</sub> plate kept normal to the radiation at the surface of the earth?  Can you indicate the order of magnitude?</div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="596" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td width="193">(a)
                <input type="radio" name="option1" value="a" disabled="disabled"/>
&nbsp; 10 W/m<sub>2</sub><br />
(b)
<input type="radio" name="option1" value="b" disabled="disabled"/>
&nbsp; 100 W/m<sub>2</sub><br />
(c)
<input type="radio" name="option1" value="c" disabled="disabled"/>
&nbsp; 1000 W/m<sub>2</sub><br />
(d)
<input type="radio" name="option1" value="d" disabled="disabled"/>
&nbsp; 10000 W/m<sub>2</sub></td>
              <td width="403"><table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td><center>
              Answer = 1000 W/m<sup>2</sup></center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table> </td>
            </tr>
            
            <tr>
              <td>&nbsp;</td>
              <td>&nbsp;</td>
            </tr>
            
          </table></td>
		  </tr>
  		
  		<tr>
  		  <td class="Textz" ><table width="716" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td background="images/animation_no.gif" width="231" height="200" >&nbsp;</td>
    <td width="485"><table width="400" border="0" align="center" cellpadding="0" cellspacing="0">
      <tr>
        <td><img src="images/lt.gif" width="23" height="19" /></td>
        <td background="images/top.gif" height="19" ></td>
        <td><img src="images/rt.gif" width="25" height="19" /></td>
      </tr>
      <tr>
        <td background="images/left.gif" width="23"></td>
        <td><p>A plate of unit area normal to incident rays and at Earth’s  surface receives 1000 W/m<sup>2</sup></p></td>
        <td background="images/right.gif" width="25"></td>
      </tr>
      <tr>
      
        <td><img src="images/lb.gif" width="23" height="19" /></td>
        <td background="images/bottom.gif" height="19" ></td>
        <td><img src="images/rb.gif" width="25" height="19" /></td>
      </tr>
    </table></td>
  </tr>
</table></td>
		  </tr>
  		<tr>
  		  <td class="Textz"><div align="justify">A body at a finite temperature emits electromagnetic radiation. Higher the temperature more the radiation it emits.  The temperature of the sun is approximately 5700 K. Thus the sun emits a large amount of electromagnetic radiation which can be computed using the Stefan-Boltzmann law [3]. Most of sun's energy flows out of our solar system without colliding with anything. However a very small fraction of that energy does get intercepted by the Earth. If the earth were closer to the sun say at half the distance, the energy that the Earth would receive would be four times. This relationship is called the inverse square law of radiation. Just outside the Earth's atmosphere (extraterrestrial irradiance) about 1350 W/m<sub>2</sub> is received from the sun [1]. But at the surface of the Earth this is about 1000 W/m<sub>2</sub> since only approximately 75 % of the radiation penetrates through the Earth's atmosphere.</div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="OTitle">References</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><span class="empty">&nbsp;</span></td>
		  </tr>
  		<tr>
  		  <td class="Textz"><p>[1] http://solardat.uoregon.edu/SolarRadiationBasics.html<br />
  		    [2] http://en.wikipedia.org/wiki/Solar_radiation#Solar_constant<br />
  		    [3] http://en.wikipedia.org/wiki/Stefan-Boltzmann_law<br />
  		    [4] http://www.windows.ucar.edu/tour/link=/earth/climate/sun_radiation_at_earth.html<br />
  		    [5] &quot;Chapter 8 – Measurement of sunshine  duration&quot; (PDF). CIMO Guide. World Meteorological Organization. <br />
  		    http://www.wmo.int/pages/prog/www/IMOP/publications/CIMO-Guide/
	      CIMO Guide 7th Edition, 2008/Part I/Chapter 8.pdf</p></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><p align="justify">Q2) Now assume the  plate is kept at an angle of 60<sup>o</sup> to the incident  radiation. Ie. The  normal to the plate makes an angle 60<sup>o</sup> with the  incident radiation.  What is the solar radiation falling on  the plate? The plate is on the surface of the earth.</p></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="570" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td width="166"><form name="quest2" id="quest2">(a)
                <input type="radio" name="option1" value="a"  />
&nbsp; 300 W/m<sub>2</sub><br />
(b)
<input type="radio" name="option1" value="b"  />
&nbsp; 500 W/m<sub>2</sub><br />
(c)
<input type="radio" name="option1" value="c"  />
&nbsp; 800 W/m<sub>2</sub><br />
(d)
<input type="radio" name="option1" value="d"  />
&nbsp; 1000 W/m<sub>2</sub></form></td>
              <td width="404"><div id="DivMessage" align="center"></div></td>
            </tr>
            <tr>
              <td align="center"><img src="images/submit.gif" onclick="question2(quest2)" title="Submit Your Answer"/></td>
              <td>&nbsp;</td>
            </tr>
          </table></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
          <tr>
  		  <td class="Textz"><div id="DivExplain"></div></td></tr>
  		 <tr><td align="right" class="Textz"><div id="DivNext" style="visibility:hidden">
  		    <span class="menutoplink"><a href="solarquestion2.php" class="menutoplink">Next </a></span><a href="solarquestion2.php" class="menutoplink">&nbsp;</a> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</div></td></tr>
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
		</table>
		</td>
      </tr>
    </table>
<?php require_once("footer.php");?>