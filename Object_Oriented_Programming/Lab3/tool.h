#pragma once

#include "framework.h"

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
	Tool(LPCSTR _title, int _menuItemId, int _toolbarItemuId);

public:
	LPCSTR getTitle();
	int getMenuItemId();
	int getToolbarItemId();
};
