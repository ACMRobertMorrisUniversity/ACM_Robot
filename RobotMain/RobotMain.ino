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
	
	robot.Scan(10,150);
	delay( 500 );
}
