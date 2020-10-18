#pragma once

#include "framework.h"
#include <CommCtrl.h>
#pragma comment(lib, "comctl32.lib")

#include "toolbar.rh"
#include "tool.h"

class ToolbarController
{
private:
	HWND instance;
	HWND parent;
	int selectedToolId;
	void generateButtons();
	void resetAllButtons();

public:
	ToolbarController(HWND hWnd);
	bool OnButtonPress(Tool tool);
	void OnNotify(WPARAM wParam, LPARAM lParam);
	void OnSize();
};
