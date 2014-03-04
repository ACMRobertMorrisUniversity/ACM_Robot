#include "Obstacle.h"


Obstacle::Obstacle(void)
{
}


Obstacle::~Obstacle(void)
{
}


Vector2 Obstacle::CalculateCenterOfMass()
{
	float mx = 0, my = 0;
	Vector2 result;
	for( int i = 0; i < 10; i++ )
	{
		mx += Points[i].X;
		my += Points[i].Y;
	}

	return result = Vector2( mx, my );
}