void BaseWithKickProgram(bool grabBase)
{
    liftHeight(100,6);
    straight(70,12);
    if(SensorValue[ultraSonic] <255)
    {
        //if less than 255 it should be about 110 which means position 1
		straight(70, 25);
		wait1Msec(200);
		pivot(100,90);
		wait1Msec(200);
		//while(!joy1Btn(2));
		straight(70,-29);
		wait1Msec(500);
		spin(70,-90);
		wait1Msec(200);
		//while(!joy1Btn(2));
		liftHeight(100,23.622);
		wait1Msec(200);
		straight(70,52);
		wait1Msec(200);
		straight(50,4);
		//drop ball in 60
		openScoopGate(true);
		wait1Msec(1000);
		//while(!joy1Btn(2));
		straight(70,-6);
		wait1Msec(200);
		spin(70,-180);
		//while(!joy1Btn(2));
		straight(35,-6);
		wait1Msec(500);
	}
	else
	{
        float shiftover = 60;
	    pivot(70,shiftover);
	    wait1Msec(200);
	    spin(70,-shiftover);
        wait1Msec(200);
	    if(SensorValue[ultraSonic] <255)
	    {
	        //if less than 255 the tower is in position 3
		    pivot(70,-shiftover);
		    wait1Msec(200);
		    spin(70,shiftover);
		    wait1Msec(200);
		    straight(70,24);
		    wait1Msec(200);
		    pivot(70,-45);
	    }
	    else
	    {
	        //position 2
		    float jiggle = 30;
		    pivot(70, -jiggle);
		    spin(70, jiggle);
		    wait1Msec(200);
		    straight(70,18);
		    wait1Msec(200);
		    pivot(70,-60);
        }
	}
	if(grabBase)
	{
		grabTubeBase(true);
		//wait1Msec(500);
		//liftHeight(100,6);
		wait1Msec(200);
		//use grabber to get the rolling goal
		straight(70,64);
		wait1Msec(200);
		spin(70,-45);
		wait1Msec(200);
		straight(70,38);
		wait1Msec(200);
		spin(70,-135);
		wait1Msec(200);
		grabTubeBase(false);
		wait1Msec(1000);
		resetLift();
	}

}
