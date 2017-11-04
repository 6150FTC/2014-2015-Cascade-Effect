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
//#include "MoveSingleTiming.c"
#include "DriveSingleencoder.c"
//#include "DriveSingleencoderLeftSpeed.c"

task main()
{
    resetLift();

    //resetLift();
    waitForStart();
    liftHeight(100,6);
    grabTubeBase(false);
    wait1Msec(200);
    openScoopGate(false);
    wait1Msec(200);
    straight(70,37);
   // wait1Msec(200);
    //liftHeight(100,12);
    wait1Msec(200);
    pivot(100,90);
    wait1Msec(200);
    while(!joy1Btn(2));
    //while(!joy1Btn(2));
    straight(70,-29);
    wait1Msec(500);
    while(!joy1Btn(2));
    spin(70,-90);
    wait1Msec(200);
    //while(!joy1Btn(2));
    liftHeight(100,23.622);
    wait1Msec(200);
    straight(70,52);
    wait1Msec(200);
    straight(50,4);
    while(!joy1Btn(2));
    //drop ball in 60
    openScoopGate(true);
    wait1Msec(1000);
    //while(!joy1Btn(2));
    straight(70,-6);
    wait1Msec(200);
    spin(70,-180);
    //while(!joy1Btn(2));
    straight(35,-6);
    wait1Msec(500);
    grabTubeBase(true);
    //wait1Msec(500);
    //liftHeight(100,6);
    wait1Msec(200);
    //use grabber to get the rolling goal
    straight(70,64);
    wait1Msec(200);
    spin(70,-45);
    wait1Msec(200);
    straight(70,38);
    wait1Msec(200);
    spin(70,-135);
    wait1Msec(200);
    grabTubeBase(false);
    wait1Msec(1000);
    resetLift();
//    straight(70,16);//34
//    wait1Msec(200);
//    straight(70,-38);//-58
//    wait1Msec(200);
//    spin(70, -90);
//    wait1Msec(200);
//    straight(70,70);
//    wait1Msec(200);
////Ball Drop
//    straight(70,-6);
//    wait1Msec(200);
//    spin(70,180);
//    wait1Msec(200);
////Option 1 If obstructed
////Do Nothing
////Option 2 If not obstructed
//    straight(70,-14);
//    wait1Msec(200);
////grabber process
//    straight(70,95);
//    wait1Msec(200);
//    spin(70,-180);
////Reverse grabber
}
