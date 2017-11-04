#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     bottomLimitSwitch, sensorTouch)
#pragma config(Sensor, S3,     topLimitSwitch, sensorTouch)
#pragma config(Sensor, S4,     IrSeeker,       sensorHiTechnicIRSeeker1200)
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

/*
Make sure to check autonomous include file names for the latest and most stable autonomous filename
 and that the latest and most stable autonomous files do NOT have a task main() method in them  as there
 should only be one main method which is included in this Program Selector file.
*/
#include "JoystickDriver.c";
#include "AutoBaseKick_2015_01_14.c"
#include "AutoRamp_2015_01_14.c"
#include "DriveSingleencoder.c"
//#include "MoveSingleTiming.c"

task main()
{
    static const short NoButton         = -1;
	static const short ExitButton       =  0;
	static const short RightButton      =  1;
	static const short LeftButton       =  2;
	static const short EnterButton      =  3;
    static const short InitialUninited   =  0;
    static const short ramp        		=  1;
    static const short base         	=  2;

    int action = InitialUninited;
    int actionSelector = 1;
    char * actionString = "none";

    while (actionSelector)
    {
	   nxtDisplayBigTextLine(4, actionString);
       switch(nNxtButtonPressed)
       {
           case ExitButton:
                action = InitialUninited;
                actionString = "none"; //Click the bottom button (or the back button if  you prefer)  to exit the program. Will print  "none" on NXT screen.
                break;
           case RightButton:
                action = ramp;
                actionString = "ramp"; //Click the right arrow on nxt to select the ramp autonomous. Will print "ramp" on NXT screen.
                break;
           case LeftButton:
                action = base;
                actionString = "base"; // Click the left arrow button on nxt to select the base autonomous. Will print "base" on NXT screen.
                break;
           case EnterButton:
                if(action != InitialUninited) // Click the  middle button (or select button if you prefer) to finalize the autonomous that you want to run. Will print nothing on NXT screen.
                {
                    actionSelector = 0;
                }
                break;
        }
   }
	/*
	Waiting for the start signal to the samatha after program has been selected.
	Pressing the back button will still exit  this programming if deemed unnecessary.
	*/
   waitForStart();

   if(action == ramp)
   {
		RampProgram();
   }
   else if(action == base)
   {
       BaseProgram();
   }
   else
   {
        actionString = "Error"; // Will print "Error" on NXT screen due to failure of launch of requested autonomous.
   }

}
