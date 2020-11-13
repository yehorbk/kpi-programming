#include "olineo_editor.h"
#include "olineo_shape.h"

OLineOEditor::OLineOEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void OLineOEditor::OnLBup()
{
	this->isEdit = false;
	POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
	OLineOShape* olineoShape = new OLineOShape();
	(*olineoShape).Shape::Set(this->x1, this->y1, this->x2, this->y2);
	this->appendShape(dynamic_cast<LineShape*>(olineoShape));
	this->redrawWindow();
}

void OLineOEditor::OnMouseMove()
{
	if (!this->isEdit)
	{
		return;
	}
	POINT pt = this->getMousePosition();
	HDC hdc = this->openDrawer();
	HPEN oldPen = this->updatePen(hdc, RGB(0, 0, 255));
	SetROP2(hdc, R2_NOTXORPEN);
	OLineOShape olineoShape = OLineOShape();
	olineoShape.Shape::Set(this->x1, this->y1, this->x2, this->y2);
	olineoShape.Show(hdc);
	this->x2 = pt.x;
	this->y2 = pt.y;
	olineoShape = OLineOShape();
	olineoShape.Shape::Set(this->x1, this->y1, this->x2, this->y2);
	olineoShape.Show(hdc);
	DeleteObject(this->updatePen(hdc, oldPen));
	this->closeDrawer(hdc);
}
