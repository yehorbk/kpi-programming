#pragma once

#include "shape_editor.h"

class EllipseEditor : public ShapeEditor
{
public:
	EllipseEditor(HWND _hWnd);
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
};
