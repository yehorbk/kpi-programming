/*
    PROJECT INFORMATION - Laboratory Work 5
    AUTHOR: YEHOR BUBLYK
    GROUP: IP-94
    NUMBER: 5
    VARIABLES:
    - MyEditor у выглядi Singleton Меєрса
*/

#include "Lab5.rh"
#include "Lab5.h"

#include "toolbar_controller.h"
#include "table_controller.h"
#include "about.h"
#include "main_editor.h"
#include "tool.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ToolbarController* toolbarController;
TableController& tableController = tableController.getInstance();
MainEditor& mainEditor = mainEditor.getInstance();

// Functions Declaration
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

static void changeTool(HWND hWnd, Tool tool);
static void updateWindowTitle(HWND hWnd, LPCSTR title);
static void updateMenuItem(HWND hWnd, int id);
static void importProject();
static void disableEdition(HWND hWnd);
static void appendToTable();
static void selectObject(int index);
static void deleteObject(int index);

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
        tableController.init(hInst, hWnd, selectObject, deleteObject);
        mainEditor.init(hWnd);
        importProject();
        break;
    case WM_LBUTTONDOWN:
        mainEditor.OnLBdown();
        break;
    case WM_LBUTTONUP:
        mainEditor.OnLBup();
        appendToTable();
        break;
    case WM_MOUSEMOVE:
        mainEditor.OnMouseMove();
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_EXPORT:
                mainEditor.exportProject(EXP_STATUS_MANUALLY);
                break;
            case IDM_IMPORT:
                importProject();
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_TOOL_POINT:
            case IDM_POINT:
                mainEditor.Start(Tool::POINT);
                changeTool(hWnd, Tool::POINT);
                break;
            case ID_TOOL_LINE:
            case IDM_LINE:
                mainEditor.Start(Tool::LINE);
                changeTool(hWnd, Tool::LINE);
                break;
            case ID_TOOL_RECT:
            case IDM_RECT:
                mainEditor.Start(Tool::RECT);
                changeTool(hWnd, Tool::RECT);
                break;
            case ID_TOOL_ELLIPSE:
            case IDM_ELLIPSE:
                mainEditor.Start(Tool::ELLIPSE);
                changeTool(hWnd, Tool::ELLIPSE);
                break;
            case ID_TOOL_OLINEO:
            case IDM_OLINEO:
                mainEditor.Start(Tool::OLINEO);
                changeTool(hWnd, Tool::OLINEO);
                break;
            case ID_TOOL_CUBE:
            case IDM_CUBE:
                mainEditor.Start(Tool::CUBE);
                changeTool(hWnd, Tool::CUBE);
                break;
            case IDM_UNDO:
                mainEditor.deleteLastObject();
                tableController.removeLast();
                break;
            case IDM_CLEAR:
                mainEditor.clearAll();
                tableController.clearAll();
                break;
            case IDM_TABLE:
                tableController.showWindow();
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
            mainEditor.OnPaint();
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
    if (toolbarController->OnButtonPress(tool))
    {
        mainEditor.enableEditor();
        updateWindowTitle(hWnd, tool.getTitle());
        updateMenuItem(hWnd, tool.getMenuItemId());
    }
    else
    {
        mainEditor.disableEditor();
        disableEdition(hWnd);
    }
}

static void updateWindowTitle(HWND hWnd, LPCSTR title)
{
    SetWindowTextA(hWnd, title ? title : "Lab5");
}

static void updateMenuItem(HWND hWnd, int id)
{
    HMENU hMenu = GetMenu(hWnd);
    HMENU hSubMenu = GetSubMenu(hMenu, 1);
    CheckMenuItem(hSubMenu, IDM_POINT, MF_UNCHECKED);
    CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
    CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
    CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED);
    CheckMenuItem(hSubMenu, IDM_OLINEO, MF_UNCHECKED);
    CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
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

static void importProject()
{
    mainEditor.importProject();
    const char** serializedShapes = mainEditor.getAllObjectsLocalized();
    if (serializedShapes)
    {
        const char* line;
        int counter = 0;
        while ((line = serializedShapes[counter++]) != NULL)
        {
            tableController.add(line);
        }
    }
}

static void appendToTable()
{
    const char* message = mainEditor.getLastObjectLocalized();
    if (message != NULL)
    {
        tableController.add(message);
    }
}

static void selectObject(int index)
{
    mainEditor.selectObject(index);
}

static void deleteObject(int index)
{
    mainEditor.deleteObject(index);
}
