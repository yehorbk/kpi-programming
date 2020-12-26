#include "Object3.h"

#include "math.h"
#include <string>

#define MAX_LOADSTRING 100

#define WINDOW_POSX 800
#define WINDOW_POSY 400
#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 300

// Global Variables
HINSTANCE hInst;
HWND hWnd;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

int hWndParent;
int** matrix;
int matrixSize;
int determinant;

// Function Declaration
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

static void cleanAllMemory();
static long getTextFromClipboard(HWND hWnd, char* dest, long maxsize);
static void prepareDeterminant();
static void parseMatrix();
static int findDeterminant(int** _matrix, int n);
static void printDeterminant(HDC hdc);
static void sendParentContinue();
static void sendParentFinish();

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
            case PARENT_FINISH:
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case PARENT_DATA:
                cleanAllMemory();
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
        cleanAllMemory();
        sendParentFinish();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

static void cleanAllMemory()
{
    if (matrixSize)
    {
        int n = matrixSize;
        for (int i = 0; i < n; i++)
        {
            delete matrix[i];
        }
        delete[] matrix;
    }
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

static void prepareDeterminant()
{
    parseMatrix();
    determinant = findDeterminant(matrix, matrixSize);
    InvalidateRect(hWnd, NULL, TRUE);
    sendParentContinue();
}

static void parseMatrix()
{
    char* buffer = new char[1024];
    int size = getTextFromClipboard(hWnd, buffer, 1024);
    char* data = new char[size + 1];
    strcpy_s(data, size + 1, buffer);
    delete[] buffer;
    std::string stringData = std::string(data);
    int n = 0;
    int lineIndex = -1;
    while ((lineIndex = stringData.find("\n", lineIndex + 1)) < stringData.size())
    {
        n++;
    }
    matrixSize = n;
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

static int findDeterminant(int** _matrix, int n) {
    int _determinant = 0;
    int** temp = new int*[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = new int[n];
    }
    if (n == 1) {
        return _matrix[0][0];
    }
    else if (n == 2) {
        _determinant = (_matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0]);
        return _determinant;
    }
    else {
        for (int p = 0; p < n; p++) {
            int h = 0;
            int k = 0;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == p) {
                        continue;
                    }
                    temp[h][k] = _matrix[i][j];
                    k++;
                    if (k == n - 1) {
                        h++;
                        k = 0;
                    }
                }
            }
            _determinant = _determinant + _matrix[0][p] * pow(-1, p) * findDeterminant(temp, n - 1);
        }
        return _determinant;
    }
}

static void printDeterminant(HDC hdc)
{
    if (!matrix)
    {
        return;
    }
    int value = determinant;
    int digits = value == 0 ? 1 : log10(abs(value)) + (value > 0 ? 1 : 2);
    TextOutA(hdc, 20, 20, std::to_string(value).c_str(), digits);
}

static void sendParentContinue()
{
    PostMessage((HWND)hWndParent, WM_COMMAND, PARENT_DATA, 0);
}

static void sendParentFinish()
{
    PostMessage((HWND)hWndParent, WM_COMMAND, PARENT_FINISH, 0);
}
