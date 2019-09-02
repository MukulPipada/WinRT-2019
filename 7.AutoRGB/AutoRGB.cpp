#include<Windows.h>

#define MYTIMER 101

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR iCmdLine, int iCmdShow)

{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("ChangeColorOnTimer");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hInstance = hInstance;

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT("Change Colour On Timer"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

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
	static int iPaintFlag = 0;
	RECT rc, rcTemp;
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hBrush;

	switch (iMsg)
	{
	case WM_CREATE:

		SetTimer(hwnd, MYTIMER, 2000, NULL);

		break;

	case WM_TIMER:

		KillTimer(hwnd, MYTIMER);

		iPaintFlag++;
		if (iPaintFlag > 7)
		{
			iPaintFlag = 0;
		}

		InvalidateRect(hwnd, NULL, FALSE);

		SetTimer(hwnd, MYTIMER, 2000, NULL);
		break;

	case WM_SIZE:
		iPaintFlag = 0;
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);

		rcTemp.top = rc.top;
		rcTemp.bottom = rc.bottom;
		rcTemp.right = rc.right/8;

		rcTemp.left = rc.left + (iPaintFlag) * (rcTemp.right);
		rcTemp.right = rcTemp.left + (rcTemp.right);

		switch (iPaintFlag)
		{

		case 0:
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rcTemp, hBrush);
			break;

		case 1:
			hBrush = CreateSolidBrush(RGB(0,255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rcTemp, hBrush);
			break;

		case 2:
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rcTemp, hBrush);
			break;

		case 3:
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rcTemp, hBrush);
			break;

		case 4:
			hBrush = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rcTemp, hBrush);
			break;

		case 5:
			hBrush = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rcTemp, hBrush);
			break;

		case 6:
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rcTemp, hBrush);
			break;

		case 7:
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rcTemp, hBrush);
			break;
		}
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
