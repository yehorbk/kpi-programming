#include "point_editor.h"
#include "point_shape.h"

PointEditor::PointEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void PointEditor::OnLBup()
{
	this->isEdit = false;
	POINT pt = this->getMousePosition();
	this->x1 = this->x2 = pt.x;
	this->y1 = this->y2 = pt.y;
	PointShape* pointShape = new PointShape();
	(*pointShape).Set(this->x1, this->y1, this->x2, this->y2);
	this->appendShape(pointShape);
	this->redrawWindow();
}

void PointEditor::OnMouseMove()
{
	if (!isEdit)
	{
		return ;
	}
	POINT pt = this->getMousePosition();
	HDC hdc = this->openDrawer();
	PointShape().Set(pt.x, pt.y, pt.x, pt.y)->Show(hdc);
	this->closeDrawer(hdc);
}
