#pragma once

#include "framework.h"

using TableCallback = void(*)(int);

class TableController
{
private:
	static TableCallback deleteCallback;
	static TableCallback selectCallback;
	HWND hWnd;
	HWND hWndList;
	int counter;
	TableController()
	{
		this->hWnd = NULL;
		this->hWndList = NULL;
		this->counter = 0;
	}
	TableController(const TableController&);
	TableController& operator=(TableController&);
	static BOOL CALLBACK tableCallback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	void deleteEntry();
	void updateCounter(int state);
public:
	static TableController& getInstance()
	{
		static TableController instance;
		return instance;
	}
	void init(HINSTANCE hInst, HWND hWndParent, TableCallback _deleteCallback);
	void show();
	void add(const char* message);
	void removeLast();
	void clearAll();
};
