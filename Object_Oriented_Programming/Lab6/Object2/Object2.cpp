#include "Object2.h"

#include "math.h"
#include <string>

#define MAX_LOADSTRING 100

#define WINDOW_POSX 200
#define WINDOW_POSY 400
#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 300

// Global Variables
HINSTANCE hInst;
HWND hWnd;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

int hWndParent;
int* matrixParams;
int** matrix;

// Function Declaration
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

static int putTextToClipboard(HWND hWnd, const char* src);
static void onCopyData(WPARAM wParam, LPARAM lParam);
static void prepareMatrix();
static void printMatrix(HDC hdc);
static void putMatrixToClipboard();
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
    LoadStringW(hInstance, IDC_OBJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OBJECT2));
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OBJECT2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OBJECT2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;
   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      WINDOW_POSX, WINDOW_POSY, WINDOW_WIDTH, WINDOW_HEIGHT,
      nullptr, nullptr, hInstance, nullptr);
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
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_COPYDATA:
        onCopyData(wParam, lParam);
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            printMatrix(hdc);
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

static int putTextToClipboard(HWND hWnd, const char* src) {
    HGLOBAL hglbCopy;
    BYTE* pTmp;
    long len;
    if (src == NULL) return 0;
    if (src[0] == 0) return 0;
    len = strlen(src);
    hglbCopy = GlobalAlloc(GHND, len + 1);
    if (hglbCopy == NULL) return FALSE;
    pTmp = (BYTE*)GlobalLock(hglbCopy);
    memcpy(pTmp, src, len + 1);
    GlobalUnlock(hglbCopy);
    if (!OpenClipboard(hWnd))
    {
        GlobalFree(hglbCopy);
        return 0;
    }
    EmptyClipboard(); SetClipboardData(CF_TEXT, hglbCopy); CloseClipboard();
    return 1;
}

static void onCopyData(WPARAM wParam, LPARAM lParam)
{
    COPYDATASTRUCT* cds = (COPYDATASTRUCT*)lParam;
    if (!hWndParent)
    {    
        hWndParent = (long)wParam;
    }
    int* inputData = (int*)cds->lpData;
    matrixParams = new int[3];
    matrixParams[0] = inputData[0];
    matrixParams[1] = inputData[1];
    matrixParams[2] = inputData[2];
    prepareMatrix();
}

static void prepareMatrix()
{
    int n = matrixParams[0];
    int Min = matrixParams[1];
    int Max = matrixParams[2];
    matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 2; // TODO: range
        }
    }
    InvalidateRect(hWnd, NULL, FALSE);
    putMatrixToClipboard();
    sendParentContinue();
}

static void printMatrix(HDC hdc)
{
    if (!matrixParams)
    {
        return;
    }
    int n = matrixParams[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value = matrix[i][j];
            int digits = log10(value) + 1;
            TextOutA(
                hdc,
                20 + 20 * j,
                20 + 20 * i,
                std::to_string(value).c_str(),
                digits
            );
        }
    }
}

static void putMatrixToClipboard()
{
    std::string charMatrix = "";
    int n = matrixParams[0];
    for (int i = 0; i < n; i++)
    {
        charMatrix += "\n";
        for (int j = 0; j < n; j++)
        {
            charMatrix += std::to_string(matrix[i][j]) + "\t";
        }
    }
    putTextToClipboard(hWnd, charMatrix.c_str());
}

static void sendParentContinue()
{
    PostMessage((HWND)hWndParent, WM_COMMAND, PARENT_DATA, 0);
}
