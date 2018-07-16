#include "Renderer.h"



RayHitObject Renderer::SendRay(Engine eng, Position pos, Position dir, uint16_t maxRange, float step)
{
	Position current_pos= Position(pos);
	float travelled = 0;
	while (travelled < maxRange) {
		float * dist;
		GameObject * tmp = &eng.GetGameObjectClosestToPos(current_pos, step, dist, GameObjectRenderType::NotRendered, true);
		if (*dist <= step) return RayHitObject(*tmp, *dist, true);
		travelled += step;
		delete tmp;
	}
	return RayHitObject(false);
}

Image Renderer::UpdateScene(Camera camera)
{
	float fov = camera.field_of_view;
	if (angleY != fov) {
		angleY = fov;
		angleX = fov * (height / width);
		float angle = 90 - fov;
		float side = height / 2;
		distance = tan(angle) * side;
		slopeSize = sqrt(sqrt((width * width) + (height * height)) + (distance * distance));
	}

	rays.clear();

	while (true) {
		for (int i = 0; i < width / ray_cast_scale; i += ray_cast_scale) {
			thread * thr = new thread[height / ray_cast_scale];
			for (int j = 0; j < height / ray_cast_scale; j += ray_cast_scale) {
				//thread t = 
			}
		}
	}

	Image result = Image(width, height);
	return result;
}



Renderer::Renderer(uint16_t w, uint16_t h, RendererWindowStyle style, GameObject ** objs, HWND hwnd, int nCmdShow)
{
	objects = objs;

	if (style == RendererWindowStyle::Window) {
		SetWindowLong(hwnd, GWL_STYLE, (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX));
		SetWindowPos(hwnd, 0, 0, 0, (int)width, height, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	}
	else if (style == RendererWindowStyle::Fullscreen) {
		SetWindowLong(hwnd, GWL_STYLE, 0);
		HMONITOR hmon = MonitorFromWindow(hwnd,
			MONITOR_DEFAULTTONEAREST);
		MONITORINFO mi = { sizeof(mi) };
		if (!GetMonitorInfo(hmon, &mi)) return;
		SetWindowPos(hwnd, HWND_TOPMOST, mi.rcMonitor.left,
			mi.rcMonitor.top,
			mi.rcMonitor.right - mi.rcMonitor.left,
			mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_FRAMECHANGED);
	}
	else if (style == RendererWindowStyle::Borderless) {
		SetWindowLong(hwnd, GWL_STYLE, 0);
		SetWindowPos(hwnd, 0, 0, 0, (int)width, height, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	width = w; height = h;
}

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}
