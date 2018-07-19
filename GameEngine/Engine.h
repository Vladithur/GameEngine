#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <algorithm> 

#include "Renderer.h"

class Engine
{
private:
	uint32_t last_index;
protected:
	Renderer renderer;
public:
	GameObject * gameObjects;
	float enlarge_multiplier;
	float shrink_multiplier;
	float shrink_check_multiplier;
	float enlarge_check_multiplier;
	bool auto_resize;
	uint32_t array_length, item_count;

	void ResizeArray(bool shrink);
	void ResizeArray(uint32_t new_size);

	void CreateRenderer(uint16_t width, uint16_t height, RendererWindowStyle style, HWND hwnd, int nCmdShow);
	void AddGameObject(GameObject obj);
	void RemoveGameObject(uint32_t index);
	void RemoveGameObject(GameObject obj);
	GameObject GetGameObject(uint32_t index);
	GameObject GetGameObject(GameObject obj);
	GameObject GetLastGameObject();
	GameObject* GetGameObjectClosestToPos(Position pos, float maxError, float * dist);
	GameObject* GetGameObjectClosestToPos(Position pos, float maxError, float * dist, GameObjectRenderType render_type, bool exclude_type);


	Image UpdateGame(Camera camera);

	Engine(float initial_array_size);
	Engine(float initial_array_size, bool auto_res);
	Engine(float initial_array_size, float enlarge_mult, float shrink_mult, float shrink_check_mult, float enlarge_check_mult);
	Engine();
	~Engine();
};

