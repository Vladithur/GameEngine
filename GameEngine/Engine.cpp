#include "Engine.h"


void Engine::CreateRenderer(uint16_t width, uint16_t height, RendererWindowStyle style, HWND hwnd, int nCmdShow)
{
	renderer = Renderer(width, height, style, &gameObjects, hwnd, nCmdShow);
}

Engine::Engine()
{
}


Engine::~Engine()
{
}
