<?php require_once("2_header.php"); ?>
<table width="800" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td><table width="770" border="0" align="center" cellpadding="0" cellspacing="0">
  		<tr>
    		<td>&nbsp;</td>
  		</tr>
  		<tr><td>
<div id="page">

<span class="OTitle">Simulation</span>

<p style="text-align:justify;" class="Textz"><b>Sun Vector</b><br />
Sun vector is the direction of sun with respect to the frame in question. Here
we show the time evolution of the sun vector in inertial frame and orbit frame.
Sun vector in inertial frame remains almost constant which is obtained from
sun model. User can provide the orbit parameters which will define the orbit
frame. Using frame transformation law given by equation (1), sun vector can
be plotted in orbit frame.</p>

<p style="text-align:justify;" class="Textz"><b>Magnetic field vector:</b><br />
Earth magnetic field at orbit position is sensed using three-axis magnetometer.
In satellite, we use International Geomagnetic Reference Field (IGRF - http:
//www.geomag.bgs.ac.uk/data_service/models_compass/igrf.html) model
to find magnetic field of the earth in inertial frame. In this simulation javascript based version (https://github.com/cmweiss/geomagJS) of world magnetic model is used. This can again be converted
in orbit frame using same transformation.</p>

<form id="form1">


<table border="0" align="center" style="text-align:left">
<tr>
    <td class="Textz">Altitude (in km)</td>
    <td class="Textz"><input name="alt"  type="number" max="1000" /></td>
    </tr>

    <tr>
    <td class="Textz">Inclination (in degrees)</td>
    <td class="Textz"><input name="inc"  type="number" max="180 "/></td>
    </tr>

    </table><br />

    <div style="text-align:center">
    <input type="button" value="Submit" onclick="prop()" />
  	<input type="reset"></div>

</form>

<script src="numeric.js"></script>
<script src="cof2Obj.js"></script>
<script src="syncXHR.js"></script>
<script src="cof2Obj.js"></script>
<script src="geomag.js"></script>
<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>

<div id="chart_div1"></div>
<div id="chart_div2"></div>
<div id="chart_div3"></div>
<div id="chart_div4"></div>

<script type="text/javascript" >
function prop(){
	var rad_earth = 6378.164;
	var x = document.getElementById("form1");
  var alt = +x[0].value;
  var inc = +x[1].value;
//console.log(alt,inc);
	inc = inc*Math.PI/180;
  var v = Math.sqrt(3.99*Math.pow(10,14)/(1000*(alt + rad_earth)));
	//var xinit = [-7061909.96247724,-516745.227013821,-14659.9341567393, -85.4453629760447 ,1064.51048588373 ,7427.29881205264];
  var xinit = [1000*(alt + rad_earth),0, 0, 0,-v*Math.cos(inc), v*Math.sin(inc)];
  //console.log(xinit)
  //console.log([-7061909.96247724,-516745.227013821,-14659.9341567393, -85.4453629760447 ,1064.51048588373 ,7427.29881205264]);
	var sol = numeric.dopri(0,10000,xinit,f );
	var b = numeric.transpose(sol.y);
	var x = b[0];
	var y = b[1];
	var z = b[2];
	var v_x = b[3];
	var v_y = b[4];
	var v_z = b[5];
	var B_I = [];
	var S_I = [];
	var B_O = [];
	var S_O = [];
	
	for (i=0;i<(sol.x).length;i++)
	{	
		var time = new Date("18-Oct-2015 10:30:0");
   
	
		var B_calc = mag_calc(x[i],y[i],z[i],time,i);
		
		B_I.push(B_calc);
		
		var S_calc = sun_calc(sol.x[i],time);
		S_I.push(S_calc);

		var r = Math.sqrt(x[i]*x[i]+y[i]*y[i]+z[i]*z[i])
		var oy = [v_y[i]*z[i]-v_z[i]*y[i], v_z[i]*x[i]-v_x[i]*z[i], v_x[i]*y[i]-v_y[i]*x[i]];
		 
		oy = numeric.mul(1/Math.sqrt(oy[0]*oy[0]+oy[1]*oy[1]+oy[2]*oy[2]),oy);

		var oz = numeric.mul(-1/r,[x[i],y[i],z[i]]);

		var ox = [oy[1]*oz[2]-oy[2]*oz[1], oy[2]*oz[0]-oy[0]*oz[2], oy[0]*oz[1]-oy[1]*oz[0]];
		
		ox = numeric.mul(1/Math.sqrt(ox[0]*ox[0]+ox[1]*ox[1]+ox[2]*ox[2]),ox);
		var TOI = [[ox[0],ox[1],ox[2]],[oy[0],oy[1],oy[2]],[oz[0],oz[1],oz[2]]];


		var v_S_O = numeric.dot(TOI,S_calc);
		
		S_O.push(v_S_O);
		var v_B_O = numeric.dot(TOI,B_calc);
		B_O.push(v_B_O);
	
		
	}
	var a = sol.x;
	S_I_T = numeric.transpose(S_I);
	S_O_T = numeric.transpose(S_O);
  d_I_S = numeric.transpose([a,S_I_T[0],S_I_T[1],S_I_T[2]]);
	d_O_S = numeric.transpose([a,S_O_T[0],S_O_T[1],S_O_T[2]]);

  B_I_T = numeric.transpose(B_I);
  B_O_T = numeric.transpose(B_O);
  d_I_B = numeric.transpose([a,B_I_T[0],B_I_T[1],B_I_T[2]]);
  d_O_B = numeric.transpose([a,B_O_T[0],B_O_T[1],B_O_T[2]]);
	//console.log(d_I_B[0],d_I_B[1],d_I_B[2]);

	
	google.charts.load('current', {packages: ['corechart', 'line']});
	google.charts.setOnLoadCallback(drawCurveTypes);

	function drawCurveTypes() {

      //Chart#1
      var data1= new google.visualization.DataTable();
      data1.addColumn('number', 't');
      data1.addColumn('number', 'sx_I');
      data1.addColumn('number', 'sy_I');
      data1.addColumn('number', 'sz_I');

      data1.addRows(d_I_S);

      var options1 = {
        title:'Sun Vector in Inertial Frame'  ,
        hAxis: {
          title: 'Time (in sec)'
        },
        vAxis: {
          title: 'Sun Vector in Inertial Frame'
        },
        series: {
          1: {curveType: 'function'}
        }
      };

      var chart1 = new google.visualization.LineChart(document.getElementById('chart_div1'));

      chart1.draw(data1, options1);
    

  //Chart#2
      var data2= new google.visualization.DataTable();
      data2.addColumn('number', 't');
      data2.addColumn('number', 'sx_O');
      data2.addColumn('number', 'sy_O');
      data2.addColumn('number', 'sz_O');

      data2.addRows(d_O_S);

      var options2 = {
        title:'Sun Vector in Orbit Frame',
        hAxis: {
          title: 'Time (in sec)'
        },
        vAxis: {
          title: 'Sun Vector in Orbit Frame'
        },
        series: {
          1: {curveType: 'function'}
        }
      };

      var chart2 = new google.visualization.LineChart(document.getElementById('chart_div2'));

      chart2.draw(data2, options2);

      //Chart#3
      var data3= new google.visualization.DataTable();
      data3.addColumn('number', 't');
      data3.addColumn('number', 'Bx_I');
      data3.addColumn('number', 'By_I');
      data3.addColumn('number', 'Bz_I');

      data3.addRows(d_I_B);

      var options3 = {
        title: 'Magnetic Field Vector in Inertial Frame',
        hAxis: {
          title: 'Time {in sec)'
        },
        vAxis: {
          title: 'Magnetic Field (in nT)'
        },
        series: {
          1: {curveType: 'function'}
        }
      };

      var chart3 = new google.visualization.LineChart(document.getElementById('chart_div3'));

      chart3.draw(data3, options3);

      //Chart#4
      var data4= new google.visualization.DataTable();
      data4.addColumn('number', 't');
      data4.addColumn('number', 'Bx_O');
      data4.addColumn('number', 'By_O');
      data4.addColumn('number', 'Bz_O');

      data4.addRows(d_O_B);

      var options4 = {
        title: 'Magnetic Field Vector in Orbit Frame',
        hAxis: {
          title: 'Time (in sec)'
        },
        vAxis: {
          title: 'Magnetic Field (in nT)'
        },
        series: {
          1: {curveType: 'function'}
        }
      };

      var chart4 = new google.visualization.LineChart(document.getElementById('chart_div4'));

      chart4.draw(data4, options4);
    }

	
}

function f(t,x1)
{
	var r = Math.sqrt(x1[1]*x1[1]+x1[0]*x1[0]+x1[2]*x1[2])
	var xdot = [x1[3],x1[4],x1[5]];
	var vdot = numeric.mul(-3.99*Math.pow(10,14)/(r*r*r),[x1[0],x1[1],x1[2]]);
	xdot = xdot.concat(vdot);
	return xdot;
}

function mag_calc(x_i,y_i,z_i,time,T1){

var equinox = new Date("20-Mar-2015 22:45:0");// date of equinox
  var phi = (time-equinox)/1000 + T1;
    phi = phi*2*Math.PI/86400
    var eci2ecef = [[Math.cos(phi), -Math.sin(phi), 0],[Math.sin(phi), Math.cos(phi), 0], [0,0,1]];

  var alt = Math.sqrt(x_i*x_i+y_i*y_i+z_i*z_i)-6371*1000;
  var XYZ_ecef =  numeric.dot(eci2ecef,[x_i,y_i,z_i]);
  var x = XYZ_ecef[0];
  var y = XYZ_ecef[1];
  var z = XYZ_ecef[2];

  var lat = Math.atan2(z,Math.sqrt(x*x+y*y));
  lat = 180*lat/Math.PI
  var lon;
  if(x<0 && y>0)
    {lon =  Math.atan2(y,x);}
  else if(x<0 && y<0)
    {lon = Math.atan2(y,x);}
  else{lon = Math.atan2(y,x);}
  lon = 180*lon/Math.PI

  var mu = lat*Math.PI/180;
    var i = lon*Math.PI/180;
    var ned2ecef = [[-Math .sin(mu)*Math.cos(i),-Math.sin(i),-Math.cos(mu)*Math.cos(i)],[-Math.sin(mu)*Math.sin(i),Math.cos(i),-Math.cos(mu)*Math.sin(i)],[Math.cos(mu),0,-Math.sin(mu)]];
	var cof = syncXHR('WMM.COF');
    wmm = cof2Obj(cof);
    geoMag = geoMagFactory(wmm);
    alt = alt*3.28084;
    mygeoMag = geoMag(lat,lon,alt,time);
    magneticBX = mygeoMag.bx;  // North Component of the geomagnetic field in nT
    magneticBY = mygeoMag.by;   // East Component of the geomagnetic field in nT
    magneticBZ = mygeoMag.bz; 
    
    var b_ecef = numeric.dot(ned2ecef,[magneticBX, magneticBY, magneticBZ]);
   
    
    var b_eci = numeric.dot(numeric.transpose(eci2ecef),b_ecef);

    //return [magneticBX, magneticBY, magneticBZ];
    return b_eci;
}

function sun_calc(T1,time){
	
    var equinox = new Date("20-Mar-2015 22:45:0");// date of equinox

    var beta = 0;   
    var time1 = (time - equinox)/86400000 + T1/ 86400;
    
    var lambda = (2*Math.PI*time1) / 365.256363;
    var epsilon = 23.5 * Math.PI / 180;
    var sin_delta = Math.cos(epsilon)*Math.sin(beta) + Math.sin(epsilon)*Math.cos(beta)*Math.sin(lambda);
    var delta = Math.asin(sin_delta);

    var cos_alpha = Math.cos(lambda) * Math.cos(beta) / Math.cos(delta);
    var alpha = Math.acos(cos_alpha);
    if (delta >= 0){
        alpha = alpha;
    }
    else{
        alpha = (2*Math.PI - 2*alpha) + alpha;
    }
    

    var s_x = Math.cos(delta)*Math.cos(alpha);
    var s_y = Math.cos(delta)*Math.sin(alpha);
    var s_z = Math.sin(delta);

    var v_Sun_i = [s_x];
    v_Sun_i.push(s_y);
    v_Sun_i.push(s_z);
    var r_s = Math.sqrt(s_x*s_x+s_y*s_y+s_z*s_z);
    v_Sun_i = numeric.mul(1/r_s,v_Sun_i);
    return v_Sun_i;


}
</script>
    </div>
    </td></tr>
    <tr><td>&nbsp;</td></tr></table>
<?php require_once("footer.php");?>