#include "ACM_Robot.h";

ACM_Robot robot;
int i = 0; int displayDist = 0;

void setup()
{
	robot.Initialize();
	//robot.myServo.attach(3);
	Serial.begin(19200);
}

void loop()
{
	if( i >= 150 )
		i = 0;
	i+=5;
	//robot.RotatePingSensor(i);
	robot.Scan(10,150);
	delay(1000);
	robot.DriveForwardFull();
	delay(500);
	robot.Halt();
	delay(1000);
}
