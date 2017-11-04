
//First cut 10/7/14

void drive(float left_pct, float right_pct)
{
    motor[left] = left_pct;
    motor[right] = right_pct;
}

void driveStop()
{
    drive(0, 0);
}

void straight(float speed_pct, float distance_inch)
{
    nMotorEncoder[left] = 0;
    nMotorEncoder[right] = 0;
    short offset = -25;
    float leftSpeed;
    if(speed_pct > 0)
        leftSpeed = speed_pct - offset;
    else
        leftSpeed = speed_pct + offset;
    if(distance_inch < 0)
    {
        leftSpeed = -leftSpeed;
        speed_pct = -speed_pct;
        distance_inch = -distance_inch;
    }
    drive(leftSpeed, speed_pct);
    //127.064 is the previous slope value based on test program
    if (speed_pct == 0)
    { /* avoid inf loop */}
        else if (speed_pct > 0)
    {
    while(nMotorEncoder[left] < (distance_inch * 118.4286))
        {
     }
 }
 else
 {
    while(nMotorEncoder[left] > -(distance_inch * 118.4286))
        {
     }
     }
   driveStop();
}

void spin(float speed_pct, float turn_deg)
{
int whichEncoder = left;
nMotorEncoder[left] = 0;
nMotorEncoder[right] = 0;
if(turn_deg > 0)
    {
        whichEncoder = right;
          drive(-speed_pct,speed_pct);
    }
    else
    {
        drive(speed_pct,-speed_pct);
        turn_deg = -turn_deg;
    }
    //17.4674 was the previously used slope
   while( nMotorEncoder[whichEncoder] < (turn_deg * 18))
   {

   }
    driveStop();
}

void pivot(float speed_pct, float turn_deg)
{
int whichEncoder = left;
nMotorEncoder[left] = 0;
nMotorEncoder[right] = 0;
float multiplyer;
if(turn_deg > 0)
    {
         whichEncoder = right;
         drive(0,speed_pct);
         multiplyer = 41;
    }
    else
    {
        drive(speed_pct,0);
        turn_deg = -turn_deg;
        multiplyer = 36;
    }
    //34.93483489 was previously used slope
    while( nMotorEncoder[whichEncoder] < (turn_deg * multiplyer))
    {

    }
    driveStop();
}
void liftHeight(float power,float height)
{
   if((height * 960) > nMotorEncoder[lift])
    {
        while((height * 1060) > nMotorEncoder[lift])
        {
            motor[lift] = abs(power);
        }
    }
    else
    {
        while((height * 1060) < nMotorEncoder[lift])
        {
            motor[lift] = -(abs(power));
            if(SensorValue[bottomLimitSwitch] != 0)
            {
                motor[lift] = 0;
                nMotorEncoder[lift] = 0;
            }
        }
    }
    motor[lift] = 0;
}
void resetLift()
{
    while(SensorValue[bottomLimitSwitch] == 0)
    {
        motor[lift] = -70;
    }
    motor[lift] = 0;
    nMotorEncoder[lift] = 0;

}
void openScoopGate(bool state)
{
    if(state)
    {
        servo[ScoopGate] = 180;
    }
    else
    {
        servo[ScoopGate] = 240;
    }
}

void grabTubeBase(bool state)
{
    if(state)
    {
        servo[TubeGrab] = 150;
    }
    else
    {
        servo[TubeGrab] = 240;
    }
}
