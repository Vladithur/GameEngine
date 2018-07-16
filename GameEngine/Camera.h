#pragma once
#include "GameObject.h"
class Camera :
	public GameObject
{
public:
	float field_of_view;

	Camera(Position pos, Rotation rot, float fov);
	Camera();
	~Camera();
};

