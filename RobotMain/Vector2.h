#pragma once

#include <math.h>

class Vector2
{
public:
	Vector2( float x, float y );
	Vector2(void);
	~Vector2(void);

	float X, Y;

	float magnitudeSquared()
	{
		return X*X + Y*Y;
	}

	float magnitude()
	{
		return (float)sqrt( (double)(X*X) + (double)(Y*Y) );
	}

	Vector2 operator*( float scalar )
	{
		X*=scalar;
		Y*=scalar;
	}
	Vector2 operator/( float scalar )
	{
		X/=scalar;
		Y/=scalar;
	}
	Vector2 operator-( float scalar )
	{
		X-=scalar;
		Y-=scalar;
	}
	Vector2 operator-()
	{
		X=-1.0f*X;
		Y=-1.0f*Y;
	}
	Vector2 operator+( float scalar )
	{
		X+=scalar;
		Y+=scalar;
	}

	Vector2 operator+( Vector2 vector )
	{
		X+=vector.X;
		Y+=vector.Y;
	}
	Vector2 operator-( Vector2 vector )
	{
		X-=vector.X;
		Y-=vector.Y;
	}
	bool operator!=( Vector2 vector )
	{
		// Magnitude and direction are the same?
		return !((X==vector.X) & (Y==vector.Y));
	}
	bool operator==( Vector2 vector )
	{
		// Magnitude and direction are the same?
		return (X==vector.X) & (Y==vector.Y);
	}
};

