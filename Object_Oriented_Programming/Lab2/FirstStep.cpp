#include "FirstStep.rh"
#include "FirstStep.h"

#include "StepActionType.h"

static BOOL CALLBACK firstStepCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM);

int firstStepInterface(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(
		hInst,
		MAKEINTRESOURCE(IDD_FIRST_STEP),
		hWnd,
		firstStepCallback,
	);
}

BOOL CALLBACK firstStepCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage) {
	case WM_INITDIALOG:
		// TODO
		break;
	case WM_COMMAND:
		switch LOWORD(wParam) {
		case IDC_NEXT:
			EndDialog(hDlg, STEP_NEXT);
			break;
		case IDC_CANCEL:
			EndDialog(hDlg, STEP_CANCEL);
			break;
		}
		break;
	}
	return FALSE;
}
