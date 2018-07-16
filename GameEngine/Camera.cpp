#include "Camera.h"

Camera::Camera(Position pos, Rotation rot, float fov)
{
	position = pos;
	rotation = rot;
	field_of_view = fov;
}

Camera::Camera()
{
	render_type = GameObjectRenderType::NotRendered;
}


Camera::~Camera()
{
}
