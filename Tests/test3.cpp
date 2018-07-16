
#include "Engine.h"
#include "Renderer.h"
#include "GameObjectRenderType.h"


int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR pCmdLine, int nCmdShow) {

	MSG  msg;
	HWND hwnd;
	WNDCLASSW wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpszClassName = L"Window";
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpszMenuName = NULL;
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassW(&wc);
	hwnd = CreateWindowW(wc.lpszClassName, L"Window",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 1000, 1000, NULL, NULL, hInstance, NULL);

	Engine engine = Engine();
	engine.CreateRenderer(500, 500, RendererWindowStyle::Window, hwnd, nCmdShow);

	int count = 1000000;
	for (int i = 0; i < count; i++) {
		engine.AddGameObject(GameObject());
	}
	for (int i = count - 1; i > 0; i--) {
		engine.RemoveGameObject(i);
	}

	GameObject obj = GameObject();
	Camera cam = Camera(Position(-1, 0, 0), Rotation(), 90);
	obj.AddFrontAnimation(Animation(Image::bmp_to_image("wall.bmp")));
	engine.AddGameObject(obj);
	engine.AddGameObject(cam);
	engine.UpdateGame(cam);

	while (GetMessage(&msg, NULL, 0, 0)) {

		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
	WPARAM wParam, LPARAM lParam) {

	switch (msg) {

	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}