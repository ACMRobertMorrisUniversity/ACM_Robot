// ACM_Robot source file.
// 
// Date: 2014-02-25

#include "ACM_Robot.h"

ACM_Robot::ACM_Robot()
{

}


ACM_Robot::~ACM_Robot()
{

}

// Sets the Robot up for functioning.
void ACM_Robot::Initialize()
{
	InitializeMotors();
	AssignPingPin(7);
	AssignServo(3);
	Halt();
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

void ACM_Robot::InitializeSDCard()
{
	  
}

void ACM_Robot::Halt()
{
	digitalWrite(ChannelA.BrakePin, HIGH);  //Engage the Brake for Channel A
	digitalWrite(ChannelB.BrakePin, HIGH);  //Engage the Brake for Channel B
}

void ACM_Robot::DriveForward( word speed )
{
	//Motor A forward @ speed
	digitalWrite(ChannelA.DirectionPin, LOW); //Establishes forward direction of Channel A
	digitalWrite(ChannelA.BrakePin, LOW);   //Disengage the Brake for Channel A
	analogWrite(ChannelA.SpeedPin, speed);   //Spins the motor on Channel A at full speed

	//Motor B forward @ speed
	digitalWrite(ChannelB.DirectionPin, HIGH); //Establishes forward direction of Channel B
	digitalWrite(ChannelB.BrakePin, LOW);   //Disengage the Brake for Channel B
	analogWrite(ChannelB.SpeedPin, speed);   //Spins the motor on Channel B at full speed
}
void ACM_Robot::DriveBackward( word speed )
{
	//Motor A forward @ speed
	digitalWrite(ChannelA.DirectionPin, HIGH); //Establishes forward direction of Channel A
	digitalWrite(ChannelA.BrakePin, LOW);   //Disengage the Brake for Channel A
	analogWrite(ChannelA.SpeedPin, speed);   //Spins the motor on Channel A at full speed

	//Motor B forward @ speed
	digitalWrite(ChannelB.DirectionPin, LOW); //Establishes forward direction of Channel B
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
	myServo.write( angle ); // turns out its very simple...
	return true;
}

void ACM_Robot::MotorFailDetected()
{
	// TODO: what to do when a motor fails...
}

void ACM_Robot::ScanEx(int min_angle, int max_angle, int passes)
{
	long D1[DIST_COUNT], D2[DIST_COUNT], D3[DIST_COUNT];
	for ( int i = 0; i < passes; i++ )
	{
		
	}
}

void ACM_Robot::Scan(int min_angle, int max_angle)
{
	int displayDist = 0;
	float degrees = 0;
	char tab = 9;
	RotatePingSensor(min_angle);
	delay(20);
	// Robot is going to rotate the ping sensor
	// Robot cycles through angles from min to max
	//  and fills the Distances list with each distance.
	for (int i = 0; i < DIST_COUNT; i++ )
	{
		char buffer[5];
		degrees = (float)min_angle + (float)i * ((float)(max_angle-min_angle)/(float)(DIST_COUNT-1));
		// Rotate the Ping Sensor to the new angle.
		RotatePingSensor(degrees);
		delay(10);
		// Send a message to the ping sensor to return
		//  a value and store it in the list.
		Distances[i] = Ping();
		delay(10);
		
		Serial.print((int)degrees);
		Serial.print(tab);
		displayDist = Distances[i];
		Serial.println(displayDist);

		/*/Serial.print("#S|LOGTEST|[");
		Serial.print(itoa(((int)degrees), buffer, 10));
		Serial.print(tab);
		Serial.print(itoa((displayDist), buffer, 10));
		//Serial.println("]#");
		
		Serial.print(degrees);
		Serial.print(" degrees: ");
		displayDist = Distances[i];
		Serial.print(displayDist);
		Serial.println(" cm");
		/*/
	}
}

long ACM_Robot::Ping()
{
	long duration;
	// Send out PING))) signal pulse
	pinMode(PingPin, OUTPUT);
	delay(2);
	digitalWrite(PingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(PingPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(PingPin, LOW);

	//Get duration it takes to receive echo
	pinMode(PingPin, INPUT);
	duration = pulseIn(PingPin, HIGH);
	delay(2);
	//Convert duration into distance
	//Distance = duration / 29 / 2;
	long temp = (duration / 29 / 2);
	
	return temp;
}

void ACM_Robot::Analyze(void)
{
	for( int i = 0; i < DIST_COUNT; i++ )
	{

	}
}
