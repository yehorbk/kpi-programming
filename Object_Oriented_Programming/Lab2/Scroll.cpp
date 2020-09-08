#include "Scroll.rh"
#include "Scroll.h";


int scrollInterface(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(
		hInst,
		MAKEINTRESOURCE(IDD_SCROLL_DI),
		hWnd,
		scrollCallback,
	);
}

static void scrollHandler(HWND hWnd, WPARAM wParam)
{
	int position = GetScrollPos(GetDlgItem(hWnd, -1), SB_CTL);
	switch (LOWORD(position))
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
	SetScrollPos(hWnd, SB_CTL, position, TRUE);
}

static BOOL CALLBACK scrollCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage) {
		case WM_INITDIALOG:

			break;
		case WM_COMMAND:

			break;
		case WM_HSCROLL:
			scrollHandler(hDlg, wParam);
			break;
	}
	return FALSE;
}
