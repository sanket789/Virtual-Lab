<?php
require_once("header.php"); ?>
<table width="800" border="0" cellspacing="0" cellpadding="0" align="center" bgcolor="#FFFFFF">
  <tr><td>
<table width="770" border="0" cellspacing="0" cellpadding="0" align="center">
  	<tr><td>&nbsp;</td>
  	</tr>
    <tr><td class="OTitle">Feedback</td></tr>
     <tr><td>&nbsp;</td></tr>
    <tr><td>&nbsp;</td></tr>
    <tr>
      <td class="Textz">
      <?php
	  if($_POST['email']!="")
	  { 
	  $email = $_POST['email'];
	  $name = $_POST['name'];
	  $course = $_POST['course'];
	  $college = $_POST['college'];
	  $city = $_POST['city'];
	  $remarks = $_POST['remarks'];
	  $fromemail = "no-reply@aero.iitb.ac.in" ;
	  mail( "prathamvirtuallab@gmail.com", "Virtual Lab Feedback",
        	"Name : $name \nE-mail ID : $email \nCourse : $course \nCollege : $college \n\nMessage : \n$remarks",
        	"From:  $fromemail\nReply-to: $email" );

	  echo "Thank you for filling in the Feedback form";
	  }
	else
	{
		header("location:index.php");
	}
	  ?>
      </td>
    </tr>
    <tr><td height="150">&nbsp;</td></tr>      
</table>
</td></table>
<?php require_once("footer.php");?>
