#pragma once

#include <stdint.h>

#include "Position.h"
#include "Rotation.h"
#include "GameObjectRenderType.h"
#include "Animation.h"

class GameObject
{
public:
	Position position;
	Rotation rotation;
	GameObjectRenderType render_type;
	uint32_t index;
	
	Animation * animations;

	void AddFrontAnimation(Animation front);
	void AddNoTop4SidesAnimations(Animation front, Animation back, Animation right, Animation left);
	void AddNoTop8SidesAnimations(Animation front, Animation front_right, Animation front_left, Animation back, Animation back_right, Animation back_left, Animation right, Animation left);
	void AddAllSides6Animations(Animation top, Animation bottom, Animation front, Animation back, Animation right, Animation left);


	GameObject(Position pos, Rotation rot, GameObjectRenderType type);
	GameObject();
	~GameObject();
};

