#pragma once

#include "shape_editor.h"

class RectEditor : public ShapeEditor
{
public:
	RectEditor(HWND _hWnd);
	void OnLBup();
	void OnMouseMove();
};
