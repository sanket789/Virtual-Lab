<?php require_once("experiment/header.php"); ?>
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
  		  <td class="Textz"><div align="justify">The sun radiates energy in all wavelengths and not just visible light. Amount of solar radiation incident on a satellite in orbit is important to know as that will decide how much the satellite will get heated. </div></td>
		  </tr>
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><div align="justify">To begin with let us consider a satellite that is a cuboid in shape and has six sides.  Total solar radiation incident on the satellite will depend on location of the satellite with respect to Earth & Sun.  It will also depend on its attitude, ie the angular orientation it has for its 6 sides with respect to the Sun. This tutorial will help you understand this dependency in a step-by-step manner.</div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
          
          <tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><div align="justify">Since the sun is very far from the earth, its rays can be considered to be parallel.  Solar radiation incident on unit area is designated as flux and is measured in Watts/m<sup>2</sup> (or W/m<sup>2</sup> in short).  We will begin by understanding flux incident on 1m<sup>2</sup> area that is normal to solar radiation.</div></td>
		  </tr>
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
          <!--<tr>
  		  <td class="OTitle">General Synchronous Orbits</td>
		  </tr>
          <tr>
  		  <td><table width="767" border="0" cellspacing="0" cellpadding="0">
            <tr>
               <td width="350"><img src="images/general1.gif" width="350" height="310" title="General Synchronous Orbits" /></td>
              <td width="352"><img src="images/general2.gif" width="350" height="330" title="General Synchronous Orbits" /></td>
            </tr>
          </table></td>
		  </tr>-->
         
          <!--<tr>
  		  <td class="OTitle">Specfic Sun Synchronous Orbits</td>
		  </tr>
          <tr>
  		  <td><span class="empty">&nbsp;</span></td>
		  </tr>  
          <tr>
  		  <td><table width="767" border="0" cellspacing="0" cellpadding="0">
            <tr>
               <td width="400"><!--<img src="images/12ampm1.gif" width="350" height="310" title="12AM/PM Orbit" />
               <div id="dropmsg0" class="dropcontent">
<img src="images/12ampm1.gif" width="350" height="310" title="12AM/PM Orbit" />
</div>

<div id="dropmsg1" class="dropcontent">
<img src="images/3ampm1.gif" width="350" height="310" title="3AM/PM Orbit" />
</div>

<div id="dropmsg2" class="dropcontent">
<img src="images/6ampm1.gif" width="350" height="310" title="6AM/PM Orbit" />
</div>

<div id="dropmsg3" class="dropcontent">
<img src="images/9ampm1.gif" width="350" height="310" title="9AM/PM Orbit" />
</div>
               </td>
              <td width="300"><!--<img src="images/12ampm2.gif" width="350" height="330" title="12AM/PM Orbit" />
              <form name="dropmsgform">
<select name="dropmsgoption" size="1" style="width:300" onChange="expandone()">
    <option selected>12AM/12PM Orbit</option>
    <option>3AM/3PM Orbit</option>
    <option>6AM/6PM Orbit</option>
    <option>9AM/9PM Orbit</option>
</select>
</form>
</td>
            </tr>
          </table></td>
		  </tr>-->
  		<tr>
  		  <td class="Textz"><div align="justify" class="Question">Q1) What do you think is the solar radiation falling on 1m<sup>2</sup> plate kept normal to the radiation at the surface of the earth?  Can you indicate the order of magnitude?</div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="570" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td width="170" height="100" valign="top"><form name="myform" class="Textz">
              (a)<input type="radio" name="option1" value="a"  />&nbsp; 10 W/m<sup>2</sup><br />
(b)<input type="radio" name="option1" value="b"  />&nbsp; 100 W/m<sup>2</sup><br />
(c)<input type="radio" name="option1" value="c"  />&nbsp; 1000 W/m<sup>2</sup><br />
(d)<input type="radio" name="option1" value="d"  />&nbsp; 10000 W/m<sup>2</sup>
              </form></td>
              <td width="400"><div id="DivMessage"></div></td>
              <!--<td width="393" valign="middle"><div id="DivMessage" align="center"></div></td>-->
            </tr>
            <tr>
              <td align="center"><div id="DivButton"><img src="images/submit.gif" onclick="question1(myform);return false;" title="Submit Your Answer"/></div></td>
              <td>&nbsp;</td>
            </tr>
          </table>  </td>
		   </tr>
  		
  		<tr>
  		  <td class="Textz" ><div id="DivExplain"></div></td></tr>
          <!--<tr><td align="right"><div id="DivNext" style="visibility:hidden">
	      <span class="menutoplink"><a href="solarquestion2.php" class="menutoplink">Next</a></span><a href="solarquestion2.php" class="menutoplink"> &nbsp;</a> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</div> </td></tr>-->
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
          
         <tr>
  		  <td class="Textz"><div id="Divquest2" style="visibility:hidden"><span class="Question">Q2) Now assume the plate is kept at an angle of 60 degrees to the incident radiation.</span>  Ie. The <span class="Question">normal to the plate makes an angle 60 degrees with the incident radiation.</span>  What is the solar radiation falling on the plate? The plate is on the surface of the earth.</div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="570" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
               <td width="170" height="100" valign="top"><div id="DivOption2" style="visibility:hidden"><form name="quest2" class="Textz" id="question">
              (a)<input type="radio" name="option1" value="a"  />&nbsp; 300 W/m<sup>2</sup><br />
(b)<input type="radio" name="option1" value="b"  />&nbsp; 500 W/m<sup>2</sup><br />
(c)<input type="radio" name="option1" value="c"  />&nbsp; 800 W/m<sup>2</sup><br />
(d)<input type="radio" name="option1" value="d"  />&nbsp; 1000 W/m<sup>2</sup>
              </form></div></td>
             <td width="400"><div id="DivMessage2" style="visibility:hidden"></div></td>
            </tr>
            <tr>
              <td align="center"><div id="DivButton2" style="visibility:hidden"><img src="images/submit.gif" onclick="question2(quest2)" title="Submit Your Answer"/></div></td>
              <td>&nbsp;</td>
            </tr>
          </table>  </td>
		   </tr>
  		
  		<tr>
  		  <td class="Textz" ><div id="DivExplain2"></div></td></tr></div>
        <tr>
  		  <td class="Textz"><div id="Divquest3" style="visibility:hidden"><span class="Question">Q3)  The plate is at a latitude of 20 degrees North with its normal passing through centre of Earth.  The day of the year is such that sun in its north-south movement is at the equator (equinox).  The time is local noon (ie. Sun is at the same longitude as the plate). What is the flux on the plate?</span></div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="601" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td width="185" height="100" valign="top"><div id="DivOption3" style="visibility:hidden"><form name="quest3" class="Textz" id="question">
              (a)<input type="radio" name="option1" value="a"  />&nbsp;	1000 Cos 0 W/m<sup>2</sup><br />
(b)<input type="radio" name="option1" value="b"  />&nbsp; 1000 Cos 20 W/m<sup>2</sup><br />
(c)<input type="radio" name="option1" value="c"  />&nbsp; 1000 Cos 30 W/m<sup>2</sup><br />
              </form></div></td>
             <td width="416"><div id="DivMessage3" style="visibility:hidden"></div></td>
            </tr>
            <tr>
              <td align="center"><div id="DivButton3" style="visibility:hidden"><img src="images/submit.gif" onclick="question3(quest3)" title="Submit Your Answer"/></div></td>
              <td>&nbsp;</td>
            </tr>
          </table>  </td>
		   </tr>
  		
  		<tr>
  		  <td class="Textz" ><div id="DivExplain3"></div></td></tr></div>
          
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
          
          <tr>
  		  <td class="Textz"><div id="Divquest4" style="visibility:hidden"><span class="Question">Q4) The plate is at a latitude of 20 degrees North with its normal passing through centre of Earth.  The day of the year is such that sun in its north-south movement is at the equator (equinox).  The local time is such that the Sun is at a longitude 30 degrees east of where the plate is. What is the flux on the plate?</span></div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="659" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td width="250" height="100" valign="top"><div id="DivOption4" style="visibility:hidden"><form name="quest4" class="Textz" id="question">
              (a)<input type="radio" name="option1" value="a"  />&nbsp;	1000 Cos 20 W/m<sup>2</sup><br />
(b)<input type="radio" name="option1" value="b"  />&nbsp; 1000 Cos 30 W/m<sup>2</sup><br />
(c)<input type="radio" name="option1" value="c"  />&nbsp; 1000 Cos 20 Cos 30 W/m<sup>2</sup><br />
(d)<input type="radio" name="option1" value="d"  />&nbsp; 1000 Cos 20 Sin 30 W/m<sup>2</sup><br />
              </form></div></td>
             <td width="409"><div id="DivMessage4" style="visibility:hidden"></div></td>
            </tr>
            <tr>
              <td align="center"><div id="DivButton4" style="visibility:hidden"><img src="images/submit.gif" onclick="question4(quest4)" title="Submit Your Answer"/></div></td>
              <td>&nbsp;</td>
            </tr>
          </table>  </td>
		   </tr>
  		
  		<tr>
  		  <td class="Textz" ><div id="DivExplain4"></div></td></tr></div>
          
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
		</table>
		</td>
      </tr>
    </table>
<?php require_once("footer.php");?>
