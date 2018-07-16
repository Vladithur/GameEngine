#include "RayHitObject.h"



RayHitObject::RayHitObject(GameObject obj, float d, bool h)
{
	object = &obj;
	dist = d;
	hit = h;
}

RayHitObject::RayHitObject(bool h)
{
	hit = false
}

RayHitObject::RayHitObject()
{
}


RayHitObject::~RayHitObject()
{
}
