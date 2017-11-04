void RampProgram(bool grabBase)
{
    straight(70, 80);
	liftHeight(100,11.811);
	openScoopGate(true);
	wait1Msec(500);
    straight(70, -6);
    if(grabBase)
    {
	    spin(70,180);
	    straight(70,-14);
		grabTubeBase(true);
		wait1Msec(200);
	    pivot(70,-45);
	    straight(70,33);
	    pivot(70,45);
	    straight(70,42);
	    spin(70,90);
	    grabTubeBase(false);
	    wait1Msec(200);
		resetLift();
	}
}