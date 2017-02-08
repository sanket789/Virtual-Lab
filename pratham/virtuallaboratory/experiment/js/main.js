function question1(thisform) {
// place any other field validations that you require here
// validate myradiobuttons
myOption = -1;
//alert(thisform.option1.length);
for (i=thisform.option1.length-1; i > -1; i--) {
if (thisform.option1[i].checked) {
myOption = i; i = -1;
}
}
if(thisform.option1[myOption].value == "c" )
{
	 	//document.getElementById('DivNext').style.visibility='hidden'
		document.getElementById('DivMessage').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Correct<br/> Answer = 1000 W/m<sup>2</sup></center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		//document.getElementById('DivButton').style.visibility='hidden'
		document.getElementById('DivExplain').innerHTML="<iframe src='question1_ans.html' frameborder='no' width='770' height='500' scrolling='no'></iframe>"
		document.getElementById('DivOption2').style.visibility='visible'
		document.getElementById('Divquest2').style.visibility='visible'
		document.getElementById('DivMessage2').style.visibility='visible'
		document.getElementById('DivButton2').style.visibility='visible'
}
else
{
	//document.getElementById('DivNext').style.visibility='hidden'
	document.getElementById('DivMessage').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Wrong<br/> Answer = 1000 W/m<sup>2</sup></center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
	//document.getElementById('DivButton').style.visibility='hidden'
	document.getElementById('DivExplain').innerHTML="<iframe src='question1_ans.html' frameborder='no' width='770' height='500' scrolling='no'></iframe>"
	document.getElementById('DivOption2').style.visibility='visible'
	document.getElementById('Divquest2').style.visibility='visible'
	document.getElementById('DivMessage2').style.visibility='visible'
	document.getElementById('DivButton2').style.visibility='visible'
}
}

function question2(thisform) 
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
		document.getElementById('DivMessage2').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Correct<br/> Answer = 500 W/m<sup>2</sup>.</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivExplain2').innerHTML="<iframe src='question2_ans.html' frameborder='no' width='770' height='410' scrolling='no'></iframe>"
		document.getElementById('DivOption3').style.visibility='visible'
		document.getElementById('Divquest3').style.visibility='visible'
		document.getElementById('DivMessage3').style.visibility='visible'
		document.getElementById('DivButton3').style.visibility='visible'
}
else
{
	
		document.getElementById('DivMessage2').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Wrong<br/> Answer = 500 W/m<sup>2</sup>.</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivExplain2').innerHTML="<iframe src='question2_ans.html' frameborder='no' width='770' height='410' scrolling='no'></iframe>"
		document.getElementById('DivOption3').style.visibility='visible'
		document.getElementById('Divquest3').style.visibility='visible'
		document.getElementById('DivMessage3').style.visibility='visible'
		document.getElementById('DivButton3').style.visibility='visible'
	
}
}

function question3(thisform) 
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
		document.getElementById('DivMessage3').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Correct<br/> Answer = 1000 Cos 20&deg;</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivExplain3').innerHTML='<table width="770" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px">That was simple to visulaise.  Let us now visualize a slightly more complex case.</td></tr></table>'
		document.getElementById('DivOption4').style.visibility='visible'
		document.getElementById('Divquest4').style.visibility='visible'
		document.getElementById('DivMessage4').style.visibility='visible'
		document.getElementById('DivButton4').style.visibility='visible'
}
else
{
	
		document.getElementById('DivMessage3').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Wrong<br/> Answer = 1000 Cos 20&deg;</center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivExplain3').innerHTML='<table width="770" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px">That was simple to visulaise.  Let us now visualize a slightly more complex case.</td></tr></table>'
		document.getElementById('DivOption4').style.visibility='visible'
		document.getElementById('Divquest4').style.visibility='visible'
		document.getElementById('DivMessage4').style.visibility='visible'
		document.getElementById('DivButton4').style.visibility='visible'
	
}
}

function question4(thisform) 
{
myOption = -1;
for (i=thisform.option1.length-1; i > -1; i--) {
if (thisform.option1[i].checked) {
myOption = i; i = -1;
}
}
if(thisform.option1[myOption].value == "c" )
{
	 	//document.getElementById('DivNext').style.visibility='hidden'
		document.getElementById('DivMessage4').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Correct<br/> Answer = 1000 Cos 20&deg; Cos 30&deg; W/m<sup>2</sup></center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivExplain4').innerHTML="<iframe src='question4_ans.html' frameborder='no' width='770' height='1650' scrolling='no'></iframe>"
		//document.getElementById('DivButton4').style.visibility='hidden'
		//document.getElementById('Divquest5').style.visibility='visible'
		//document.getElementById('DivMessage5').style.visibility='visible'
		//document.getElementById('DivButton5').style.visibility='visible'
}
else
{
	
		document.getElementById('DivMessage4').innerHTML='<table width="400" border="0" align="center" cellpadding="0" cellspacing="0"><tr><td><img src="images/lt.gif" width="23" height="19" /></td><td background="images/top.gif" height="19" ></td><td><img src="images/rt.gif" width="25" height="19" /></td></tr><tr><td background="images/left.gif" width="23"></td><td style="font-family:Verdana, Arial, Helvetica, sans-serif; font-size:12px"><center>Your Answer is Wrong<br/> Answer = 1000 Cos 20&deg; Cos 30&deg; W/m<sup>2</sup></center></td><td background="images/right.gif" width="25"></td></tr><tr><td><img src="images/lb.gif" width="23" height="19" /></td><td background="images/bottom.gif" height="19" ></td><td><img src="images/rb.gif" width="25" height="19" /></td></tr></table>'
		document.getElementById('DivExplain4').innerHTML="<iframe src='question4_ans.html' frameborder='no' width='770' height='1650' scrolling='no'></iframe>"
		//document.getElementById('DivButton4').style.visibility='hidden'
		//document.getElementById('Divquest5').style.visibility='visible'
		//document.getElementById('DivMessage5').style.visibility='visible'
		//document.getElementById('DivButton5').style.visibility='visible'
	
}
}