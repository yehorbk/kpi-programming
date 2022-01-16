﻿/*
    PROJECT INFORMATION - Laboratory Work 1
    AUTHOR: YEHOR BUBLYK
    GROUP: IP-94
    NUMBER: 5
    FORMULA: B1 = NUMBER % 4; B2 = (NUMBER + 1) % 4
    VARIABLES: B1 = 1; B2 = 2
*/

#include <string>

#include "framework.h"
#include "Lab1.h"

#include "Scroll.h"
#include "FirstStep.h"
#include "SecondStep.h"
#include "StepActionType.h"

#define MAX_LOADSTRING 100

// Global Variables
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];
int* scrollValue = new int(-1);

// Functions declaration
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void                drawScrollValue(HDC hdc);
void                callScrollDialog(HWND hWnd);
void                callFirstStepDialog(HWND hWnd);
void                callSecondStepDialog(HWND hWnd);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initializing global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Initializing application
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB1));
    MSG msg;
    // Main message cycle
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB1);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
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
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDM_WORK_1:
            callScrollDialog(hWnd);
            break;
        case IDM_WORK_2:
            callFirstStepDialog(hWnd);
            break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
        drawScrollValue(hdc);
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

void drawScrollValue(HDC hdc)
{
    int position = *scrollValue;
    if (position != -1) {
        int digits = log10(position) + 1;
        char result[4];
        _itoa_s(position, result, 10);
        TextOutA(hdc, 200, 200, LPCSTR(result), digits);
    }
}

void callScrollDialog(HWND hWnd) 
{
    int scrollDialogResult = scrollInterface(hInst, hWnd, scrollValue);
    if (scrollDialogResult == IDOK)
    {
        RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
    }
}

void callFirstStepDialog(HWND hWnd)
{
    int firstStepDialogResult = firstStepInterface(hInst, hWnd);
    switch (firstStepDialogResult)
    {
    case STEP_NEXT:
        callSecondStepDialog(hWnd);
        break;
    }
}

void callSecondStepDialog(HWND hWnd)
{
    int secondStepDialogResult = secondStepInterface(hInst, hWnd);
    switch (secondStepDialogResult)
    {
    case STEP_BACK:
        callFirstStepDialog(hWnd);
        break;
    }
}
