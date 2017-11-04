#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S2,     bottomLimitSwitch, sensorTouch)
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

task main()
{


    while(SensorValue[bottomLimitSwitch] == 0)
    {
        motor[lift] = -100;
    }
    motor[lift] = 0;
    nMotorEncoder[lift] = 0;


}
