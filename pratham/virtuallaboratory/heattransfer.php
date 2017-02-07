<?php require_once("experiment/header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr>
  		  <td class="OTitle">Heat Transfer</td>
		  </tr>
          <tr>
  		  <td>&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><div align="justify">The first tutorial taught you to compute the radiant solar flux incident on any 2-D geometry located anywhere in space. We shall now move on to study the effect of this flux on the physical properties of the plate. The physical property of interest here is the temperature of the body. This tutorial will guide you through the computation of temperatures for various physical systems. The effect of material properties on the temperature of the geometry shall be explained. At the end of the tutorial, you would be able to carry out trade studies; that is variation of temperature for changes in the incident thermal load or material properties.</div></td>
		  </tr>
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><div align="justify" class="Question">Q1) Consider a 1 m<sup>2</sup> (A) flat plate with radiant flux density of 1000 W/m<sup>2</sup> incident normal to it. Assume the thickness of the plate to be 'th', density to be &rho;, specific heat capacity to be C. Also assume that there is no spatial variation in the temperature of the plate and assume that the initial temperature is T<sub>0</sub>. Also the absorptivity of the plate is α and that this is the only thermal load incident on the body. What is the temperature of the plate as a function of time? The specific heat capacity can be assumed to be independent of temperature</div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="650" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td width="250" height="100" valign="top"><form name="myform" class="Textz" >
              (a)<input type="radio" name="option1" value="a"  />&nbsp; T<sub>0</sub> + &alpha;*A<sup>2</sup>*&rho;*th*C*1000*t<br />
(b)<input type="radio" name="option1" value="b"  />&nbsp; T<sub>0</sub> + &alpha;*A*&rho;*th*C*1000*t<br />
(c)<input type="radio" name="option1" value="c"  />&nbsp; T<sub>0</sub> + A<sup>2</sup>*&rho;*th*C*1000*t<br />
(d)<input type="radio" name="option1" value="d"  />&nbsp; T<sub>0</sub> + &alpha;*A*1000*t/(A*&rho;*th*C)
              </form></td>
              <td width="400"><div id="DivHMessage"></div></td>
              <!--<td width="393" valign="middle"><div id="DivHMessage" align="center"></div></td>-->
            </tr>
            <tr>
              <td align="center"><div id="DivHButton"><img src="images/submit.gif" onclick="hquestion1(myform)" title="Submit Your Answer"/></div></td>
              <td>&nbsp;</td>
            </tr>
          </table>  </td>
		   </tr>
  		
  		<tr>
  		  <td class="Textz" ><div id="DivHExplain"></div></td></tr>
          <!--<tr><td align="right"><div id="DivNext" style="visibility:hidden">
	      <span class="menutoplink"><a href="solarquestion2.php" class="menutoplink">Next</a></span><a href="solarquestion2.php" class="menutoplink"> &nbsp;</a> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</div> </td></tr>-->
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
          
         <tr>
  		  <td class="Textz"><div id="DivHquest2" style="visibility:hidden"><span class="Question">Q2) Derive the governing equation for the same flat plate. Now along with the incident radiation, the flat plate emits radiation to free space at 0 K according to the Stefan Boltzmann relationship. The emissivity of the surface can be assumed to be &epsilon;</div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="681" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
               <td width="273" height="100" valign="top"><div id="DivHOption2" style="visibility:hidden"><form name="quest2" class="Textz" id="question">
              (a)<input type="radio" name="option1" value="a"  />&nbsp; M*C*(dT/dt)=&alpha;*1000*A-&sigma;*A*T<sup>3</sup><br />
(b)<input type="radio" name="option1" value="b"  />&nbsp; M*C*(dT/dt)=&alpha;*1000*A-&epsilon;*&sigma;*A*T<sup>4</sup><br />
(c)<input type="radio" name="option1" value="c"  />&nbsp; M*C*(dT/dt)=&alpha;*1000*A+&sigma;*A*T<sup>4</sup><br />
(d)<input type="radio" name="option1" value="d"  />&nbsp; M*C*(dT/dt)=&alpha;*1000*A–&sigma;*A*T<sup>4</sup>
              </form></div></td>
             <td width="408"><div id="DivHMessage2" style="visibility:hidden"></div></td>
            </tr>
            <tr>
              <td align="center"><div id="DivHButton2" style="visibility:hidden"><img src="images/submit.gif" onclick="hquestion2(quest2)" title="Submit Your Answer"/></div></td>
              <td>&nbsp;</td>
            </tr>
          </table>  </td>
		   </tr>
  		
  		<tr>
  		  <td class="Textz" ><div id="DivHExplain2"></div></td></tr></div>
        <tr>
  		  <td class="Textz"><div id="DivHquest3" style="visibility:hidden"><span class="Question">Q3)Compute the steady state temperature for the above problem</span></div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="650" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td width="250" height="100" valign="top"><div id="DivHOption3" style="visibility:hidden"><form name="quest3" class="Textz" id="question">
              (a)<input type="radio" name="option1" value="a"  />&nbsp; (&alpha;*1000/&epsilon;*&sigma;)^0.25<br />
(b)<input type="radio" name="option1" value="b"  />&nbsp; (&epsilon;*&sigma;/&alpha;*1000)^0.25<br />
(c)<input type="radio" name="option1" value="c"  />&nbsp; (&epsilon;*&sigma;/&alpha;*1000)^0.5<br />
(c)<input type="radio" name="option1" value="d"  />&nbsp; (&alpha;*1000/&epsilon;*&sigma;)^0.5
              </form></div></td>
             <td width="400"><div id="DivHMessage3" style="visibility:hidden"></div></td>
            </tr>
            <tr>
              <td align="center"><div id="DivHButton3" style="visibility:hidden"><img src="images/submit.gif" onclick="hquestion3(quest3)" title="Submit Your Answer"/></div></td>
              <td>&nbsp;</td>
            </tr>
          </table>  </td>
		   </tr>
  		
  		<tr>
  		  <td class="Textz" ><div id="DivHExplain3"></div></td></tr></div>
          
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
          
          <tr>
  		  <td class="Textz"><div id="DivHquest4" style="visibility:hidden"><span class="Question">Q4) Now instead of a constant incident flux density, assume that the flux density is varying periodically as it would in the case of a satellite. Assume Flux density = 100*sin(wt). Which of these according to you describes the situation in the most accurate manner?</span></div></td>
		  </tr>
  		<tr>
  		  <td class="Textz">&nbsp;</td>
		  </tr>
  		<tr>
  		  <td class="Textz"><table width="691" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td width="281" height="100" valign="top"><div id="DivHOption4" style="visibility:hidden"><form name="quest4" class="Textz" id="question">
              (a)<input type="radio" name="option1" value="a"  />&nbsp;	Go on increasing<br />
(b)<input type="radio" name="option1" value="b"  />&nbsp; Achieve a steady state temperature<br />
(c)<input type="radio" name="option1" value="c"  />&nbsp; Vary cyclically<br />
(d)<input type="radio" name="option1" value="d"  />&nbsp; None of these<br />
              </form></div></td>
             <td width="410"><div id="DivHMessage4" style="visibility:hidden"></div></td>
            </tr>
            <tr>
              <td align="center"><div id="DivHButton4" style="visibility:hidden"><img src="images/submit.gif" onclick="hquestion4(quest4)" title="Submit Your Answer"/></div></td>
              <td>&nbsp;</td>
            </tr>
          </table>  </td>
		   </tr>
  		
  		<tr>
  		  <td class="Textz" ><div id="DivHExplain4"></div></td></tr></div>
          
  		<tr>
  		  <td>&nbsp;</td>
		  </tr>
         
		</table>
		</td>
      </tr>
    </table>
<?php require_once("footer.php");?>
