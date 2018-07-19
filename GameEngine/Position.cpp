#include "Position.h"


static float xtoy(float x)
{
	float r = (x - (int)((x - 1) / 90) * 90) / 90;
	if (x > 180)
		return r;

	float c = 1;
	if (x > 90 && x <= 180)
		c = 0;

	return c - r;
}

Position Position::MoveFromRotation(Rotation r)
{
	Rotation temp = Rotation(r);
	temp.Normalize(); 
	Position dir = Position();
	dir.x = xtoy(temp.x);
	dir.y = xtoy(temp.y);
	dir.z = xtoy(temp.z);

	// TODO 
	// Apply magnitude scaling

	delete &temp;
	return dir;
}

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
