


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

const unsigned int DIST_COUNT = 100;

class ACM_Robot{
	// Robots Brain structures.
	float Distances[DIST_COUNT];

	// Motor Control structures.
	MotorChannel ChannelA;
	MotorChannel ChannelB;
	void InitializeMotors();		

	// Ping Control structures.
	int PingPin;
	long PingDuration;
	
	
public:
	// CTOR & DTORs
	ACM_Robot();
	~ACM_Robot();
	// Initialization
	void Initialize();		// This needs to be called in the Setup function
	Servo myServo;			// Unfortunately this has to be a public member to work
	
	// Ping Sensor Methods
	bool RotatePingSensor(int angle);
	void Scan(int min_angle, int max_angle);
	void ScanEx(int min_angle, int max_angle, int passes);
	long Ping();

	// Motor related Methods
	void DriveForward(word speed);
	void DriveBackward(word speed);
	void DriveForwardFull();
	void Halt();
	void MotorFailDetected();

	// SDCard related methods
	void InitializeSDCard();

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

	// Analyze the environment
	void Analyze(void);

};
