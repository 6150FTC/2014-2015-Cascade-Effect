void BaseProgram()
{
    waitForStart();
    straight(70,39);
    wait1Msec(200);
    pivot(100,90);
    wait1Msec(200);
    while(!joy1Btn(2));
    straight(70,-38);
    wait1Msec(500);
    pivot(70,-90);
    wait1Msec(200);
    while(!joy1Btn(2));
    straight(70,58);
    wait1Msec(200);
    //drop ball in 60
    straight(70,-6);
    wait1Msec(200);
    spin(70,180);
    while(!joy1Btn(2));
    straight(70,-14);
    wait1Msec(500);
    //use grabber to get the rolling goal
    straight(70,67);
    wait1Msec(200);
    spin(70,-45);
    wait1Msec(200);
    straight(70,38);
    wait1Msec(200);
    spin(70,-135);
}