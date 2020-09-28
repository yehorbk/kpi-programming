#pragma once

#include "framework.h"
#include "editor.h"

class ShapeEditor : public Editor
{
public:
	ShapeEditor(void);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};
