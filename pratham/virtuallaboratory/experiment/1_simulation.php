<?php require_once("1_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr><td>
<div id="page">

<span class="OTitle">Input values of angular rates for the satellite</span>


<form id="form1">


<table border="0" align="center" style="text-align:left">

    <tr>
    <td class="Textz">Angular rate in 'x-axis' (in degrees per sec)</td>
    <td class="Textz"><input name="wx" value="0" type="number" max="15" /></td>
    </tr>

    <tr>
    <td class="Textz">Angular rate in 'y-axis' (in degrees per sec)</td>
    <td class="Textz"><input name="wy" value="0" type="number" max="15" /></td>
    </tr>

	<tr>
    <td class="Textz">Angular rate in 'z-axis' (in degrees per sec)</td>
    <td class="Textz"><input name="wz" value="0" type="number" max="15" /></td>
    </tr>
    </table><br />

    <div style="text-align:center">
    <input type="button" value="Submit" onclick="prop()" />
  	<input type="reset"></div>

</form>

<script src="numeric.js"></script>
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>

<div id="chart_div"></div>
<script type="text/javascript" >
		f = function func(t, x1){
    		var xdot=[0,0,0,0,0,0,0];
    		var Kp=1;
    		var wref=[0,0,0];
    		var q=[x1[0], x1[1], x1[2], x1[3]];
    		var w=[x1[4], x1[5], x1[6]];
    		var tau = [-Kp*w[0],-Kp*w[1], -Kp*w[2]];
    		var qdot=[0,0,0,0];
    		var W=[[0, w[2], -w[1], w[0]], [-w[2], 0, w[0], w[1]], [w[1], -w[0], 0, w[2]], [-w[0], -w[1], -w[2], 0]];
    		qdot=numeric.dot(W,q);
    		qdot=numeric.mul(0.5,qdot);
    		xdot=qdot.concat(tau);
    		return xdot;
    	}
	function prop(){
		var x = document.getElementById("form1");
    
		//var xinit = [0,0,0,1,x[0].value,x[1].value,x[2].value];
    var xinit = [0,0,0,1];
    w0_x = (+x[0].value)*Math.PI/180
    w0_y = (+x[1].value)*Math.PI/180
    w0_z = (+x[2].value)*Math.PI/180
		xinit.push(w0_x);
		xinit.push(w0_y);
		xinit.push(w0_z);
    
    //var xinit = [0,0,0,1,0.1,0.1,0.1]
		var sol = numeric.dopri(0,6,xinit,f );
		a=sol.x;
    //var trial = +x[0].value + +x[1].value;
		
		b=numeric.transpose(sol.y);
		c=[a,numeric.mul((180/Math.PI),b[4]),numeric.mul((180/Math.PI),b[5]),numeric.mul((180/Math.PI),b[6])];
		d=numeric.transpose(c);
    
		//var c=numeric.transpose(a);

				/*var text = "";
		var i;
		for (i = 0; i < 7 ;i++) {
        text += sol.x[i] + "<br>";
    	}

    	document.getElementById("answer").innerHTML = text;
    */
    	google.charts.load('current', {packages: ['corechart', 'line']});
google.charts.setOnLoadCallback(drawCurveTypes);

function drawCurveTypes() {

      var data = new google.visualization.DataTable();
      data.addColumn('number', 't');
      data.addColumn('number', 'w_x');
      data.addColumn('number', 'w_y');
      data.addColumn('number', 'w_z');

      data.addRows(d);

      var options = {
        hAxis: {
          title: 'Time'
        },
        vAxis: {
          title: 'Angular velocity'
        },
        series: {
          1: {curveType: 'function'}
        }
      };

      var chart = new google.visualization.LineChart(document.getElementById('chart_div'));

      chart.draw(data, options);
    }

}
      </script>
	

    
      
    
  </head>
  <body>
    <div id="curve_chart" style="width: 800px; height: 500px"></div>
  </body>

<div id="answer" style="text-align: center"></div>


    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>