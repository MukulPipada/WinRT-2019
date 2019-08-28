#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("Indian Pledge");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT("INDIAN PLEDGE"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

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
	PAINTSTRUCT ps;
	HDC hdc;

	static int cChar;
	int X, Y;
	TEXTMETRIC tm;


	switch (iMsg)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);
		GetTextMetrics(hdc, &tm);
		cChar = tm.tmHeight + tm.tmExternalLeading;
		break;

	case WM_PAINT:
		X = 350;
		Y = 50;

		hdc = BeginPaint(hwnd, &ps);
		SetBkColor(hdc, RGB(0, 0, 0));

		SetTextColor(hdc, RGB(255, 125, 0));

		TextOut(hdc, X, Y, TEXT("India is my country\n"), strlen("India is my country\n"));
		Y = Y + cChar;
		TextOut(hdc, X, Y, TEXT("All Indians are my Brothers and Sisters."), strlen("All Indians are my Brothers and Sisters"));
		Y = Y + cChar;
		TextOut(hdc, X, Y, TEXT("I love my country and I am proud of its"), strlen("I love my country and I am proud of its"));
		Y = Y + cChar;
		TextOut(hdc, X, Y, TEXT("rich and varied heritage."), strlen("rich and varied heritage."));
		Y = Y + cChar;

		SetTextColor(hdc, RGB(255, 225, 255));

		TextOut(hdc, X, Y, TEXT("I shall Strive to be worthy of it"), strlen("I shall Strive to be worthy of it"));
		Y = Y + cChar;
		TextOut(hdc, X, Y, TEXT("I shall respect my Parents, Teachers and "), strlen("I shall respect my Parents, Teachers and "));
		Y = Y + cChar;
		TextOut(hdc, X, Y, TEXT("all elders and treat everyone with"), strlen("all elders and treat everyone with"));
		Y = Y + cChar;
		TextOut(hdc, X, Y, TEXT("courtesy"), strlen("courtesy"));
		Y = Y + cChar;

		SetTextColor(hdc, RGB(0, 225, 0));

		TextOut(hdc, X, Y, TEXT("To my country and all my People"), strlen("To my country and all my people"));
		Y = Y + cChar;
		TextOut(hdc, X, Y, TEXT("I pledge my devotion "), strlen("I pledge my devotion "));
		Y = Y + cChar;
		TextOut(hdc, X, Y, TEXT("In their well being and prosperity alone lies my happiness"), strlen("In their well being and prosperity alone lies my happiness"));
		Y = Y + cChar;
		TextOut(hdc, X, Y, TEXT("Jai Hind"), strlen("Jai Hind"));
		Y = Y + cChar;

		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}