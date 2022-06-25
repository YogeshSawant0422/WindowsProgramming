//header files
#include<windows.h>

//global function declarations 
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//global variable declaration

//Entry point function
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdLine,int iCmdShow)
{
	//local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("WINDEV");
	
	//code
	//WNDCLASSEX initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW|CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
	
	//Registration of WNDCLASSEX
	RegisterClassEx(&wndclass);
	
	//creating the window
	hwnd = CreateWindow(
	 szAppName,
	 TEXT("YSS:Window"),
	 WS_OVERLAPPEDWINDOW,
	 CW_USEDEFAULT,
	 CW_USEDEFAULT,
	 CW_USEDEFAULT,
	 CW_USEDEFAULT,
	 NULL,
	 NULL,
	 hInstance,
	 NULL
	);
	
	//show the window
	
	ShowWindow(hwnd,iCmdShow);
	
	//update the window
	UpdateWindow(hwnd);
	
	//message loop
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	//local variable declaration 
	
	//code
	switch(iMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			break;
	}
	
	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}

