#include "Rotation.h"



void Rotation::Normalize()
{
	float x = (360 + (int)(roundf(x)) % 360) % 360;
	float y = (360 + (int)(roundf(y)) % 360) % 360;
	float z = (360 + (int)(roundf(z)) % 360) % 360;
}

Rotation::Rotation(float _x, float _y, float _z)
{
	x = _x; y = _y; z = _z;
}

Rotation::Rotation()
{
	x = 0; y = 0; z = 0;
}


Rotation::~Rotation()
{
}
