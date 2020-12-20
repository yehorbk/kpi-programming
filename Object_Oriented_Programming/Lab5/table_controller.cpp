#include "table_controller.h"
#include "table.h"
#include "table.rh"

TableController::TableController()
{
	this->hWnd = NULL;
	this->hWndList = NULL;
}

void TableController::init(HINSTANCE hInst, HWND hWndParent)
{
	this->hWnd = tableInterface(hInst, hWndParent);
	this->hWndList = GetDlgItem(this->hWnd, IDC_LIST);
}

void TableController::show()
{
	ShowWindow(this->hWnd, SW_SHOW);
}

void TableController::add(const char* message)
{
	SendMessageA(this->hWndList, LB_ADDSTRING, 0, LPARAM(message));
}

void TableController::removeLast()
{
	SendMessageA(this->hWndList, LB_DELETESTRING, 0, 0);
}

void TableController::clearAll()
{
	SendMessageA(this->hWndList, LB_RESETCONTENT, 0, 0);
}
