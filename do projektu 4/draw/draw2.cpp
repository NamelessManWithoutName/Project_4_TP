#include "stdafx.h"
#include "draw2.h"
#include <vector>
#include <cstdio>

#define MAX_LOADSTRING 100
#define TMR_1 1

HINSTANCE hInst;								
TCHAR szTitle[MAX_LOADSTRING];					
TCHAR szWindowClass[MAX_LOADSTRING];			

INT value;

HWND hwndButton;

int col = 0;
std::vector<Point> data;
RECT drawArea1 = { 0, 0, 1999, 1999 };
RECT drawArea2 = { 497, 21.5, 512.7, 152.5 };
RECT drawArea2_5 = { 0,65,750,152.5 };
RECT drawArea4 = { 840, 180, 853.5, 306 };
RECT drawArea4_5 = {670,190,1999,305};
RECT drawArea3 = { 505, 6, 847, 773};

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Buttons(HWND, UINT, WPARAM, LPARAM);

int jak_sie_ruszyc = 0;

void MyOnPaintBackground(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen1(Color(250, 1, 1, 1));
	Pen pen3(Color(255, 169, 169, 169));
	Pen pen2(Color(255, 25 * col, 0, 255));
	pen1.SetWidth(6);
	pen3.SetWidth(3);
	graphics.DrawLine(&pen1, 501, 0, 501, 779);
	graphics.DrawLine(&pen1, 851, 0, 851, 779);
	graphics.DrawLine(&pen1, 501, 3, 851, 3);
	graphics.DrawLine(&pen1, 501, 776, 851, 776);
	graphics.DrawLine(&pen3, 0, 155, 498, 155);
	graphics.DrawLine(&pen3, 854, 310, 1900, 310);
	graphics.DrawLine(&pen3, 0, 465, 498, 465);
	graphics.DrawLine(&pen3, 854, 620, 1900, 620);
	graphics.DrawLine(&pen1, 509, 18 , 842, 18 );
	graphics.DrawLine(&pen1, 509, 15 , 509, 158);
	graphics.DrawLine(&pen1, 843, 15 , 843, 158 );
	graphics.DrawLine(&pen1, 509, 155 , 842, 155 );
}

void MyOnPaint(HDC hdc, int przesuniecie,int gora_dol, int y1, int y2, int y3 ,int y4, int pion_czlowiek, int gora_czlowiek, int dol_czlowiek, int czy_rysowac)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen1(Color(250, 1, 1, 1));
	Pen pen3(Color(255, 169, 169, 169));
	pen1.SetWidth(6);
	pen3.SetWidth(3);
	if (gora_dol == 0)
	{
		graphics.DrawLine(&pen1, 509, y1 + przesuniecie * 0.5, 843, y1 + przesuniecie * 0.5);
		graphics.DrawLine(&pen1, 509, y2 + przesuniecie * 0.5, 509, y4 + przesuniecie * 0.5);
		graphics.DrawLine(&pen1, 843, y2 + przesuniecie * 0.5, 843, y4 + przesuniecie * 0.5);
		graphics.DrawLine(&pen1, 509, y3 + przesuniecie * 0.5, 843, y3 + przesuniecie * 0.5);
		if (czy_rysowac == 0)
		{
		graphics.DrawLine(&pen1, 720, gora_czlowiek + przesuniecie * 0.5, 720, dol_czlowiek + przesuniecie * 0.5);
		graphics.DrawLine(&pen1, 690, pion_czlowiek + przesuniecie * 0.5, 750, pion_czlowiek + przesuniecie * 0.5);
		}
	}
	else
	{
		graphics.DrawLine(&pen1, 509, y1 - przesuniecie * 0.5, 843, y1 - przesuniecie * 0.5);
		graphics.DrawLine(&pen1, 509, y2 - przesuniecie * 0.5, 509, y4 - przesuniecie * 0.5);
		graphics.DrawLine(&pen1, 843, y2 - przesuniecie * 0.5, 843, y4 - przesuniecie * 0.5);
		graphics.DrawLine(&pen1, 509, y3 - przesuniecie * 0.5, 843, y3 - przesuniecie * 0.5);
		if (czy_rysowac == 0)
		{
			graphics.DrawLine(&pen1, 720, gora_czlowiek - przesuniecie * 0.5, 720, dol_czlowiek - przesuniecie * 0.5);
			graphics.DrawLine(&pen1, 690, pion_czlowiek - przesuniecie * 0.5, 750, pion_czlowiek - przesuniecie * 0.5);
		}
	}
}
void MyOnPaintHumanIn(HDC hdc, int przesuniecie, int jak_isc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen1(Color(250, 1, 1, 1));
	Pen pen3(Color(255, 169, 169, 169));
	pen1.SetWidth(6);
	pen3.SetWidth(3);
	if (jak_isc == 0)
	{
		graphics.DrawLine(&pen1, 100+ przesuniecie * 0.5, 70 , 100+ przesuniecie * 0.5, 130 );
		graphics.DrawLine(&pen1, 70+ przesuniecie * 0.5, 100 , 130+ przesuniecie * 0.5, 100 );
	}
	else
	{
		graphics.DrawLine(&pen1, 720 - przesuniecie * 0.5, 70, 720 - przesuniecie * 0.5, 130);
		graphics.DrawLine(&pen1, 690 - przesuniecie * 0.5, 100, 750 - przesuniecie * 0.5, 100);
	}

}
void MyOnPaintHumanOut(HDC hdc, int przesuniecie, int jak_isc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen1(Color(250, 1, 1, 1));
	Pen pen3(Color(255, 169, 169, 169));
	pen1.SetWidth(6);
	pen3.SetWidth(3);
	if (jak_isc==0)
	{
		graphics.DrawLine(&pen1, 720 + przesuniecie * 0.5, 225, 720 + przesuniecie * 0.5, 285);
		graphics.DrawLine(&pen1, 690 + przesuniecie * 0.5, 255, 750 + przesuniecie * 0.5, 255);
	}
	else
	{
		graphics.DrawLine(&pen1, 1030 - przesuniecie * 0.5, 225, 1030 - przesuniecie * 0.5, 285);
		graphics.DrawLine(&pen1, 1000 - przesuniecie * 0.5, 255, 1060 - przesuniecie * 0.5, 255);
	}

}
void MyOnPaintDoor (HDC hdc, int przesuniecie, int otwierac_czy_zamykac, int x1, int x2, int y1, int y2, int width)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	Pen pen1(Color(250, 1, 1, 1));
	Pen pen3(Color(255, 169, 169, 169));
	if (otwierac_czy_zamykac == 0)
	{
		pen1.SetWidth(width);
		graphics.DrawLine(&pen1, x1, y1 , x1, y2  - przesuniecie * 0.5);
		graphics.DrawLine(&pen1, x2, y1 , x2, y2  - przesuniecie * 0.5);
	}
	else
	{
		pen1.SetWidth(width);
		graphics.DrawLine(&pen1, x2, y1, x2, y2  + przesuniecie * 0.5);
		graphics.DrawLine(&pen1, x1, y1, x1, y2  + przesuniecie * 0.5);
	}

}

void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea, int przesuniecie, int gora_dol, int y1, int y2, int y3,int y4, int pion_czlowiek, int lewo_czlowiek, int prawo_czlowiek, int czy_czlowiek)
{
	for (int i = 0; i < przesuniecie*10; i++)
	{
	if (drawArea==NULL)
		InvalidateRect(hWnd, NULL, TRUE); 
	else
		InvalidateRect(hWnd, drawArea, TRUE); 
	hdc = BeginPaint(hWnd, &ps);
	MyOnPaint(hdc, i, gora_dol, y1, y2, y3, y4, pion_czlowiek, lewo_czlowiek, prawo_czlowiek, czy_czlowiek); Sleep(10);
	EndPaint(hWnd, &ps);
	}
}
void repaintWindowDoor(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea, int przesuniecie, int stan_drzwi, int x1, int x2, int y1, int y2, int width)
{
	for (int i = 0; i < przesuniecie * 10; i++)
	{
		if (drawArea == NULL)
			InvalidateRect(hWnd, NULL, TRUE); 
		else
			InvalidateRect(hWnd, drawArea, TRUE); 
		hdc = BeginPaint(hWnd, &ps);
		MyOnPaintDoor(hdc, i, stan_drzwi, x1, x2, y1, y2, width); Sleep(10);
		EndPaint(hWnd, &ps);
	}
}
void repaintWindowHumanIn(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea, int przesuniecie, int jak_isc, int ile_przeniesc)
{
	for (int i = 0; i < przesuniecie * 10*ile_przeniesc; i++)
	{
		if (drawArea == NULL)
			InvalidateRect(hWnd, NULL, TRUE);
		else
			InvalidateRect(hWnd, drawArea, TRUE);
		hdc = BeginPaint(hWnd, &ps);
		MyOnPaintHumanIn(hdc, i, jak_isc); Sleep(10);
		EndPaint(hWnd, &ps);
	}
}
void repaintWindowHumanOut(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea, int przesuniecie, int jak_isc, int ile_przesuniec)
{
	for (int i = 0; i < przesuniecie * 10*ile_przesuniec; i++)
	{
		if (drawArea == NULL)
			InvalidateRect(hWnd, NULL, TRUE);
		else
			InvalidateRect(hWnd, drawArea, TRUE);
		hdc = BeginPaint(hWnd, &ps);
		MyOnPaintHumanOut(hdc, i, jak_isc); Sleep(10);
		EndPaint(hWnd, &ps);
	}
}
void repaintWindowBackground(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	if (drawArea == NULL)
		InvalidateRect(hWnd, NULL, TRUE); 
	else
		InvalidateRect(hWnd, drawArea, TRUE); 
	hdc = BeginPaint(hWnd, &ps);
	MyOnPaintBackground(hdc);

	EndPaint(hWnd, &ps);
}

void inputData()
{	
	data.push_back(Point(0, 0));
	for (int i = 1; i < 100; i++){
		data.push_back(Point(2*i+1, 200 * rand()/RAND_MAX));
	}
}

int OnCreate(HWND window)
{
	inputData();
	return 0;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;
	HACCEL hAccelTable;

	value = 0;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);


	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;


	hInst = hInstance;

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	hwndButton = CreateWindow(TEXT("button"),             
		TEXT("Piêtro1"),                  
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  
		300, 0,                                 
		80, 50,                          
		hWnd,                                
		(HMENU)ID_BUTTON2,                  
		hInstance,                           
		NULL);
	hwndButton = CreateWindow(TEXT("button"),
		TEXT("Piêtro2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		900, 0,
		80, 50,
		hWnd,
		(HMENU)ID_BUTTON1,
		hInstance,
		NULL);
                                                     
	OnCreate(hWnd);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	int przesuniecie;
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON1:
			switch (jak_sie_ruszyc)
			{
			case 1:
				przesuniecie = 31;
				repaintWindowDoor(hWnd, hdc, ps, &drawArea4, przesuniecie, 0, 840, 853.5, 178, 309, 11);
				repaintWindowHumanOut(hWnd, hdc, ps, &drawArea4_5, przesuniecie, 1, 2);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea4, przesuniecie, 1, 840, 853.5, 178, 178, 11);
				repaintWindow(hWnd, hdc, ps, &drawArea3, przesuniecie, 1, 173, 170, 310, 313, 255, 225, 285,0);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea2, przesuniecie, 0, 501, 509, 15, 150, 6);
				repaintWindowHumanIn(hWnd, hdc, ps, &drawArea2_5, przesuniecie, 1, 5);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea2, przesuniecie, 1, 501, 509, 15, 15, 6);
				jak_sie_ruszyc = 0;
				break;
			case 0:
				przesuniecie = 31;
				repaintWindow(hWnd, hdc, ps, &drawArea3, przesuniecie, 0, 18, 15, 155, 158, 100, 70, 130, 1);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea4, przesuniecie, 0, 840, 853.5, 178, 309, 11);
				repaintWindowHumanOut(hWnd, hdc, ps, &drawArea4_5, przesuniecie, 1, 2);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea4, przesuniecie, 1, 840, 853.5, 178, 178, 11);
				repaintWindow(hWnd, hdc, ps, &drawArea3, przesuniecie, 1, 173, 170, 310, 313, 255, 225, 285, 0);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea2, przesuniecie, 0, 501, 509, 15, 150, 6);
				repaintWindowHumanIn(hWnd, hdc, ps, &drawArea2_5, przesuniecie, 1, 5);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea2, przesuniecie, 1, 501, 509, 15, 15, 6);
				jak_sie_ruszyc = 0;
				break;
			}
			break;
		case ID_BUTTON2:
			switch(jak_sie_ruszyc)
			{
			case 0:
				przesuniecie = 31;
				repaintWindowDoor(hWnd, hdc, ps, &drawArea2, przesuniecie, 0, 501, 509, 15, 150,6);
				repaintWindowHumanIn(hWnd, hdc, ps, &drawArea2_5, przesuniecie,0,4);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea2, przesuniecie, 1, 501, 509, 15, 15,6);
				repaintWindow(hWnd, hdc, ps, &drawArea3, przesuniecie, 0, 18, 15, 155, 158, 100, 70, 130,0);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea4, przesuniecie, 0, 840, 853.5, 178, 309, 11);
				repaintWindowHumanOut(hWnd, hdc, ps, &drawArea4_5, przesuniecie, 0, 3);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea4, przesuniecie, 1, 840, 853.5, 178, 178,11);
				jak_sie_ruszyc = 1;
				break;
			case 1:
				przesuniecie = 31;
				repaintWindow(hWnd, hdc, ps, &drawArea3, przesuniecie, 1, 173, 170, 310, 313, 100, 70, 130,1);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea2, przesuniecie, 0, 501, 509, 15, 150, 6);
				repaintWindowHumanIn(hWnd, hdc, ps, &drawArea2_5, przesuniecie ,0,4);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea2, przesuniecie, 1, 501, 509, 15, 15, 6);
				repaintWindow(hWnd, hdc, ps, &drawArea3, przesuniecie, 0, 18, 15, 155, 158, 100, 70, 130,0);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea4, przesuniecie, 0, 840, 853.5, 178, 309, 11);
				repaintWindowHumanOut(hWnd, hdc, ps, &drawArea4_5, przesuniecie ,0,3);
				repaintWindowDoor(hWnd, hdc, ps, &drawArea4, przesuniecie, 1, 840, 853.5, 178, 178, 11);
				jak_sie_ruszyc = 1;
				break;
			}
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		repaintWindowBackground(hWnd, hdc, ps, &drawArea1);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
