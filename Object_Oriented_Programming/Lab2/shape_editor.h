#pragma once

#include "framework.h"
#include "editor.h"

class ShapeEditor : public Editor
{
protected:
	POINT point;
	HDC hdc;
	short x1;
	short y2;
	short x2;
	short y2;

public:
	ShapeEditor(void);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};
