#pragma once

#include <math.h>
#include <limits>
#include "Rotation.h"

class Position
{
public:
	float x, y, z;

	// Rotation( x = 0, y = 0, z = 0 ) is front;
	static Position MoveFromRotation(Rotation r);
	static float Distance(Position a, Position b);
	static float DistanceComp(Position a, Position b, float limit);

	Position(float _x, float _y, float _z);
	Position(float _x, float _y);
	Position();
	~Position();
};

