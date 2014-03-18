


#pragma once

#include "arduino.h"
#include "Servo.h"
#include "Vector2.h"

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
	MotorChannel( uint8_t directionPin, uint8_t speedPin, uint8_t brakePin, uint8_t currentSensePin )
	{
		DirectionPin = directionPin; SpeedPin = speedPin; BrakePin = brakePin;
		CurrentSensePin = currentSensePin;
	}
	uint8_t DirectionPin;
	uint8_t SpeedPin;
	uint8_t BrakePin;
	uint8_t CurrentSensePin;
};

const uint8_t DIST_COUNT = 100;
const char TAB_CHAR = 6;

class ACM_Robot{
	// Robots Brain structures.
	float Distances[DIST_COUNT];
	Vector2 verts1[DIST_COUNT];
	Vector2 verts2[DIST_COUNT];
	Vector2 verts3[DIST_COUNT];

	// Motor Control structures.
	MotorChannel ChannelA;
	MotorChannel ChannelB;
	void InitializeMotors();		

	// Ping Control structures.
	uint8_t PingPin;
	uint8_t PingDuration;
	
	
public:
	// CTOR & DTORs
	ACM_Robot();
	~ACM_Robot();
	// Initialization
	void Initialize();		// This needs to be called in the Setup function
	Servo myServo;			// Unfortunately this has to be a public member to work
	
	// Ping Sensor Methods
	bool RotatePingSensor(uint8_t angle);
	void Scan(uint8_t min_angle, uint8_t max_angle);
	Vector2* ScanEx(uint8_t min_angle, uint8_t max_angle, uint8_t passes);
	uint8_t Ping();

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
	void AssignPingPin(uint8_t pin){
		PingPin = pin;
	}
	void AssignServo(uint8_t pin){
		myServo.attach(pin);
		//pinMode(pin,OUTPUT);
	}
#pragma endregion AssignPins

	// Analyze the environment
	void DetectObstacles(Vector2* pts);

};
