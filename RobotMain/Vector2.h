#pragma once
class Vector2
{
public:
	Vector2( float x, float y );
	Vector2(void);
	~Vector2(void);

	float X, Y;

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
};

