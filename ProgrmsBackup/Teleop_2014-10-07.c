#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c";
#include "MoveSingleTiming.c";

#define joyLeft joystick.joy1_y1
#define joyRight joystick.joy1_y2

void joyToMovement(short leftSpeed, short rightSpeed, int deadzone)
{
	if ((-deadzone < leftSpeed)
		&& (leftSpeed < deadzone))
	{
		leftSpeed=0;
	}
	if ((-deadzone < rightSpeed)
		&& (rightSpeed < deadzone))
	{
		rightSpeed=0;
	}
	drive(leftSpeed, rightSpeed);

}

task main()
{
    while(true)
    {
	      getJoystickSettings(joystick);
	      int deadzone = 5;
	      joyToMovement(joyLeft, joyRight, deadzone);
	  }
}
