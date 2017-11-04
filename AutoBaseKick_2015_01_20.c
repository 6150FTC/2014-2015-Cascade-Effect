float shiftover = 60;
float jiggle = 30;

void BaseWithKickProgram(bool grabBase)
{
    resetLift();
    liftHeight(100,6);
    grabTubeBase(false);
    wait1Msec(200);
    openScoopGate(false);
    wait1Msec(200);
    straight(70,18);
	if(SensorValue[ultraSonic]  <  255)
	{
		straight(70, 19);
		pivot(100,90);
		//while(!joy1Btn(2));
		straight(70,-29);
		spin(70,-90);
		//while(!joy1Btn(2));
		liftHeight(100,23.622);
		wait1Msec(200);
		straight(70,52);
		straight(50,4);
		//drop ball in 60
		openScoopGate(true);
		wait1Msec(1000);
		//while(!joy1Btn(2));
		straight(70,-6);
		spin(70,-180);
		//while(!joy1Btn(2));
		straight(35,-6);
	}
	else
	{
		pivot(70, shiftover);
        spin(70, -shiftover);
		//code that guides robot until grabber and while also kicking kickstand in position 2 and position 3.
		if (SensorValue[ultraSonic] < 255)
        {
            //if less than 255 the tower is in position 3
            pivot(70, -shiftover);
            spin(70, shiftover);
            straight(70,24);
            pivot(70,-45);
        }
        else
        {
            //position 2
            pivot(70, -jiggle);
            spin(70, jiggle);
            straight(70, 18);
            pivot(70, -60);

			/*pivot(70, -shiftover);
			spin(70,shiftover);
			straight(70, 24);
			pivot(70, 85);
			straight(70, -27);
			spin(70,-85);
			straight(70,60);
			straight(70,4);
			openScoopGate(true);
			wait1Msec(200);
			straight(70,-6);
			spin(70,-180);
			straight(35,-6);
			*/
        }
	}
	if(grabBase)
	{
		grabTubeBase(true);
		wait1Msec(200);
		straight(70,64);
		spin(70,-45);
		straight(70,38);
		spin(70,-135);
		grabTubeBase(false);
		wait1Msec(200);
		resetLift();
	}

}
