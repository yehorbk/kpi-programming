#include "Scroll.rh"
#include "Scroll.h"

#include <string>

static HWND hScrl;

static BOOL CALLBACK scrollCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM);
static void init(HWND hDlg);
static void prepareScrollBar();
static void scrollHandler(HWND hWnd, WPARAM wParam);

int scrollInterface(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(
		hInst,
		MAKEINTRESOURCE(IDD_SCROLL),
		hWnd,
		scrollCallback,
	);
}

BOOL CALLBACK scrollCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage) {
	case WM_INITDIALOG:
		init(hDlg);
		break;
	case WM_COMMAND:
		switch LOWORD(wParam) {
		case IDOK:
			EndDialog(hDlg, LOWORD(wParam));
			break;
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			break;
		}
		break;
	case WM_HSCROLL:
		scrollHandler(wParam);
		break;
	}
	return FALSE;
}

static void init(HWND hDlg)
{
	hScrl = GetDlgItem(hDlg, IDC_SCROLLBAR);
	prepareScrollBar();
}

static void prepareScrollBar()
{
	SetScrollRange(hScrl, SB_CTL, 0, 100, TRUE);
	SetScrollPos(hScrl, SB_CTL, 50, TRUE);
}

static void scrollHandler(WPARAM wParam)
{
	int position = GetScrollPos(hScrl, SB_CTL);
	switch (LOWORD(wParam))
	{
	case SB_LINELEFT:
		position--;
		break;
	case SB_LINERIGHT:
		position++;
		break;
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		position = HIWORD(wParam);
		break;
	}
	SetScrollPos(hScrl, SB_CTL, position, TRUE);
}
