#pragma once
#include <math.h>
class Rotation
{
public:
	float x, y, z;

	void Normalize();
	Rotation(float _x, float _y, float _z);
	Rotation();
	~Rotation();
};

