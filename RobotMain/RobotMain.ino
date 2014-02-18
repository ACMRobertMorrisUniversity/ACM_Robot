#include "ACM_Robot.h";

ACM_Robot robot = ACM_Robot();

int i = 0;

void setup()
{
	Serial.begin(9600);
	robot.RotatePingSensor(0);
}

void loop()
{
	if( i > 1024 )
		i = 0;
	i++;
	robot.RotatePingSensor(i);
	delay(150);
	Serial.println(i);
  /* add main program code here */

}
