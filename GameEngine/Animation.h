#pragma once

#include "AnimationFrame.h"
class Animation
{
public:
	AnimationFrame * frames;
	Image image;
	bool playable;
	float time;
	float speed;

	Animation(Image img);
	Animation(AnimationFrame * afs, float play_speed);
	Animation();
	~Animation();
};

