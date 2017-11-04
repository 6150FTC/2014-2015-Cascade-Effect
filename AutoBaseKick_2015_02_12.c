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
		straight(70,-30);
		spin(70,-86);
		//liftHeight(100,12);
		//wait1Msec(200);
		straight(70,57);
		straight(50,5);
		openScoopGate(down);
		wait1Msec(1000);
		straight(70,-6);
		spin(70,-180);
		straight(25,-7);
	    if(grabBase)
	    {
			grabTubeBase(true);
			wait1Msec(1000);
			straight(70,56);
			spin(70,-55);
			straight(70,38);
			spin(70,-125);
			wait1Msec(200);
			straight(70,-2);
			grabTubeBase(false);
			wait1Msec(1000);
	    }
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
    		spin(70, -105);
            straight(40,-1.2);
            liftHeight(70,35);//37.7


            //straight(30,2);
            openScoopGate(down);
            wait1Msec(2000);
            straight(70,-8);
            //liftHeight(70,25);//37.7
            pivot(70,-90);
            pivot(70,105);
            straight(70,13);
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
          	/*pivot(70, -shiftover);
            spin(70, shiftover);
            */
            //spin(40,-5);
            straight(70,17);
            spin(100, -50);

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
    //resetLift();
}
