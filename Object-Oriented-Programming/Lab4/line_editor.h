#pragma once

#include "shape_editor.h"

class LineEditor : public ShapeEditor
{
public:
	LineEditor(HWND _hWnd);
	void OnLBup();
	void OnMouseMove();
};
