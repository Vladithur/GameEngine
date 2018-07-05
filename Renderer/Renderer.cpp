#include "Renderer.h"



void Renderer::UpdateScene(GameObject camera, uint32_t camera_index)
{
}

Renderer::Renderer(uint16_t width, uint16_t height, RendererWindowStyle style, GameObject ** objs, HWND hwnd, int nCmdShow)
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
}

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}
