#include "Scroll.rh"
#include "Scroll.h"

static HWND hScrl;
static int scrollValue = -1;

static BOOL CALLBACK scrollCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM);
static void init(HWND hDlg);
static void prepareScrollBar();
static void scrollHandler(WPARAM wParam);

int scrollInterface(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(
		hInst,
		MAKEINTRESOURCE(IDD_SCROLL),
		hWnd,
		scrollCallback,
	);
}

int getScrollValue()
{
	return scrollValue;
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
			scrollValue = -1;
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
	int min = 1, max = 100, def = 50;
	SetScrollRange(hScrl, SB_CTL, min, max, TRUE);
	SetScrollPos(hScrl, SB_CTL, def, TRUE);
	scrollValue = def;
}

static void scrollHandler(WPARAM wParam)
{
	scrollValue = GetScrollPos(hScrl, SB_CTL);
	switch (LOWORD(wParam))
	{
	case SB_LINELEFT:
		scrollValue--;
		break;
	case SB_LINERIGHT:
		scrollValue++;
		break;
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		scrollValue = HIWORD(wParam);
		break;
	}
	SetScrollPos(hScrl, SB_CTL, scrollValue, TRUE);
}
