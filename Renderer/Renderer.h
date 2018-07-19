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

	// dir is the change in postion when moved 1 unit forward

public:
	static RayHitObject SendRay(Engine eng, Position pos, Position dir, uint16_t maxRange, float step);
	uint8_t ray_cast_scale = 2;
	HWND window;
	GameObject ** objects;
	uint16_t width, height;

	Image UpdateScene(Camera camera, Engine engine);

	Renderer(uint16_t width, uint16_t height, RendererWindowStyle style, GameObject ** objs, HWND hwnd, int nCmdShow);
	Renderer();
	~Renderer();
};

