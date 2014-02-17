

#pragma once

#include <vector>
#include "arduino.h"


class ACM_Robot
{
	std::vector<float> Distances;

	int RMotorPin;
	int RBrakePin;
	int Channel_A;
	int Channel_B;
	int LMotorPin;
	int LBrakePin;
	int PingPin;

	long PingDuration;
public:
	ACM_Robot();
	~ACM_Robot();

	bool RotatePingSensor(int angle);
	void Scan(int min_angle, int max_angle);
	void MoveForward(float time);
	long Ping();
	void MotorFailDetected();

	// Assign pins.
#pragma region AssignPins
	void AssignPingPin( int pin ){
		PingPin = pin;
	}
	void AssignRMotorPin( int pin ){
		RMotorPin = pin;
	}
	void AssignRMotorPin( int pin ){
		LMotorPin = pin;
	}
	void AssignRBrakePin( int pin ){
		RBrakePin = pin;
	}
	void AssignLBrakePin( int pin ){
		LBrakePin = pin;
	}
	void AssignChannelAPin( int pin ){
		Channel_A = pin;
	}
	void AssignChannelBPin( int pin ){
		Channel_B = pin;
	}

#pragma endregion AssignPins

	void DriveForwardFull()
	{
		//Motor A forward @ full speed
		digitalWrite(RMotorPin, HIGH); //Establishes forward direction of Channel A
		digitalWrite(RBrakePin, LOW);   //Disengage the Brake for Channel A
		analogWrite(Channel_A, 255);   //Spins the motor on Channel A at full speed

		//Motor B forward @ full speed
		digitalWrite(LMotorPin, HIGH); //Establishes forward direction of Channel B
		digitalWrite(LBrakePin, LOW);   //Disengage the Brake for Channel B
		analogWrite(Channel_B, 255);   //Spins the motor on Channel B at full speed
	}
	void Halt()
	{
		digitalWrite(Channel_A, HIGH);  //Engage the Brake for Channel A
		digitalWrite(Channel_B, HIGH);  //Engage the Brake for Channel B

		
	}
};
