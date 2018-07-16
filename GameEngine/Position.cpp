#include "Position.h"



float Position::Distance(Position a, Position b)
{
	float dist2D = sqrt(exp(b.x - a.x) + exp(b.y - a.y));
	float dist3D = sqrt(exp(dist2D) + exp(b.z - a.z));
	return dist3D;
}

float Position::DistanceComp(Position a, Position b, float limit)
{
	float dist2D = sqrt(exp(b.x - a.x) + exp(b.y - a.y));
	if (dist2D < limit) {
		float dist3D = sqrt(exp(dist2D) + exp(b.z - a.z));
		return dist3D;
	}
	else return std::numeric_limits<float>::max();
}

Position::Position(float _x, float _y, float _z)
{
	x = _x; y = _y; z = _z;
}

Position::Position(float _x, float _y)
{
	x = _x; y = _y; z = 0;
}

Position::Position()
{
	x = 0; y = 0; z = 0;
}


Position::~Position()
{
}
