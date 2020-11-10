#pragma once

#include "framework.h"
#include "shape_editor.h"

using Factory = ShapeEditor(*)(HWND);

class Tool
{
public:
	static const Tool POINT;
	static const Tool LINE;
	static const Tool RECT;
	static const Tool ELLIPSE;

private:
	LPCSTR title;
	int menuItemId;
	int toolbarItemId;
	Factory factory;
	Tool(LPCSTR _title, int _menuItemId, int _toolbarItemuId, Factory _factory);

public:
	LPCSTR getTitle();
	int getMenuItemId();
	int getToolbarItemId();
};
