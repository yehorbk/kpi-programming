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
	Tool(LPCSTR _title, int _menuItemId);

public:
	LPCSTR getTitle();
	int getMenuItemId();
};
