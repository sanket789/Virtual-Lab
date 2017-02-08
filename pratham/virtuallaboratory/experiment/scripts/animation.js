// JavaScript Document
DE_ML = "262";
DE_MT = "270";
Shadow = 1;
Pause =0;
function PlaceSat(x,y,z) {
	newx = parseInt(DE_ML)+parseInt(x);
	newy = parseInt(DE_MT)-parseInt(y);
	document.getElementById("Sate").style.marginLeft = newx+"px";
	document.getElementById("Sate").style.marginTop = newy+"px";
	if (z < 0) {
		tempomax = (x*x) + (y*y);
		if (tempomax < 98*97) { // 6400 * 6400, perhaps more 'at-home' in constants.php?
//			document.getElementById("Sate").style.display="none";
			Shadow = 0;
			$("#Sate").fadeOut(100);
		}
		else {
			Shadow = 1;
			$("#Sate").fadeIn(100);
		}
    }
	else {
		Shadow = 1;
		$("#Sate").fadeIn(100);
	}
	
}
ML_LOW = 0;
ML_HIGH = 534;
function PlaceSatTheta(Theta) {
	ML_CURR = Theta*(ML_HIGH-ML_LOW)/360;
	Theta = Theta*3.14159/180;
	document.getElementById("SetPosition").style.marginLeft=ML_CURR+"px";
	if (TYPE ==0) {
		x = RADIUS * Math.sin(Theta);
    	y = RADIUS * Math.sin(ANGLE) * Math.cos(Theta);
	    z = RADIUS * Math.cos(ANGLE) * Math.cos(Theta);
		t1 = Shadow * Math.cos(Theta) * Math.cos(ANGLE);
		t2 = -t1;
        t3 = Shadow * (-Math.sin(Theta)) * Math.cos(ANGLE);
		t4 = -t3;
		if ((t1>=0)&&(t3>=0)) {
			document.getElementById("Sate").style.backgroundImage="url(images/135.png)"
		}
		else if((t1>=0)&&(t4>=0)){
			document.getElementById("Sate").style.backgroundImage="url(images/145.png)"
		}
		else if((t2>=0)&&(t4>=0)){
			document.getElementById("Sate").style.backgroundImage="url(images/245.png)"
		}
		else if((t2>=0)&&(t3>=0)){
			document.getElementById("Sate").style.backgroundImage="url(images/235.png)"
		}
	}
	else {
		x =  - RADIUS * Math.sin(Theta) * Math.sin(ANGLE) ;
    	y = RADIUS * Math.cos(Theta);
	    z = RADIUS * Math.cos(ANGLE) * Math.sin(Theta);
		
		t1 = Shadow * Math.sin(Theta) * Math.cos(ANGLE);
		t2 = -t1;
        t3 = Shadow * Math.cos(Theta) * Math.cos(ANGLE);
		t4 = -t3;
		
		if ((t1>=0)&&(t3>=0)) {
			document.getElementById("Sate").style.backgroundImage="url(images/135.png)"
		}
		else if((t1>=0)&&(t4>=0)){
			document.getElementById("Sate").style.backgroundImage="url(images/145.png)"
		}
		else if((t2>=0)&&(t4>=0)){
			document.getElementById("Sate").style.backgroundImage="url(images/245.png)"
		}
		else if((t2>=0)&&(t3>=0)){
			document.getElementById("Sate").style.backgroundImage="url(images/235.png)"
		}
	}
	PlaceSat(x,y,z);
}
ThetaN =0;
function PlaceSatAnimate() {
	if (Pause ==0) {
		if (ThetaN == 360) ThetaN = 0;
		ThetaN++;
		PlaceSatTheta(ThetaN);
	}
	setTimeout('PlaceSatAnimate()', 10);
}
function SetPause(x) {
		Pause =x;
}