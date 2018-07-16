#include "GameObject.h"



void GameObject::AddFrontAnimation(Animation front)
{
	animations = new Animation[1];
	animations[0] = front;
}

void GameObject::AddNoTop4SidesAnimations(Animation front, Animation back, Animation right, Animation left)
{
	animations = new Animation[1];
	animations[0] = front;
	animations[1] = back;
	animations[2] = right;
	animations[3] = left;
}

void GameObject::AddNoTop8SidesAnimations(Animation front, Animation front_right, Animation front_left, Animation back, Animation back_right, Animation back_left, Animation right, Animation left)
{
	animations = new Animation[1];
	animations[0] = front;
	animations[1] = front_right;
	animations[2] = front_left;
	animations[3] = back;
	animations[4] = back_right;
	animations[5] = back_left;
	animations[6] = right;
	animations[7] = left;
}

void GameObject::AddAllSides6Animations(Animation top, Animation bottom, Animation front, Animation back, Animation right, Animation left)
{
	animations = new Animation[1];
	animations[0] = top;
	animations[1] = bottom;
	animations[2] = front;
	animations[3] = back;
	animations[4] = right;
	animations[5] = left;
}

GameObject::GameObject(Position pos, Rotation rot, GameObjectRenderType type)
{
	position = pos;
	rotation = rot;
}

GameObject::GameObject()
{
	position = Position();
	rotation = Rotation();
}


GameObject::~GameObject()
{
}
