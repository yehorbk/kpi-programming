/*
    PROJECT INFORMATION - Laboratory Work 2
    AUTHOR: YEHOR BUBLYK
    GROUP: IP-94
    NUMBER: 5
    VARIABLES:
    - статичний масив для Shape (5 mod 3 = 2): обсягом 105 об'єктiв;
    - "гумовий" слiд (5 mod 4 = 1) - суцiльна лiнiя червоного кольору;
    - прямокутник:
        - вiд центру до одного з кутiв (5 mod 2 = 1);
        - чорний контур з бiлим заповненням (5 mod 5 = 0);
        - сiрий (5 mod 6 = 5); // Не потрiбно, тому що прямокутник з бiлим заповненням
    - елiпс:
        - по двом протилежним кутам охоплюючого прямокутника (5 mod 2 = 1);
        - чорний контур без заповнення (5 mod 5 = 0);
        - помаранчевий (5 mod 6 = 5); // Не потрiбно, тому що елiпс без заповнення
    - позначка поточного типу об'єкту: в заголовку вiкна (5 mod 2 = 1 ).
*/

#include "Shlwapi.h"

#include "Lab2.rh"
#include "Lab2.h"

#include "About.h"
#include "shape_object_builder.h"
#include "tool.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ShapeObjectBuilder* shapeObjectBuilder;

// Functions Declaration
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

static void changeTool(HWND hWnd, Tool tool);
static void updateWindowTitle(HWND hWnd, LPCSTR title);
static void updateMenuItem(HWND hWnd, int id);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB2));
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
        shapeObjectBuilder = new ShapeObjectBuilder(hWnd);
        break;
    case WM_LBUTTONDOWN:
        shapeObjectBuilder->OnLBdown();
        break;
    case WM_LBUTTONUP:
        shapeObjectBuilder->OnLBup();
        break;
    case WM_MOUSEMOVE:
        shapeObjectBuilder->OnMouseMove();
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_ABOUT:
                aboutInterface(hInst, hWnd);
                break;
            case IDM_POINT:
                changeTool(hWnd, Tool::POINT);
                shapeObjectBuilder->StartPointEditor();
                break;
            case IDM_LINE:
                changeTool(hWnd, Tool::LINE);
                shapeObjectBuilder->StartLineEditor();
                break;
            case IDM_RECT:
                changeTool(hWnd, Tool::RECT);
                shapeObjectBuilder->StartRectEditor();
                break;
            case IDM_ELLIPSE:
                changeTool(hWnd, Tool::ELLIPSE);
                shapeObjectBuilder->StartEllipseEditor();
                break;
            case IDM_UNDO:
                shapeObjectBuilder->undo();
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
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
            shapeObjectBuilder->OnPaint();
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

static void changeTool(HWND hWnd, Tool tool)
{
    updateWindowTitle(hWnd, tool.getTitle());
    updateMenuItem(hWnd, tool.getMenuItemId());
}

static void updateWindowTitle(HWND hWnd, LPCSTR title)
{
    SetWindowTextA(hWnd, title);
}

static void updateMenuItem(HWND hWnd, int id)
{
    HMENU hMenu = GetMenu(hWnd);
    HMENU hSubMenu = GetSubMenu(hMenu, 1);
    CheckMenuItem(hSubMenu, IDM_POINT, MF_UNCHECKED);
    CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
    CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
    CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED);
    if (id != -1)
    {
        CheckMenuItem(hSubMenu, id, MF_CHECKED);
    }
}
