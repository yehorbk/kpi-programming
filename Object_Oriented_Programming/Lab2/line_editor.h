#pragma once

#include "shape_editor.h"

class LineEditor : public ShapeEditor
{
public:
	LineEditor(HWND);
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
	void OnPaint();
};
