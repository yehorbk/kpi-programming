#pragma once

#include "shape_editor.h"

class LineEditor : public ShapeEditor
{
public:
	LineEditor(HWND _hWnd);
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
};
