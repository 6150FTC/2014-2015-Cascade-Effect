#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     IrSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          IrScanner,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c";
#include "MoveSingleTiming.c";

task main()
{
    char    buffer[16];
	int     x;

    nMotorEncoder[IrSeeker] = 0;
    waitForStart();

    while (true)
    {
        motor[motorA] = 0;
        while (SensorValue[Irseeker] == 0)
        {
            nxtDisplayBigTextLine(3, "No IR" );
        }

        while (SensorValue[IrSeeker] < 5)
        {

            motor[motorA] = -40;
	        nMotorEncoderTarget[IrSeeker] = nMotorEncoder[IrSeeker] + 10;
	        while (nMotorRunState[IrSeeker] != runStateIdle)
	        {
	        }
            motor[motorA] = 0;
        }
        while (SensorValue[IrSeeker] > 5)
        {

            motor[motorA] = 40;
	        nMotorEncoderTarget[IrSeeker] = nMotorEncoder[IrSeeker] - 10;
	        while (nMotorRunState[IrSeeker] != runStateIdle)
	        {
	        }
            motor[motorA] = 0;
        }
       // Sould be in zone 5 now
        motor[motorA] = -40;
        while (SensorValue[IrSeeker] == 5)
        {
        }
         motor[motorA] = 0;

         long leftSide = nMotorEncoder[motorA];

        motor[motorA] = 40;
       while (SensorValue[IrSeeker] != 5)
       {}

	    // first while loop is to get it back to 5 second is to exit 5 on other side
        while(SensorValue[IrSeeker] == 5)
        {
	    }
        motor[motorA] = 0;

        long rightSide = nMotorEncoder[motorA];

        float orientation = 0.6 * (leftSide + rightSide) / 2.0;

	    sprintf(buffer, "%d", leftSide);
        nxtDisplayBigTextLine(1 , buffer );
	    sprintf(buffer, "%d", rightSide);
        nxtDisplayBigTextLine(3 , buffer );
	    sprintf(buffer, "%f", orientation);
        nxtDisplayBigTextLine(5 , buffer );
    }
}
