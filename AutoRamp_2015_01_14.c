void RampProgram()
{
    waitForStart();
    straight(70, 80);
    wait1Msec(200);
    straight(70, -6);
    wait1Msec(200);
    spin(70,180);
    wait1Msec(200);
    straight(70,-14);
    wait1Msec(200);
    pivot(70,-45);
    wait1Msec(200);
    straight(70,33);
    wait1Msec(200);
    pivot(70,45);
    wait1Msec(200);
    straight(70,42);
    wait1Msec(200);
    spin(70,90);
}