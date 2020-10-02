#pragma once

#include "shape_editor.h"

class PointEditor : public ShapeEditor
{
public:
	PointEditor(HWND _hWnd);
	void OnLBup();
	void OnMouseMove();
};
