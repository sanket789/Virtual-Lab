function hquestion1(thisform) {
// place any other field validations that you require here
// validate myradiobuttons
myOption = -1;
for (i=thisform.option1.length-1; i > -1; i--) {
if (thisform.option1[i].checked) {
myOption = i; i = -1;
}
}
if(thisform.option1[myOption].value == "d" )
{
	 	//document.getElementById('DivNext').style.visibility='hidden'
		document.getElementById('DivHMessage').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Correct<br/> Answer =  T0+&alpha;*A*1000*t/(A*&rho;*th*C)</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		//document.getElementById('DivButton').style.visibility='hidden'
		document.getElementById('DivHExplain').innerHTML="<iframe src='hquestion1_ans.html' frameborder='no' width='770' height='580' scrolling='no'></iframe>"
		document.getElementById('DivHOption2').style.visibility='visible'
		document.getElementById('DivHquest2').style.visibility='visible'
		document.getElementById('DivHMessage2').style.visibility='visible'
		document.getElementById('DivHButton2').style.visibility='visible'
}
else
{
	//document.getElementById('DivNext').style.visibility='hidden'
	document.getElementById('DivHMessage').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Wrong<br/> Answer =  T0+&alpha;*A*1000*t/(A*&rho;*th*C)</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
	//document.getElementById('DivButton').style.visibility='hidden'
	document.getElementById('DivHExplain').innerHTML="<iframe src='hquestion1_ans.html' frameborder='no' width='770' height='580' scrolling='no'></iframe>"
	document.getElementById('DivHOption2').style.visibility='visible'
	document.getElementById('DivHquest2').style.visibility='visible'
	document.getElementById('DivHMessage2').style.visibility='visible'
	document.getElementById('DivHButton2').style.visibility='visible'
}
}

function hquestion2(thisform) 
{
myOption = -1;
for (i=thisform.option1.length-1; i > -1; i--) {
if (thisform.option1[i].checked) {
myOption = i; i = -1;
}
}
if(thisform.option1[myOption].value == "b" )
{
	 	//document.getElementById('DivNext').style.visibility='hidden'
		document.getElementById('DivHMessage2').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Correct<br/> Answer = M*C*(dT/dt)=&alpha;*1000*A-&epsilon;*&sigma;*A*T<sup>4</sup</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivHExplain2').innerHTML="<iframe src='hquestion2_ans.html' frameborder='no' width='770' height='370' scrolling='no'></iframe>"
		document.getElementById('DivHOption3').style.visibility='visible'
		document.getElementById('DivHquest3').style.visibility='visible'
		document.getElementById('DivHMessage3').style.visibility='visible'
		document.getElementById('DivHButton3').style.visibility='visible'
}
else
{
	
		document.getElementById('DivHMessage2').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Wrong<br/> Answer = M*C*(dT/dt)=&alpha;*1000*A-&epsilon;*&sigma;*A*T<sup>4</sup></center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivHExplain2').innerHTML="<iframe src='hquestion2_ans.html' frameborder='no' width='770' height='370' scrolling='no'></iframe>"
		document.getElementById('DivHOption3').style.visibility='visible'
		document.getElementById('DivHquest3').style.visibility='visible'
		document.getElementById('DivHMessage3').style.visibility='visible'
		document.getElementById('DivHButton3').style.visibility='visible'
	
}
}

function hquestion3(thisform) 
{
myOption = -1;
for (i=thisform.option1.length-1; i > -1; i--) {
if (thisform.option1[i].checked) {
myOption = i; i = -1;
}
}
if(thisform.option1[myOption].value == "a" )
{
	 	//document.getElementById('DivNext').style.visibility='hidden'
		document.getElementById('DivHMessage3').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Correct<br/> Answer = (&alpha;*1000/&epsilon;*&sigma;)^0.25</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivHExplain3').innerHTML="<iframe src='hquestion3_ans.html' frameborder='no' width='770' height='200' scrolling='no'></iframe>"
		document.getElementById('DivHOption4').style.visibility='visible'
		document.getElementById('DivHquest4').style.visibility='visible'
		document.getElementById('DivHMessage4').style.visibility='visible'
		document.getElementById('DivHButton4').style.visibility='visible'
}
else
{
	
		document.getElementById('DivHMessage3').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Wrong<br/> Answer = (&alpha;*1000/&epsilon;*&sigma;)^0.25</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivHExplain3').innerHTML="<iframe src='hquestion3_ans.html' frameborder='no' width='770' height='200' scrolling='no'></iframe>"
		document.getElementById('DivHOption4').style.visibility='visible'
		document.getElementById('DivHquest4').style.visibility='visible'
		document.getElementById('DivHMessage4').style.visibility='visible'
		document.getElementById('DivHButton4').style.visibility='visible'
	
}
}

function hquestion4(thisform) 
{
myOption = -1;
for (i=thisform.option1.length-1; i > -1; i--) {
if (thisform.option1[i].checked) {
myOption = i; i = -1;
}
}
if(thisform.option1[myOption].value == "a" )
{
	 	//document.getElementById('DivNext').style.visibility='hidden'
		document.getElementById('DivHMessage4').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Correct<br/> Answer = Vary cyclically</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivHExplain4').innerHTML="<iframe src='hquestion4_ans.html' frameborder='no' width='770' height='350' scrolling='no'></iframe>"
		//document.getElementById('DivButton4').style.visibility='hidden'
		//document.getElementById('Divquest5').style.visibility='visible'
		//document.getElementById('DivMessage5').style.visibility='visible'
		//document.getElementById('DivButton5').style.visibility='visible'
}
else
{
	
		document.getElementById('DivHMessage4').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Wrong<br/> Answer = Vary cyclically</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivHExplain4').innerHTML="<iframe src='hquestion4_ans.html' frameborder='no' width='770' height='350' scrolling='no'></iframe>"
		//document.getElementById('DivButton4').style.visibility='hidden'
		//document.getElementById('Divquest5').style.visibility='visible'
		//document.getElementById('DivMessage5').style.visibility='visible'
		//document.getElementById('DivButton5').style.visibility='visible'
	
}
}