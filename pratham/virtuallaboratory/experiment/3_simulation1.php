<?php require_once("3_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr><td>
<div id="page">


<span class="OTitle">Multi-Layer Insulation</span>

<center><figure>
  <img src="images\mli.png" width="256px" height="192px
  ">
  <figcaption>Fig1 Multi-Layer Insulation.</figcaption>
</figure></center>
<p style="text-align:justify;" class="Textz"> Orbiting in the shadow of earth or the spacecraft's own shadow can be a challenge in keeping the temperature stable in the deep space. The craft can swing quickly to the cold side (typically -125°C) when in the shadows. On the other side, the spacecraft can see extremely high temperatures, typically +150°C, when exposed directly to the sun. Furthermore, there is a substantial amount of heat generated from the spacecraft's onboard equipment. Therefore, the spacecraft material must be highly adaptive to protect from both extreme heat and cold. Multi-layer insulation (MLI) sheets are ideal to protect the critical components in these extreme conditions.
<br>
MLI materials consist of lightweight reflective films assembled in many thin layers. These layers are typically made of polyimide and/or polyester films (typically 12 layers) are vapor deposited with 99.99% aluminum, on one or both sides. The MLI films assist in the material's heat management by reducing emittance with each layer. As it is very difficult to design an MLI insulation blanket that reflects 100% of incident radiation, a multilayer film design can range from a few simple layers to a complex array of blankets that completely surround the spacecraft and many of its external components. The designs of these layers typically reflect 95% of radiation back away from the Spacecraft.
<br>
Now in the below example if we apply MLI (absorptivity = 0.36 and emissivity = 0.65) on the exposed surfaces, the rate of absorption in (a) and the rate of emission in (b) will decrease by the factor of absorptivity and emissivity respectively. </p>

<span class="OTitle">Example:</span>


<p style="text-align:justify;" class="Textz"> Consider a cubical aluminum block with length L, density ρ = 2700kg/m3 and specific heat C<sub>p</sub> = 910 J/kg-K.
<br>(a) Heat flux of β Watts/m<sup>2</sup> is applied on one face and rest all the faces are insulated from the surrounding, so the applied heat flux is directly used to increase the temperature of the cube.
    
</p>
  <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
 
      
<form id="form1">


<table border="0" align="center" style="text-align:left">

    <tr>
    <td class="Textz">Heat Flux β (in W/m<sup>2</sup>):</td>
    <td class="Textz"><input name="X" value="0" type="number" max="100" /></td>
    </tr>

    <tr>
    <td class="Textz">Length L (in meters):</td>
    <td class="Textz"><input name="Y" value="0" type="number" max="100" /></td>
    </tr>

    </table><br />

    <div style="text-align:center">
    <input type="button" value="Submit" onclick="exp1()" />
  	<input type="reset"></div>

</form>

 <div id="chart_div1"></div>

<script type="text/javascript" >
		
	function exp1(){
		var x = document.getElementById("form1");
    
    	var b = (+x[0].value);
    	var l = (+x[1].value);
        var rho = 2700;
        var cp = 910;
        var m = b/(l*cp*rho);
        var a = 0.36;



google.charts.load('current', {packages: ['corechart', 'line']});
google.charts.setOnLoadCallback(drawBasic);

function drawBasic() {

      var data = new google.visualization.DataTable();
      data.addColumn('number', 'X');
      data.addColumn('number', 'w/o MLI');
      data.addColumn('number', 'with MLI')

      data.addRows([
        [0, 0, 0], [1,m, a*m], [2,2*m, 2*m*a] , [3, 3*m, 3*m*a]
      ]);

      var options = {
        hAxis: {
          title: 'Time'
        },
        vAxis: {
          title: 'Temperature'
        }
      };

      var chart = new google.visualization.LineChart(document.getElementById('chart_div1'));

      chart.draw(data, options);
    }

    	
	}

    </script>

<p style="text-align:justify;" class="Textz">(b) Initially the temperature of cube is 20 degrees Celsius, one of the face is exposed to vacuum and rest five faces are insulated. The temperature of cube decreases by radiation to vacuum through the exposed face. Temperature of vacuum = 3K (-270 degrees Celsius)
    

</p>
  <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
 
      
<form id="form2">


<table border="0" align="center" style="text-align:left">

    <tr>
    <td class="Textz">Emmisivity ε :</td>
    <td class="Textz"><input name="X" value="0" type="number" max="1" /></td>
    </tr>
    
    <tr>
    <td class="Textz">Length L (in meters):</td>
    <td class="Textz"><input name="Y" value="0" type="number" max="100" /></td>
    </tr>
   

    </table><br />

    <div style="text-align:center">
    <input type="button" value="Submit" onclick="exp2()" />
    <input type="reset"></div>

</form>

 <div id="chart_div2"></div>

<script type="text/javascript" >
        
    function exp2(){
        var x = document.getElementById("form2");
    
        var e = (+x[0].value);
        var l = (+x[1].value);
        var T = 3;
        var c =  .00000005670367*l*l;
        var e1 = 0.65;
        var k = 1/(3*Math.pow(293,3));
        var c2 = Math.pow(3,(1/3));



google.charts.load('current', {packages: ['corechart', 'line']});
google.charts.setOnLoadCallback(drawBasic);

function drawBasic() {

      var data = new google.visualization.DataTable();
      data.addColumn('number', 'X');
      data.addColumn('number', 'w/o MLI');
      data.addColumn('number', 'with MLI')

      data.addRows([
        [0, 293, 293], [0.1, 1/(c2*Math.pow(k+ e*c*0.1 , (1/3))) , 1/(c2*Math.pow(k+ e1*c*0.1 , (1/3)))], [0.2, 1/(c2*Math.pow(k+ e*c*0.2 , (1/3))) , 1/(c2*Math.pow(k+ e1*c*0.2 , (1/3)))], [0.3, 1/(c2*Math.pow(k+ e*c*0.3 , (1/3))) , 1/(c2*Math.pow(k+ e1*c*0.3 , (1/3)))], [0.4, 1/(c2*Math.pow(k+ e*c*0.4 , (1/3))) , 1/(c2*Math.pow(k+ e1*c*0.4 , (1/3)))], [0.5, 1/(c2*Math.pow(k+ e*c*0.5 , (1/3))) , 1/(c2*Math.pow(k+ e1*c*0.5 , (1/3)))], [0.6, 1/(c2*Math.pow(k+ e*c*0.6 , (1/3))) , 1/(c2*Math.pow(k+ e1*c*0.6 , (1/3)))], [1, 1/(c2*Math.pow(k+ e*c , (1/3))) , 1/(c2*Math.pow(k+ e1*c , (1/3)))], 
      ]);

      var options = {
        curveType: 'function',
        hAxis: {
          title: 'Time'
        },
        vAxis: {
          title: 'Temperature'
        }
      };

      var chart = new google.visualization.LineChart(document.getElementById('chart_div2'));

      chart.draw(data, options);
    }

        
    }

    </script>


    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>