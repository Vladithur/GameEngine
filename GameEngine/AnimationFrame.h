#pragma once

#include "Image.h"
class AnimationFrame
{
public:
	Image image;
	float startTime;

	AnimationFrame(Image img, float t);
	AnimationFrame();
	~AnimationFrame();
};

