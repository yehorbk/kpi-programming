#pragma once

#include "framework.h"

class TableController
{
private:
	HWND hWnd;
public:
	TableController();
	// ~TableController();
	void init(HINSTANCE hInst, HWND parentHWND);
	void show();
	// void add();
	// void delete();
};
