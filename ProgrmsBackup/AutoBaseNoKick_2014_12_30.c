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
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)

#include "JoystickDriver.c";
#include "DriveSingleencoder.c"

task main()
{
    waitForStart();
    straight(70,43);
    spin(70,-90);
    straight(70,34);
    straight(70,-58);
    spin(70, -90);
    straight(70,70);
//Ball Drop
    straight(70,-6);
    spin(70,180);
//Option 1 If obstructed
//Do Nothing
//Option 2 If not obstructed
    straight(70,-14);
//grabber process
    straight(70,95);
    spin(70,180);
//Reverse grabber
}
