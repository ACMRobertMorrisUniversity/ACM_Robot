
#pragma once
#include <StandardCplusplus.h>
#include "Vector2.h"

class Obstacle
{
private:
	//std::vector<Vector2,std::allocator<void>> Points;
	Vector2 Points[100];
public:
	Obstacle(void);
	~Obstacle(void);

	void AddPoint( Vector2 point );

	Vector2 CalculateCenterOfMass( );
};

