#pragma once

#include "framework.h"

class TableController
{
private:
	HWND hWnd;
	HWND hWndList;
public:
	TableController();
	void init(HINSTANCE hInst, HWND hWndParent);
	void show();
	void add(const char* message);
	void removeLast();
	void clearAll();
};
