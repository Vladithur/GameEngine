#pragma once

#include <stdint.h>
#include <Windows.h>


#include "RendererWindowStyle.h"
#include "GameObject.h"

class Renderer
{
public:
	HWND window;
	GameObject ** objects;

	

	void UpdateScene(GameObject camera, uint32_t camera_index);

	Renderer(uint16_t width, uint16_t height, RendererWindowStyle style, GameObject ** objs, HWND hwnd, int nCmdShow);
	Renderer();
	~Renderer();
};

