#include "table_controller.h"
#include "table.h"
#include "table.rh"
#include "counter_state.h"
#include "common.h"

#include <string>

TableController::TableController()
{
	this->hWnd = NULL;
	this->hWndList = NULL;
	this->counter = 0;
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
