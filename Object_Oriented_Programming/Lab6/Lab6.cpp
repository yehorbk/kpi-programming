/*
    PROJECT INFORMATION - Laboratory Work 6
    AUTHOR: YEHOR BUBLYK
    GROUP: IP-94
    NUMBER: 5
    VARIABLES:
    - Користувач вводить значення n, Min, Max у дiалоговому вiкнi; виклик Object2 та Object3
    - Object2 створює матрицю nxnц цiлих (int) чисел у дiапазонi Min - Max;
      показує числовi значення;
      записує данi в Clipboard Windows у тектовому форматi;
    - Object3 зчитує данi з Clipboard Windows;
      вiдображає значення детермiнанту матрицi;
*/

#include "Lab6.rh"
#include "Lab6.h"

#include <string>

#include "about.h"
#include "input.h"

#define MAX_LOADSTRING 100

// Global Variables
HINSTANCE hInst;
HWND hWnd;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

long inputData[3];
// int* matrixData;
ChildProcessData childProcessData;

// Function Declaration
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

static void finishChildProcesses();
static int sendCopyData(HWND hWndSource, void* lp, long cb);
// static void onCopyData(WPARAM wParam, LPARAM lParam);
static void saveMatrixInfo(int n, int Min, int Max);
static void passDataToObject2();
static void passDataToObject3();

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB6, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB6));
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB6));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB6);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;
   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
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
    switch (message)
    {
    case WM_CREATE:
        childProcessData.hWndObject2 =
            (long)FindWindowA(childProcessData.identifierObject2, NULL);
        childProcessData.hWndObject3 =
            (long)FindWindowA(childProcessData.identifierObject3, NULL);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_INPUT:
                inputInterface(hInst, hWnd, saveMatrixInfo);
                break;
            case IDM_ABOUT:
                aboutInterface(hInst, hWnd);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case OBJECT2_HWND:
                childProcessData.hWndObject2 = (long)lParam;
                passDataToObject2();
                break;
            case OBJECT2_DATA:
                passDataToObject3();
                break;
            case OBJECT3_HWND:
                childProcessData.hWndObject3 = (long)lParam;
                passDataToObject3();
                break;
            case OBJECT3_DATA:
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    /*case WM_COPYDATA:
        onCopyData(wParam, lParam);
        break;*/
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        finishChildProcesses();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

static void finishChildProcesses()
{
    if (childProcessData.hWndObject2)
    {
        PostMessage(
            (HWND)childProcessData.hWndObject2,
            WM_COMMAND,
            (WPARAM)OBJECT2_FINISH,
            (LPARAM)hWnd
        );
    }
    if (childProcessData.hWndObject3)
    {
        PostMessage(
            (HWND)childProcessData.hWndObject3,
            WM_COMMAND,
            (WPARAM)OBJECT3_FINISH,
            (LPARAM)hWnd
        );
    }
}

static int sendCopyData(HWND hWndDest, void* lp, long cb)
{
    COPYDATASTRUCT cds;
    cds.dwData = 1;
    cds.lpData = lp;
    cds.cbData = cb;
    return SendMessage(hWndDest, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&cds);
}

/*static void onCopyData(WPARAM wParam, LPARAM lParam)
{
    COPYDATASTRUCT* cds = (COPYDATASTRUCT*)lParam;
    if ((long)wParam == childProcessData.hWndObject2)
    {
        matrixData = (int*)cds->lpData;
        passDataToObject3();
    }
}*/

static void saveMatrixInfo(int n, int Min, int Max)
{
    inputData[0] = n;
    inputData[1] = Min;
    inputData[2] = Max;
    passDataToObject2();
}

static void passDataToObject2()
{
    if (!childProcessData.hWndObject2)
    {
        long hWndIdentifier = (long)hWnd;
        std::string programNameParam =
            std::string(childProcessData.executableObject2) +
            " " + std::to_string(hWndIdentifier);
        WinExec(programNameParam.c_str(), SW_SHOW);
        return;
    }
    sendCopyData(
        (HWND)childProcessData.hWndObject2,
        inputData,
        sizeof(inputData)
    );
}

static void passDataToObject3()
{
    if (!childProcessData.hWndObject3)
    {
        long hWndIdentifier = (long)hWnd;
        std::string programNameParam =
            std::string(childProcessData.executableObject3) +
            " " + std::to_string(hWndIdentifier);
        WinExec(programNameParam.c_str(), SW_SHOW);
        return;
    }
    PostMessage(
        (HWND)childProcessData.hWndObject3,
        WM_COMMAND,
        (WPARAM)OBJECT3_DATA,
        (LPARAM)hWnd
    );
}
