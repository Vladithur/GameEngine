#include "Animation.h"



Animation::Animation(Image img)
{
	image = img;
	playable = false;
}

Animation::Animation(AnimationFrame * afs, float play_speed)
{
	frames = afs;
	playable = true;
	speed = play_speed;
}

Animation::Animation()
{
}


Animation::~Animation()
{
}
