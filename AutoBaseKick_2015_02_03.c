float shiftover = 60;
float jiggle = 30;
void BaseWithKickProgram(bool grabBase)
{
    liftHeight(100,6);
    grabTubeBase(false);
    wait1Msec(200);
    openScoopGate(stable);
    wait1Msec(200);
    straight(70,18);
	if(SensorValue[ultraSonic]  <  255)
	{
		//when in position 1
		straight(70, 17);
		pivot(100,90);
		straight(70,-29);
		spin(70,-110);
		liftHeight(100,11.811);
		wait1Msec(200);
		straight(70,52);
		straight(50,4);
		openScoopGate(up);
		wait1Msec(1000);
		straight(70,-6);
		spin(70,-180);
		straight(35,-6);
	}
	else
	{
		grabBase = false;
		pivot(70, shiftover);
        spin(70, -shiftover);
		//code that guides robot until grabber and while also kicking kickstand in position 2 and position 3.
		if (SensorValue[ultraSonic] < 255)
        {
            //if less than 255 (sensor shows value) the tower is in position 3
        	/*	pivot(70, -shiftover);
        		straight(70,2);
            spin(70, shiftover);
            straight(70,5);
            pivot(70, -90);
            */
            //creating new position three because of 120cm goal
           	pivot(70, 90);
    		spin(70, -90);
            straight(70,-2);
            liftHeight(70,37.7);
            straight(30,2);
            openScoopGate(down);
            wait1Msec(1000);
            straight(70,-6);
            pivot(70,-90);
            pivot(70,90);
            straight(70,4);
            spin(100,-90);
            //waiting for ball to drop in 120 cm goal
            /*straight(70,);
            pivot(70, -shiftover);
            spin(70, shiftover);
            pivot(70, -shiftover);
        		straight(70,2);
            spin(70, shiftover);
            straight(70,5);
            pivot(70, -90);
            */


        }
		else
        {
        	//else the center is in postion 2
          	pivot(70, -shiftover);
            spin(70, shiftover);
            straight(70,5);
            pivot(100, -90);
       	}
  }
}
	/*}
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

}*/
