#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     bottomLimitSwitch, sensorTouch)
#pragma config(Sensor, S3,     topLimitSwitch, sensorTouch)
#pragma config(Sensor, S4,     IrSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          IrScanner,     tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     lift,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     nada,          tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c";
#include "MoveSingleTiming.c";

// buttons should be an enum, but compiler wasn't handling properly...
static const short X_Btn = 1;
static const short A_Btn = 2;
static const short Y_Btn = 4;
static const short B_Btn = 3;
static const short TopLeft_Btn = 5;
static const short TopRight_Btn = 6;
static const short LowLeft_Btn = 7;
static const short LowRight_Btn = 8;
static const short Back_Btn = 9;
static const short Start_Btn = 10;
static const short LJoyPress_Btn = 11;
static const short RJoyPress_Btn = 12;


#define DRIVE_STOP_BTN  joy1Btn(A_Btn)
#define DRIVE_BOOST_BTN joy1Btn(LowRight_Btn)
#define DRIVE_FINE_BTN  joy1Btn(TopRight_Btn)
#define joyLeft joystick.joy1_y1
#define joyRight joystick.joy1_y2
#define LIFT_RAISE joy2Btn(TopLeft_Btn)
#define LIFT_LOWER joy2Btn(LowLeft_Btn)
#define ARRAY_LENGTH(x) ((sizeof(x))/(sizeof(x[0])))
#define AUTO_LIFT_SPEED 50
#define TWEAK_LIFT_SPEED 70

float joystickMotorMapping(short controlInput, float maxOutput_pct, short deadzone)
{
    float output;

    if (controlInput <= -128 + deadzone)
    {
        output = -maxOutput_pct;
    }
    else if (( controlInput >= -deadzone)
        && ( controlInput <= deadzone))
    {
        output = 0;
    }
    else if (controlInput >= 127 - deadzone)
    {
        output = maxOutput_pct;
    }
    else if (controlInput < -deadzone)
    {
        output = (-maxOutput_pct / (-128 + 2*deadzone)) * (controlInput + deadzone);
    }
    else
    {
        output = (-maxOutput_pct / (-127 + 2*deadzone)) * (controlInput + deadzone);
    }

    return output;
}


task main()
{
    int lastCmdTweak = 1;
    motor[lift] = 0;
    nMotorEncoder[lift] = 0;
    int encoderTargets[] = {0,11171,23648};
    int targetIndex = 0;
    int length = ARRAY_LENGTH(encoderTargets);
    char    buffer[16];

    while(true)
    {
        int deadzone = 5;

        getJoystickSettings(joystick);

        float FullSpeed_pct = 70;

        if ((DRIVE_STOP_BTN)
           ||bDisconnected)
        {
            driveStop();
        }
        else
        {
            if (DRIVE_BOOST_BTN)
            {
                FullSpeed_pct = 100;
            }
            else if (DRIVE_FINE_BTN)
            {
                FullSpeed_pct = 40;
            }
            drive(joystickMotorMapping(joyLeft, FullSpeed_pct, deadzone),
                  joystickMotorMapping(joyRight, FullSpeed_pct, deadzone));
         }

        if (joystick.joy2_TopHat == 0)
        {
            lastCmdTweak = 1;
            motor[lift] = TWEAK_LIFT_SPEED;
            nxtDisplayBigTextLine(5 , "up" );
        }
        else if ((joystick.joy2_TopHat == 4)
          &&  (SensorValue[bottomLimitSwitch] == 0))
        {
            lastCmdTweak = 1;
            motor[lift] = -TWEAK_LIFT_SPEED;
            nxtDisplayBigTextLine(5 , "down" );
        }
       else if(LIFT_RAISE)
       {
           if((targetIndex+1) < length)
           {
               lastCmdTweak = 0;
               targetIndex++;
               motor[lift] = AUTO_LIFT_SPEED;
               nMotorEncoderTarget[lift] = encoderTargets[targetIndex];
               nxtDisplayBigTextLine(5 , "i-up" );

            }
       }
       else if (SensorValue[bottomLimitSwitch] != 0)
       {
           nMotorEncoder[lift] = 0;
           motor[lift] = 0;
       }
       else if(LIFT_LOWER)
       {
            if(targetIndex > 0)
            {
                lastCmdTweak = 0;
                targetIndex--;
                motor[lift] = -AUTO_LIFT_SPEED;
                nMotorEncoderTarget[lift] = encoderTargets[targetIndex];
                nxtDisplayBigTextLine(5 , "i-down" );

            }
       }
       else if (lastCmdTweak)
       {
               motor[lift] = 0;

       }
        sprintf(buffer, "%d", encoderTargets[targetIndex]);
        nxtDisplayBigTextLine(3 , buffer );
        sprintf(buffer, "%d", nMotorEncoder[lift]);
        nxtDisplayBigTextLine(1 , buffer );

    }
}
