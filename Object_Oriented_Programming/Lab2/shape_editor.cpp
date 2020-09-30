#include "shape_editor.h"

ShapeEditor::ShapeEditor(HWND hWnd)
{
	this->hWnd = hWnd;
}

HDC ShapeEditor::openDrawer()
{
	return GetDC(this->hWnd);
}

void ShapeEditor::closeDrawer(HDC hdc)
{
	ReleaseDC(this->hWnd, hdc);
}

POINT ShapeEditor::getMousePosition()
{
	POINT result;
	GetCursorPos(&result);
	ScreenToClient(this->hWnd, &result);
	return result;
}
