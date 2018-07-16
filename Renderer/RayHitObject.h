#pragma once

#include "GameObject.h"

class RayHitObject
{
public:
	GameObject * object;
	float dist;
	bool hit;

	struct order {
		inline bool operator()(const RayHitObject& left, const RayHitObject& right)
		{
			return left.dist > right.dist;
		}
	};

	RayHitObject(GameObject obj, float d, bool h);
	RayHitObject(bool h);
	RayHitObject();
	~RayHitObject();
};

