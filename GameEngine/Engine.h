#pragma once

#include <stdint.h>

#include "Renderer.h"

class Engine
{
protected:
	Renderer renderer;
	GameObject * gameObjects;
public:

	void CreateRenderer(uint16_t width, uint16_t height, RendererWindowStyle style, HWND hwnd, int nCmdShow);

	Engine();
	~Engine();
};

