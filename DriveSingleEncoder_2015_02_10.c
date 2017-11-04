//First cut 10/7/14
    static const short up               =  1;
    static const short stable           =  0;
    static const short down             = -1;

void drive(float left_pct, float right_pct)
{
    motor[left] = left_pct;
    motor[right] = right_pct;
}

void driveStop()
{
    drive(0, 0);
	wait1Msec(200);
}

void straight(float speed_pct, float distance_inch)
{
    float balanceAdjustmentPercent = .64; //percent to adjust power to counter weight imbalance. float based on power of 70;
    nMotorEncoder[left] = 0;
    nMotorEncoder[right] = 0;
    if(distance_inch < 0)
    {
        speed_pct = -speed_pct;
        distance_inch = -distance_inch;
    }
    drive((balanceAdjustmentPercent * speed_pct), speed_pct);
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
float multiplyer;
if(turn_deg > 0)
    {//greater than is a left turn
          whichEncoder = right;
          drive(-speed_pct,speed_pct);
          multiplyer = 17.36;
    }
    else
    {// less than is a right turn
        drive(speed_pct,-speed_pct);
        turn_deg = -turn_deg;
        multiplyer = 17.4;
    }
   while( nMotorEncoder[whichEncoder] < (turn_deg * multiplyer))
   {

   }
    driveStop();
    wait1Msec(200);
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
         multiplyer = 38.1;//41 was the previous multiplyer until tightening of treads changed calibration
    }
    else
    {
        drive(speed_pct,0);
        turn_deg = -turn_deg;
        multiplyer = 33.8;//32.7
    }
    //34.93483489 was previously used slope
    while( nMotorEncoder[whichEncoder] < (turn_deg * multiplyer))
    {

    }
    driveStop();
    wait1Msec(200);
}
void liftHeight(float power,float height)
{
    short multiplyer = 1100; //1060
   if((height * multiplyer) > nMotorEncoder[lift])
    {
        while((height * multiplyer) > nMotorEncoder[lift])
        {
            motor[lift] = abs(power);
        }
    }
    else
    {
        while((height * multiplyer) < nMotorEncoder[lift])
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
        motor[lift] = -100;
    }
    motor[lift] = 0;
    nMotorEncoder[lift] = 0;
}
void openScoopGate(int state)
{
    if(state == 1)
    {
        servo[ScoopGate] = 70;//Scoop gate up
    }
    else if(state == 0)//
    {
        servo[ScoopGate] = 115;//Scoop gate stable
    }
    else
    {
        servo[ScoopGate] = 160;//Scoop gate down
    }
}

void grabTubeBase(bool state)
{
    if(state)
    {
        servo[TubeGrab] = 110;
    }
    else
    {
        servo[TubeGrab] = 250;
    }
}
