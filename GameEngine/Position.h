#pragma once

#include <math.h>
#include <limits>

class Position
{
public:
	float x, y, z;

	static float Distance(Position a, Position b);
	static float DistanceComp(Position a, Position b, float limit);

	Position(float _x, float _y, float _z);
	Position(float _x, float _y);
	Position();
	~Position();
};

