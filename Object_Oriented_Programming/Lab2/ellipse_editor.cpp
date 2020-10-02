#include "ellipse_editor.h"
#include "ellipse_shape.h"

EllipseEditor::EllipseEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void EllipseEditor::OnLBup()
{
	this->isEdit = false;
	POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
	EllipseShape* ellipseShape = new EllipseShape();
	(*ellipseShape).Set(this->x1, this->y1, this->x2, this->y2);
	this->appendShape(ellipseShape);
	this->redrawWindow();
}

void EllipseEditor::OnMouseMove()
{
	if (!this->isEdit)
	{
		return ;
	}
	POINT pt = this->getMousePosition();
	HDC hdc = this->openDrawer();
	HPEN oldPen = this->updatePen(hdc, RGB(255, 0, 0));
	SetROP2(hdc, R2_NOTXORPEN);
	EllipseShape().Set(this->x1, this->y1, this->x2, this->y2)->Show(hdc);
	this->x2 = pt.x;
	this->y2 = pt.y;
	EllipseShape().Set(this->x1, this->y1, this->x2, this->y2)->Show(hdc);
	DeleteObject(this->updatePen(hdc, oldPen));
	this->closeDrawer(hdc);
}
