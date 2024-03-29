<<<<<<< HEAD
#include<windows.h>
#include "SplashScreen.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE HPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SplashScreen");
	
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT("SplashScreen"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	HICON LoadIcon(HINSTANCE hInstance, LPCSTR lpicon);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HBITMAP hBitmap;
	HDC hdc, hdcMem;
	PAINTSTRUCT ps;
	RECT rc;
	BITMAP bitmap;
	static HINSTANCE hInstance = NULL;

	switch (iMsg)
	{
	case WM_CREATE:
		hInstance = (HINSTANCE)GetModuleHandle(NULL);
		//hBitmap = LoadBitmap(hInstance,  MAKEINTRESOURCE(MY_BITMAP));

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(MY_BITMAP));
		
		GetClientRect(hwnd, &rc);
		
		hdcMem = CreateCompatibleDC(NULL);
		
		SelectObject(hdcMem, hBitmap);
		
		GetObject(hBitmap, sizeof(BITMAP), (PSTR)&bitmap);
		
		StretchBlt(hdc, 0, 0, rc.right, rc.bottom,
			hdcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		
		DeleteObject(hBitmap);
		
		DeleteDC(hdcMem);
		
		EndPaint(hwnd, &ps);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
=======
#include<windows.h>
#include "SplashScreen.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE HPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SplashScreen");
	
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MY_ICON));

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT("SplashScreen"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	HICON LoadIcon(HINSTANCE hInstance, LPCSTR lpicon);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HBITMAP hBitmap;
	HDC hdc, hdcMem;
	PAINTSTRUCT ps;
	RECT rc;
	BITMAP bitmap;
	static HINSTANCE hInstance = NULL;

	switch (iMsg)
	{
	case WM_CREATE:
		hInstance = (HINSTANCE)GetModuleHandle(NULL);
		//hBitmap = LoadBitmap(hInstance,  MAKEINTRESOURCE(MY_BITMAP));

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(MY_BITMAP));
		
		GetClientRect(hwnd, &rc);
		
		hdcMem = CreateCompatibleDC(NULL);
		
		SelectObject(hdcMem, hBitmap);
		
		GetObject(hBitmap, sizeof(BITMAP), (PSTR)&bitmap);
		
		StretchBlt(hdc, 0, 0, rc.right, rc.bottom,
			hdcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		
		DeleteObject(hBitmap);
		
		DeleteDC(hdcMem);
		
		EndPaint(hwnd, &ps);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
>>>>>>> 6d5d492c3781cdc9f4a1939a006d19f4ffda58f0
