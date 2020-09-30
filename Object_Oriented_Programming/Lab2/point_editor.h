#pragma once

#include "shape_editor.h"

class PointEditor : public ShapeEditor
{
private:
	HDC hdc;

public:
	PointEditor(HWND);
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
	void OnPaint();
};
