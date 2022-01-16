#include "input.rh"
#include "input.h"

static void (*callback)(int, int, int);
static BOOL CALLBACK inputCallback(HWND, UINT, WPARAM, LPARAM);
static bool checkIsCorreñtInput(int n, int Min, int Max);

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
        {
            long n = GetDlgItemInt(hDlg, IDC_EDIT_N, FALSE, true);
            long Min = GetDlgItemInt(hDlg, IDC_EDIT_MIN, FALSE, true);
            long Max = GetDlgItemInt(hDlg, IDC_EDIT_MAX, FALSE, true);
            if (checkIsCorreñtInput(n, Min, Max))
            {
                callback(n, Min, Max);
                EndDialog(hDlg, LOWORD(wParam));
            }
            else
            {
                MessageBoxA(
                    hDlg,
                    "Ïåðåâ³ðòå êîðåêòí³ñòü äàíèõ",
                    "Ïîìèëêà ââîäó",
                    MB_OK
                );
            }
            break;
        }
        case IDCANCEL:
            EndDialog(hDlg, LOWORD(wParam));
            break;
        }
        break;
    }
    return FALSE;
}

static bool checkIsCorreñtInput(int n, int Min, int Max)
{
    return (n > 0) && (Min < Max);
}
