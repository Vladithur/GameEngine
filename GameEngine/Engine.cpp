#include "Engine.h"


void Engine::ResizeArray(bool shrink) {
	GameObject * newObjs;
	uint32_t new_size;
	if (shrink) {
		new_size = (int)(((float)array_length) / shrink_multiplier);
		newObjs = new GameObject[new_size];
	}
	else {
		new_size = (int)(((float)array_length) * enlarge_multiplier);
		newObjs = new GameObject[new_size];
	}

	memcpy(newObjs, gameObjects, item_count * sizeof(GameObject));
	delete[] gameObjects;
	gameObjects = newObjs;
	array_length = new_size;
}

void Engine::ResizeArray(uint32_t new_size)
{
	GameObject * newObjs = new GameObject[new_size];

	memcpy(newObjs, gameObjects, item_count * sizeof(GameObject));
	delete[] gameObjects;
	gameObjects = newObjs;
	array_length = new_size;
}

void Engine::CreateRenderer(uint16_t width, uint16_t height, RendererWindowStyle style, HWND hwnd, int nCmdShow)
{
	renderer = Renderer(width, height, style, &gameObjects, hwnd, nCmdShow);
}

void Engine::AddGameObject(GameObject obj)
{
	gameObjects[item_count] = obj;
	obj.index = item_count;
	item_count++;
	if (auto_resize && item_count * enlarge_check_multiplier >= array_length) {
		ResizeArray(false);
	}
}


//Swaps the LAST element with the deleted element (The last element after the swap is ignored)
void Engine::RemoveGameObject(uint32_t index)
{
	gameObjects[index] = gameObjects[array_length - 1];
	gameObjects[index].index = index;
	last_index = index;
	item_count--;
	if (auto_resize && item_count * shrink_check_multiplier <= array_length) {
		ResizeArray(true);
	}
}

void Engine::RemoveGameObject(GameObject obj)
{
	RemoveGameObject(obj.index);
}

GameObject Engine::GetGameObject(uint32_t index)
{
	return gameObjects[index];
}

GameObject Engine::GetGameObject(GameObject obj)
{
	return gameObjects[obj.index];
}

GameObject Engine::GetLastGameObject()
{
	return gameObjects[last_index];
}

GameObject Engine::GetGameObjectClosestToPos(Position pos, float maxError, float * dist)
{
	int i = 0;
	while (i < item_count) {
		GameObject o = GetGameObject(i);
		float d = Position::DistanceComp(o.position, pos, maxError);
		if (d <= maxError) {
			if (*dist) *dist = d;
			return o;
		}
		i++;
	}
}

GameObject Engine::GetGameObjectClosestToPos(Position pos, float maxError, float * dist, GameObjectRenderType render_type, bool exclude_type)
{
	int i = 0;
	if (!exclude_type) {
		while (i < item_count) {
			GameObject o = GetGameObject(i);
			float d = Position::DistanceComp(o.position, pos, maxError);
			if (o.render_type == render_type && d <= maxError) {
				if (*dist) *dist = d;
				return o;
			}
			i++;
		}
	}
	else {
		while (i < item_count) {
			GameObject o = GetGameObject(i);
			float d = Position::DistanceComp(o.position, pos, maxError);
			if (o.render_type != render_type && d <= maxError) {
				if (*dist) *dist = d;
				return o;
			}
			i++;
		}
	}
}

Image Engine::UpdateGame(Camera c)
{
	return renderer.UpdateScene(c);
}

Engine::Engine(float initial_array_size)
{
	gameObjects = new GameObject[initial_array_size];
	array_length = initial_array_size;
	item_count = 0;
	enlarge_multiplier = 2;
	shrink_multiplier = 2;
	shrink_check_multiplier = 3;
	enlarge_check_multiplier = 1;
	auto_resize = true;
}

Engine::Engine(float initial_array_size, bool auto_res)
{
	gameObjects = new GameObject[initial_array_size];
	array_length = initial_array_size;
	item_count = 0;
	auto_resize = false;
}

Engine::Engine(float initial_array_size, float enlarge_mult, float shrink_mult, float shrink_check_mult, float enlarge_check_mult)
{
	gameObjects = new GameObject[initial_array_size];
	array_length = initial_array_size;
	item_count = 0;
	enlarge_multiplier = enlarge_mult;
	shrink_multiplier = shrink_mult;
	shrink_check_multiplier = shrink_check_mult;
	enlarge_check_multiplier = enlarge_check_mult;
	auto_resize = true;
}

Engine::Engine()
{
	gameObjects = new GameObject[50];
	array_length = 50;
	item_count = 0;
	enlarge_multiplier = 2;
	shrink_multiplier = 2;
	shrink_check_multiplier = 3;
	enlarge_check_multiplier = 1;
	auto_resize = true;
}


Engine::~Engine()
{
}
