


#pragma once

#include "arduino.h"
#include "Servo.h"

/*/ 
	Function 		Channel A 	Channel B
	Direction 		Digital 12 	Digital 13
	Speed (PWM) 	Digital 3 	Digital 11
	Brake 			Digital 9 	Digital 8
	Current	Sensing	Analog 0 	Analog 1
/*/
struct MotorChannel
{
	MotorChannel()
	{
		MotorChannel( -1, -1, -1, -1 );
	}
	MotorChannel( int directionPin, int speedPin, int brakePin, int currentSensePin )
	{
		DirectionPin = directionPin; SpeedPin = speedPin; BrakePin = brakePin;
		CurrentSensePin = currentSensePin;
	}
	int DirectionPin;
	int SpeedPin;
	int BrakePin;
	int CurrentSensePin;
};

class ACM_Robot{
	// Robots Brain structures.
	float Distances[10];

	MotorChannel ChannelA;
	MotorChannel ChannelB;
	int PingPin;
	
	long PingDuration;
	void InitializeMotors();
	
public:
	ACM_Robot();
	~ACM_Robot();
	Servo myServo;
	bool RotatePingSensor(int angle);
	void Scan(int min_angle, int max_angle);
	void DriveForward(word speed);
	void DriveBackward(word speed);
	void DriveForwardFull();
	void Halt();
	long Ping();
	void MotorFailDetected();
	void Initialize();

	// Assign pins.
#pragma region AssignPins
	void AssignPingPin(int pin){
		PingPin = pin;
	}
	void AssignServo(int pin){
		myServo.attach(pin);
		//pinMode(pin,OUTPUT);
	}
#pragma endregion AssignPins



};
