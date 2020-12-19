#include "table_controller.h"
#include "table.h"

TableController::TableController()
{
	this->hWnd = hWnd;
}

void TableController::init(HINSTANCE hInst, HWND parentHWND)
{
	this->hWnd = tableInterface(hInst, parentHWND);
}

void TableController::show()
{
	ShowWindow(this->hWnd, SW_SHOW);
}
