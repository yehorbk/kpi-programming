#pragma once

#include "shape_editor.h"

class PointEditor : public ShapeEditor
{
private:
	HDC hdc;

public:
	PointEditor(HWND _hWnd);
	void OnLBup();
	void OnMouseMove();
};
