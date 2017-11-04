
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
    if(distance_inch < 0)
    {
        speed_pct = -speed_pct;
        distance_inch = -distance_inch;
    }
    drive(speed_pct,speed_pct);
    wait1Msec(3302*(distance_inch/abs(speed_pct))+11.15);
    driveStop();
}
/*
same as pivot except radius is halved
causing constant to be halved
new constant = 446.596
left turns are signified by positive turn_deg, while right turns are signified by negative turn_deg
all sign checks are used to make sure that parameters for used methods are within the respectived method's domain when being applied later on
*/
void spin(float speed_pct, float turn_deg)
{
    if(turn_deg > 0)
    {
          drive(-speed_pct,speed_pct);
    }
    else
    {
        drive(speed_pct,-speed_pct);
        turn_deg = -turn_deg;
    }
    //449.596 was previous slope coefficeint based on estimate from drive
    wait1Msec(478.50 *(turn_deg/abs(speed_pct))+11.15);
    driveStop();


}

/*
radius = 15.5 inches
180 degree turn = 48.69 inches of coverage by outer wheel
substituted proportion for figuring out degrees of coverage into straight wait1Msec formula
constant = 893.191
left turns are signified by positive turn_deg, while right turns are signified by negative turn_deg
all sign checks are used to make sure that parameters for used methods are within the respectived method's domain when being applied later on
*/
void pivot(float speed_pct, float turn_deg)
{
if(turn_deg > 0)
    {
          drive(0,speed_pct);
    }
    else
    {
        drive(speed_pct,0);
        turn_deg = -turn_deg;
    }
    //893.191 was previous slope coefficeint based on estimate from drive
    wait1Msec(956.991 *(turn_deg/abs(speed_pct))+11.15);
    driveStop();


}
