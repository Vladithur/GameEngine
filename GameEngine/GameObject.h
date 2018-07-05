#pragma once

#include "Position.h"
#include "Rotation.h"

class GameObject
{
public:
	Position position;
	Rotation rotation;

	GameObject(Position pos, Rotation rot);
	GameObject();
	~GameObject();
};

