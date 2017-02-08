<?php require_once("header.php"); ?>
<script type="text/javascript">

function formValidate(feedback)
{
		var emailRegEx = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
		str = document.getElementById('email').value;
		//alert(str.match(emailRegEx));
		if(feedback.name.value=='')
        {
                //alert("Name Required");
                document.getElementById('lname').setAttribute('style','color:#FF0000;');
                return false;
        }
        /*else if(feedback.college.value=='')
        {
                //alert("Paper Title Required");
                document.getElementById('lcollege').setAttribute('style','color:#FF0000;');
                return false;
        }
        else if(feedback.city.value=='')
        {
                //alert("Upload file Required");
                document.getElementById('lcity').setAttribute('style','color:#FF0000;');
                return false;
        }*/
		else if(str.match(emailRegEx)==null){
				//document.feedback.submit();
				//}
				//else{
				alert('Please enter a valid email address.');
				document.getElementById('lemail').setAttribute('style','color:#FF0000;');
      			return false;
				//}
        }
		else if(feedback.remarks.value=='')
        {
                //alert("Upload file Required");
                document.getElementById('lremarks').setAttribute('style','color:#FF0000;');
                return false;
        }

}
</script>
<form name="feedback" id="feedback" method="post" enctype="multipart/form-data" action="feedbackdb.php" onsubmit="return formValidate(feedback);">
<table width="800" border="0" cellspacing="0" cellpadding="0" align="center" bgcolor="#FFFFFF">
  <tr><td>
<table width="770" border="0" cellspacing="0" cellpadding="0" align="center">
  	<tr><td>&nbsp;</td>
  	</tr>
    <tr><td class="OTitle">Feedback</td></tr>
     <tr><td>&nbsp;</td></tr>
    <tr><td>&nbsp;</td></tr>
    <tr><td><table width="574" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td width="183" class="Textz"><label id="lname" name="lname">Name</label></td>
    <td width="327" class="Textz"><input type="text" name="name" id="name" /></td>
  </tr>
  <tr>
    <td class="Textz">&nbsp;</td>
    <td class="Textz">&nbsp;</td>
  </tr>
  <tr>
    <td class="Textz">Course of study?</td>
    <td class="Textz"><select name="course" id="course">
    <option value="None">None</option>
    <option value="B.Sc">B.Sc</option>
    <option value="B.Tech">B.Tech</option>
    <option value="M.sc">M.Sc</option>
    <option value="M.Tech">M.Tech</option>
    <option value="P.hd">P.hd</option></select></td>
  </tr>
  <tr>
    <td class="Textz">&nbsp;</td>
    <td class="Textz">&nbsp;</td>
  </tr>
  <tr>
    <td class="Textz"><label id="lcollege" name="lcollege">Name of college</label></td>
    <td class="Textz"><input type="text" name="college" id="college" /></td>
  </tr>
  <tr>
    <td class="Textz">&nbsp;</td>
    <td class="Textz">&nbsp;</td>
  </tr>
  <tr>
    <td class="Textz"><label id="lcity" name="lcity">City</label></td>
    <td class="Textz"><input type="text" name="city" id="city" /></td>
  </tr>
  <tr>
    <td class="Textz">&nbsp;</td>
    <td class="Textz">&nbsp;</td>
  </tr>
  <tr>
    <td class="Textz"><label id="lemail" name="lemail">Email address :</label></td>
    <td class="Textz"><input type="text" name="email" id="email" /></td>
  </tr>
  <tr>
    <td class="Textz">&nbsp;</td>
    <td class="Textz">&nbsp;</td>
  </tr>
  <tr>
    <td valign="top" class="Textz"><label id="lremarks" name="lremarks">Box for text remarks</label></td>
    <td class="Textz"><textarea name="remarks" id="remarks" cols="40" rows="10"></textarea></td>
  </tr>
  <tr>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
  <tr>
    <td colspan="2" align="center"><input type="image" src="images/submit.gif" name="submit" title="Submit your Feedback"/>
 &nbsp;&nbsp;
    <a href="index.php"><img src="images/cancel.gif" name="cancel" title="Click here to cancel the feedback form" border=0/></a></td>
    </tr>
</table>
</td></tr>
    <tr><td height="150">&nbsp;</td></tr>      
</table>
</td></table>
<?php require_once("footer.php");?>
