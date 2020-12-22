#include "table_controller.h"
#include "table.rh"
#include "common.h"

#define CR_INCREASE 1
#define CR_DECREASE -1
#define CR_CLEAR 0

TableCallback TableController::deleteCallback;
TableCallback TableController::selectCallback;

BOOL CALLBACK TableController::tableCallback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		case IDC_SELECT:
			TableController::getInstance().selectEntry();
			break;
		case IDC_DELETE:
			TableController::getInstance().deleteEntry();
			break;
		}
		break;
	}
	return FALSE;
}

void TableController::selectEntry()
{
	int index = SendMessage(this->hWndList, LB_GETCURSEL, 0, 0);
	if (index != LB_ERR)
	{
		TableController::selectCallback(index);
	}
}

void TableController::deleteEntry()
{
	int index = SendMessage(this->hWndList, LB_GETCURSEL, 0, 0);
	if (index != LB_ERR)
	{
		this->updateCounter(CR_DECREASE);
		SendMessage(this->hWndList, LB_DELETESTRING, WPARAM(index), 0);
		TableController::deleteCallback(index);
	}
}

void TableController::init(HINSTANCE hInst, HWND hWndParent, TableCallback _selectCallback, TableCallback _deleteCallback)
{
	this->hWnd = CreateDialog(
		hInst,
		MAKEINTRESOURCE(IDD_TABLE),
		hWndParent,
		TableController::tableCallback
	);
	this->hWndList = GetDlgItem(this->hWnd, IDC_LIST);
	TableController::selectCallback = _selectCallback;
	TableController::deleteCallback = _deleteCallback;
}

void TableController::show()
{
	ShowWindow(this->hWnd, SW_SHOW);
}

void TableController::add(const char* message)
{
	SendMessageA(this->hWndList, LB_INSERTSTRING, WPARAM(this->counter), LPARAM(message));
	this->updateCounter(CR_INCREASE);
}

void TableController::removeLast()
{
	this->updateCounter(CR_DECREASE);
	SendMessageA(this->hWndList, LB_DELETESTRING, WPARAM(this->counter), 0);
}

void TableController::clearAll()
{
	SendMessageA(this->hWndList, LB_RESETCONTENT, 0, 0);
	this->updateCounter(CR_CLEAR);
}

void TableController::updateCounter(int state)
{
	switch (state)
	{
	case CR_DECREASE:
		if (this->counter != 0)
		{
			this->counter -= 1;
		}
		break;
	case CR_CLEAR:
		this->counter = 0;
		break;
	case CR_INCREASE:
		this->counter += 1;
		break;
	default:
		break;
	}
	SetDlgItemInt(this->hWnd, IDC_COUNTER, this->counter, TRUE);
}
