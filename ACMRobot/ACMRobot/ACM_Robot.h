

#pragma once

#include <vector>

class ACM_Robot
{
private:
	std::vector<float> Distances;

public:
	ACM_Robot();
	~ACM_Robot();

	bool RotatePingSensor(int angle);
	void Scan(int min_angle, int max_angle);
	void MoveForward(float time);
	float Ping();
	void MotorFailDetected();

};

