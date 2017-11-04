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

#include "JoystickDriver.c";
#include "MoveSingleTiming.c"
//#include "DriveSingleencoder.c"


task main()
{
    static const short NoButton         = -1;
	static const short ExitButton       =  0;
	static const short RightButton      =  1;
	static const short LeftButton       =  2;
	static const short EnterButton      =  3;
    static const short InitialUninted   =  0;
    static const short RightSpin        =  1;
    static const short LeftSpin         =  2;

    int action = InitialUninted;
    int actionSelector = 1;

    while(actionSelector)
   {
       switch(nNxtButtonPressed)
       {
           case ExitButton:
                action = InitialUninted;
                nxtDisplayBigTextLine(4, "none");
                break;
           case RightButton:
                action = RightSpin;
                nxtDisplayBigTextLine(4, "RightSpin");
                break;
           case LeftButton:
                action = LeftSpin;
                nxtDisplayBigTextLine(4, "LeftSpin");
                break;
           case EnterButton:
                if(action != InitialUninted)
                {
                    actionSelector = 0;
                }
                break;
        }
   }

   waitForStart();

   if(action == RightSpin)
   {
       spin(70,-180);
   }
   else if(action == LeftSpin)
   {
       spin(70, 180);
   }
   else
   {
        nxtDisplayBigTextLine(6, "Error");
   }

}
