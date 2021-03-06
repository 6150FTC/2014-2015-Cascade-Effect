void BaseWithKickProgram(bool grabBase)
{
    resetLift();
    liftHeight(100,6);
    grabTubeBase(false);
    wait1Msec(200);
    openScoopGate(false);
    wait1Msec(200);
    straight(70,18);
	if(SensorValue[IrSeeker] == 0)
	{
		straight(70, 19)
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
		//code that guides robot until grabber and while also kicking kickstand in position 2 and position 3.
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