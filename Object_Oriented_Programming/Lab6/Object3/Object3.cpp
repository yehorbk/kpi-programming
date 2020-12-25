#include "Object3.h"

#include "math.h"
#include <string>

#define MAX_LOADSTRING 100

// Global Variables
HINSTANCE hInst;
HWND hWnd;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

int hWndParent;
int** matrix;
int* determinant;

// Function Declaration
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

static long getTextFromClipboard(HWND hWnd, char* dest, long maxsize);
static void parseMatrix();
static void findDeterminant();
static void prepareDeterminant();
static void printDeterminant(HDC hdc);
static void sendParentContinue();

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    hWndParent = _wtoi(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_OBJECT3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OBJECT3));
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OBJECT3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OBJECT3);
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
        if (hWndParent)
        {
            PostMessage((HWND)hWndParent, WM_COMMAND, PARENT_HWND, (LPARAM)hWnd);
        }
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case PARENT_DATA:
                if (!hWndParent)
                {
                    hWndParent = (long)lParam;
                }
                prepareDeterminant();
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            printDeterminant(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

static long getTextFromClipboard(HWND hWnd, char* dest, long maxsize) {
    HGLOBAL hglb;
    LPSTR lptstr;
    long size, res;
    res = 0;
    if (!IsClipboardFormatAvailable(CF_TEXT)) return 0; if (!OpenClipboard(hWnd)) return 0;
    hglb = GetClipboardData(CF_TEXT);
    if (hglb != NULL)
    {
        lptstr = (char*)GlobalLock(hglb);
        if (lptstr != NULL)
        {
            size = strlen(lptstr);
            if (size > maxsize)
            {
                lptstr[maxsize] = 0;
                size = strlen(lptstr);
            }
            strcpy_s(dest, size + 1, lptstr);
            res = size;
            GlobalUnlock(hglb);
        }
    }
    CloseClipboard();
    return res;
}

static void parseMatrix()
{
    char* data = new char;
    getTextFromClipboard(hWnd, data, LONG_MAX);
    std::string stringData = std::string(data);
    int n = 0;
    int lineIndex = -1;
    while ((lineIndex = stringData.find("\n", lineIndex + 1)) < stringData.size())
    {
        n++;
    }
    matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        stringData = stringData.substr(
            stringData.find("\n") + 1,
            stringData.size()
        );
        for (int j = 0; j < n; j++)
        {
            std::string value = stringData.substr(0, stringData.find("\t"));
            stringData = stringData.substr(
                stringData.find("\t") + 1,
                stringData.size()
            );
            matrix[i][j] = std::stoi(value);
        }
    }
}

static void findDeterminant()
{
    determinant = new int;
    *determinant = 40;
    // TODO: find determinant
}

static void prepareDeterminant()
{
    parseMatrix();
    findDeterminant();
    InvalidateRect(hWnd, NULL, FALSE);
    sendParentContinue();
}

static void printDeterminant(HDC hdc)
{
    if (!determinant)
    {
        return;
    }
    int value = *determinant;
    int digits = log10(value) + 1;
    TextOutA(hdc, 20, 20, std::to_string(value).c_str(), digits);
}

static void sendParentContinue()
{
    PostMessage((HWND)hWndParent, WM_COMMAND, PARENT_DATA, 0);
}
