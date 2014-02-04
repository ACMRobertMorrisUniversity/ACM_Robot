#include "ACM_Robot.h"


ACM_Robot::ACM_Robot()
{
}


ACM_Robot::~ACM_Robot()
{
}

void ACM_Robot::MoveForward(float time)
{
	// TODO: write the move code...
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
		Distances.push_back(Ping());
		if (!RotatePingSensor(i))
			MotorFailDetected();
	}
}

float ACM_Robot::Ping()
{
	// TODO: Write Arduino code to make the ping sensor
	//   work.
	return 0.0f;
}