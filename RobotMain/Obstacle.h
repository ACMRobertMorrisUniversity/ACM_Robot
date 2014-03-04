#pragma once

#include "Vector2.h"
#include <vector>

class Obstacle
{
private:
	std::vector<Vector2,std::allocator<void>> Points[10];
public:
	Obstacle(void);
	~Obstacle(void);

	void AddPoint( Vector2 point );

	Vector2 CalculateCenterOfMass( );
};

