#include "SecondStep.rh"
#include "SecondStep.h"

#include "StepActionType.h"

static BOOL CALLBACK secondStepCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM);

int secondStepInterface(HINSTANCE hInst, HWND hWnd)
{
	return DialogBox(
		hInst,
		MAKEINTRESOURCE(IDD_SECOND_STEP),
		hWnd,
		secondStepCallback,
	);
}

BOOL CALLBACK secondStepCallback(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage) {
	case WM_INITDIALOG:
		// TODO
		break;
	case WM_COMMAND:
		switch LOWORD(wParam) {
		case IDC_BACK:
			EndDialog(hDlg, STEP_BACK);
			break;
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
