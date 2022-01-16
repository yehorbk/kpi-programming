#pragma once

#include "shape_editor.h"

class OLineOEditor : public ShapeEditor
{
public:
	OLineOEditor(HWND _hWnd);
	void OnLBup();
	void OnMouseMove();
};
