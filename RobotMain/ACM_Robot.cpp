// 
// 
// 

#include "ACM_Robot.h"

ACM_Robot::ACM_Robot(){

	myServo = Servo();
	InitializeMotors();
	AssignPingPin(7);
	AssignServo(A5);
	Halt();
}


ACM_Robot::~ACM_Robot(){
}

void ACM_Robot::InitializeMotors()
{
	ChannelA = MotorChannel(12, 3, 9, 0);
	pinMode(ChannelA.DirectionPin,OUTPUT);
	pinMode(ChannelA.BrakePin,OUTPUT);
	ChannelB = MotorChannel(13, 11, 8, 1);
	pinMode(ChannelB.DirectionPin,OUTPUT);
	pinMode(ChannelB.BrakePin,OUTPUT);
}

void ACM_Robot::Halt()
{
	digitalWrite(ChannelA.BrakePin, HIGH);  //Engage the Brake for Channel A
	digitalWrite(ChannelB.BrakePin, HIGH);  //Engage the Brake for Channel B
}

void ACM_Robot::DriveForward( word speed )
{
	//Motor A forward @ speed
	digitalWrite(ChannelA.DirectionPin, HIGH); //Establishes forward direction of Channel A
	digitalWrite(ChannelA.BrakePin, LOW);   //Disengage the Brake for Channel A
	analogWrite(ChannelA.SpeedPin, speed);   //Spins the motor on Channel A at full speed

	//Motor B forward @ speed
	digitalWrite(ChannelB.DirectionPin, HIGH); //Establishes forward direction of Channel B
	digitalWrite(ChannelB.BrakePin, LOW);   //Disengage the Brake for Channel B
	analogWrite(ChannelB.SpeedPin, speed);   //Spins the motor on Channel B at full speed
}

void ACM_Robot::DriveForwardFull()
{
	DriveForward(255);
}

bool ACM_Robot::RotatePingSensor(int angle)
{
	// TODO: write rotation code for arduino
	//myServo.write( angle );
	analogWrite(A5,angle);
	return true;
}

void ACM_Robot::MotorFailDetected()
{
	// TODO: what to do when a motor fails...
}

void ACM_Robot::Scan(int min_angle, int max_angle)
{
	// Robot is going to rotate the ping sensor
	if (!RotatePingSensor(min_angle))
		MotorFailDetected();
	// Robot cycles through angles from min to max
	//  and fills the Distances list with each distance.
	for (int i = 0; i < 9; i++)
	{
		// Send a message to the ping sensor to return
		//  a value and store it in the list
		Distances[i] = Ping();
		if (!RotatePingSensor(i))
			MotorFailDetected();

		Serial.println(Distances[i]);
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
