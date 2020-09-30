#pragma once

#include "framework.h"
#include "editor.h"

class ShapeEditor : public Editor
{
protected:
	HWND hWnd;
	short x1;
	short y1;
	short x2;
	short y2;

public:
	ShapeEditor(HWND hWnd);
	HDC openDrawer();
	void closeDrawer(HDC hdc);
	POINT getMousePosition();
};
