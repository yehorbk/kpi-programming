#include "Scroll.rh"
#include "Scroll.h"

static HWND hScrl;
static int *scrollValue;
static int scrollPosition;

static BOOL CALLBACK scrollCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM);

static void init(HWND hDlg);
static void prepareScrollBar();
static void scrollHandler(WPARAM wParam);

int scrollInterface(HINSTANCE hInst, HWND hWnd, int *value)
{
	scrollValue = value;
	return DialogBox(
		hInst,
		MAKEINTRESOURCE(IDD_SCROLL),
		hWnd,
		scrollCallback,
	);
}

static BOOL CALLBACK scrollCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage) {
	case WM_INITDIALOG:
		init(hDlg);
		break;
	case WM_COMMAND:
		switch LOWORD(wParam) {
		case IDOK:
			*scrollValue = scrollPosition;
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
	const int MIN = 1, MAX = 100, DEFAULT = 50;
	scrollPosition = *scrollValue == -1 ? DEFAULT : *scrollValue;
	SetScrollRange(hScrl, SB_CTL, MIN, MAX, TRUE);
	SetScrollPos(hScrl, SB_CTL, scrollPosition, TRUE);
}

static void scrollHandler(WPARAM wParam)
{
	scrollPosition = GetScrollPos(hScrl, SB_CTL);
	switch (LOWORD(wParam))
	{
	case SB_LINELEFT:
		scrollPosition--;
		break;
	case SB_LINERIGHT:
		scrollPosition++;
		break;
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		scrollPosition = HIWORD(wParam);
		break;
	}
	SetScrollPos(hScrl, SB_CTL, scrollPosition, TRUE);
}
