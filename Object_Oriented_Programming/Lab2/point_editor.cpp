#include "point_editor.h"
#include "point_shape.h"

PointEditor::PointEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void PointEditor::OnLBdown()
{
	this->hdc = this->openDrawer();
}

void PointEditor::OnLBup()
{
	this->closeDrawer(this->hdc);
}

void PointEditor::OnMouseMove()
{
	PointShape pointShape = PointShape();
	POINT pt = this->getMousePosition();
	pointShape.Set(pt.x, pt.y, pt.x, pt.y);
	pointShape.Show(hdc);
}
