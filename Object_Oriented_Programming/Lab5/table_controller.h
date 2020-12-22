#pragma once

#include "framework.h"

class TableController
{
private:
	HWND hWnd;
	HWND hWndList;
	int counter;
	void updateCounter(int state);
public:
	TableController();
	void init(HINSTANCE hInst, HWND hWndParent);
	void show();
	void add(const char* message);
	void removeLast();
	void clearAll();
};
