#pragma once

#include <stdint.h>
#include <Windows.h>
#include <math.h>
#include <thread>
#include <set>

#include "Camera.h"
#include "RendererWindowStyle.h"
#include "GameObject.h"
#include "RayHitObject.h"
#include "Engine.h"

class Renderer
{
private:
	float distance, slopeSize, angleX, angleY;
	std::set<RayHitObject, RayHitObject::order> rays;

	// dir is the change in postion when moved 1 unit forward
	RayHitObject SendRay(Engine eng, Position pos, Position dir, uint16_t maxRange, float step);

public:
	uint8_t ray_cast_scale = 2;
	HWND window;
	GameObject ** objects;
	uint16_t width, height;

	Image UpdateScene(Camera camera);

	Renderer(uint16_t width, uint16_t height, RendererWindowStyle style, GameObject ** objs, HWND hwnd, int nCmdShow);
	Renderer();
	~Renderer();
};

