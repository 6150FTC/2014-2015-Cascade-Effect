#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop, reversed)
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
    }
}
