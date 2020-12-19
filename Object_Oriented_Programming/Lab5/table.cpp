#include "table.h"
#include "table.rh"

static BOOL CALLBACK tableCallback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

HWND tableInterface(HINSTANCE hInst, HWND hWnd)
{
	return CreateDialog(
		hInst,
		MAKEINTRESOURCE(IDD_TABLE),
		hWnd,
		tableCallback
	);
}

static BOOL CALLBACK tableCallback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return TRUE;
        }
        break;
    }
    return FALSE;
}
