/*
    PROJECT INFORMATION - Laboratory Work 4
    AUTHOR: YEHOR BUBLYK
    GROUP: IP-94
    NUMBER: 5
    VARIABLES:
    - глобальний статичний об'єкт класу MyEditor
    - гумовий слiд пунктирною лiнiєю
*/

#include "Lab4.rh"
#include "Lab4.h"

#include "toolbar_controller.h"
#include "about.h"
#include "shape_object_builder.h"
#include "main_editor.h"
#include "tool.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ToolbarController* toolbarController;
ShapeObjectBuilder* shapeObjectBuilder; // TODO: remove it 
MainEditor* mainEditor;

// Functions Declaration
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

static void changeTool(HWND hWnd, Tool tool);
static void updateWindowTitle(HWND hWnd, LPCSTR title);
static void updateMenuItem(HWND hWnd, int id);
static void disableEdition(HWND hWnd);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB4));
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB4);
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
        toolbarController = new ToolbarController(hWnd);
        shapeObjectBuilder = new ShapeObjectBuilder(hWnd);
        mainEditor = new MainEditor(hWnd);
        break;
    case WM_LBUTTONDOWN:
        // shapeObjectBuilder->OnLBdown();
        mainEditor->OnLBdown();
        break;
    case WM_LBUTTONUP:
        // shapeObjectBuilder->OnLBup();
        mainEditor->OnLBup();
        break;
    case WM_MOUSEMOVE:
        // shapeObjectBuilder->OnMouseMove(); // TODO: remove, deprecated
        mainEditor->OnMouseMove();
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_TOOL_POINT:
            case IDM_POINT:
                shapeObjectBuilder->StartPointEditor(); // TODO: remove, deprecated
                // mainEditor->Start();
                changeTool(hWnd, Tool::POINT);
                break;
            case ID_TOOL_LINE:
            case IDM_LINE:
                shapeObjectBuilder->StartLineEditor(); // TODO: remove, deprecated
                changeTool(hWnd, Tool::LINE);
                break;
            case ID_TOOL_RECT:
            case IDM_RECT:
                shapeObjectBuilder->StartRectEditor(); // TODO: remove, deprecated
                changeTool(hWnd, Tool::RECT);
                break;
            case ID_TOOL_ELLIPSE:
            case IDM_ELLIPSE:
                shapeObjectBuilder->StartEllipseEditor(); // TODO: remove, deprecated
                changeTool(hWnd, Tool::ELLIPSE);
                break;
            case IDM_UNDO:
                // shapeObjectBuilder->undo(); // TODO: remove, deprecated
                mainEditor->undo();
                break;
            case IDM_ABOUT:
                aboutInterface(hInst, hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_SIZE:
        toolbarController->OnSize();
        break;
    case WM_NOTIFY:
        toolbarController->OnNotify(wParam, lParam);
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // shapeObjectBuilder->OnPaint(); // TODO: remove, deprecated
            mainEditor->OnPaint();
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        delete shapeObjectBuilder; // TODO: remove, deprecated
        delete mainEditor;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

static void changeTool(HWND hWnd, Tool tool)
{
    if (toolbarController->OnButtonPress(tool))
    {
        // shapeObjectBuilder->enableEditor(); // TODO: remove, deprecated
        mainEditor->enableEditor();
        updateWindowTitle(hWnd, tool.getTitle());
        updateMenuItem(hWnd, tool.getMenuItemId());
    }
    else
    {
        // shapeObjectBuilder->disableEditor(); // TODO: remove, deprecated
        mainEditor->disableEditor();
        disableEdition(hWnd);
    }
}

static void updateWindowTitle(HWND hWnd, LPCSTR title)
{
    SetWindowTextA(hWnd, title ? title : "Lab3");
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

static void disableEdition(HWND hWnd)
{
    updateWindowTitle(hWnd, NULL);
    updateMenuItem(hWnd, -1);
}
