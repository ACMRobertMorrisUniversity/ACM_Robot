// 
// 
// 

#include "ACM_Robot.h"

ACM_Robot::ACM_Robot(){
	AssignPingPin(7);
	AssignRMotorPin(12);
	AssignLMotorPin(13);
	AssignRBrakePin(9);
	AssignLBrakePin(8);
	AssignChannelAPin(3);
	AssignChannelBPin(11);
	AssignServo(6);
}


ACM_Robot::~ACM_Robot(){
}

void ACM_Robot::MoveForward(float time)
{
	// TODO: write the move code...
	DriveForwardFull();
	delay(300);
}

bool ACM_Robot::RotatePingSensor(int angle)
{


	// TODO: write rotation code for arduino
	return true;
}

void ACM_Robot::MotorFailDetected()
{
	// TODO: what to do when a motor fails.
}

void ACM_Robot::Scan(int min_angle, int max_angle)
{
	// Robot is going to rotate the ping sensor
	if (!RotatePingSensor(min_angle))
		MotorFailDetected();
	// Robot cycles through angles from min to max
	//  and fills the Distances list with each distance.
	for (int i = min_angle; i < max_angle; i++)
	{
		// Send a message to the ping sensor to return
		//  a value and store it in the list
		//Distances.push_back(Ping());
		if (!RotatePingSensor(i))
			MotorFailDetected();
	}
}

long ACM_Robot::Ping()
{
	long duration;
	// Send out PING))) signal pulse
	pinMode(PingPin, OUTPUT);
	digitalWrite(PingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(PingPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(PingPin, LOW);

	//Get duration it takes to receive echo
	pinMode(PingPin, INPUT);
	duration = pulseIn(PingPin, HIGH);

	//Convert duration into distance
	//Distance = duration / 29 / 2;
	long temp = (duration / 29 / 2);
	
	return temp;
}
