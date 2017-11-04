
void RampProgram(bool grabBase)
{
    straight(70, 74);
	liftHeight(100,23.622);
	straight(40,8);
	openScoopGate(up);
	wait1Msec(500);
    straight(70,-6);
    if(grabBase)
    {
	    spin(70,180);
	    straight(20,-14);
		grabTubeBase(true);
		wait1Msec(200);
	    pivot(70,-45);
	    straight(70,33);
	    pivot(70,45);
	    straight(70,51);
	    spin(70,90);
	    grabTubeBase(false);
	    wait1Msec(200);
	}
}
