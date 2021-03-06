#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S2,     bottomLimitSwitch, sensorTouch)
#pragma config(Sensor, S3,     topLimitSwitch, sensorTouch)
#pragma config(Sensor, S4,     ultraSonic,     sensorSONAR)
#pragma config(Motor,  motorA,          IrScanner,     tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     lift,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     nada,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    TubeGrab,             tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    ScoopGate,            tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Make sure to check autonomous include file names for the latest and most stable autonomous filename
 and that the latest and most stable autonomous files do NOT have a task main() method in them  as there
 should only be one main method which is included in this Program Selector file.
*/

#include "JoystickDriver.c";
#include "DriveSingleencoder.c"
//#include "MoveSingleTiming.c"

task main()
{
resetLift();
    waitForStart();
    liftHeight(100,1);
    wait1Msec(200);
    straight(70,12);
    if(SensorValue[ultraSonic] <255)
    {
        //if less than 255 it should be about 110 which means position 1
    }
    else
    {
	   //variable is for easier changing
	    wait1Msec(200);
        float shiftover = 60;
	    pivot(70,shiftover);
	    wait1Msec(200);
	    spin(70,-shiftover);
	    if(SensorValue[ultraSonic] <255)
	    {
	      //if less than 255 the tower is in position 3
		  wait1Msec(200);
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
	    wait1Msec(200);
	    float jiggle = 30;
	    pivot(70, -jiggle);
	    spin(70, jiggle);
	    wait1Msec(200);
	    straight(70,18);
	    wait1Msec(200);
	    pivot(70,-60);
        }
    }
}
