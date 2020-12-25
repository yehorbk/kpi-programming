#include "input.rh"
#include "input.h"

static void (*callback)(int, int, int);
static BOOL CALLBACK inputCallback(HWND, UINT, WPARAM, LPARAM);

int inputInterface(HINSTANCE hInst, HWND hWnd, void (*_callback)(int, int, int))
{
    callback = _callback;
    return DialogBox(
        hInst,
        MAKEINTRESOURCE(IDD_INPUT),
        hWnd,
        inputCallback
    );
}

static BOOL CALLBACK inputCallback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDOK:
            // TODO
            callback(1, 2, 3);
            break;
        case IDCANCEL:
            EndDialog(hDlg, LOWORD(wParam));
            break;
        }
        break;
    }
    return FALSE;
}
