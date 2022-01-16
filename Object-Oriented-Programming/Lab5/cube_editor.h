#pragma once

#include "shape_editor.h"

class CubeEditor : public ShapeEditor
{
public:
	CubeEditor(HWND _hWnd);
	void OnLBup();
	void OnMouseMove();
};
