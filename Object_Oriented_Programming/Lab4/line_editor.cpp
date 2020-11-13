#include "line_editor.h"
#include "line_shape.h"

LineEditor::LineEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void LineEditor::OnLBup()
{
	this->isEdit = false;
	POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
	LineShape* lineShape = new LineShape();
	(*lineShape).Set(this->x1, this->y1, this->x2, this->y2);
	this->appendShape(lineShape);
	this->redrawWindow();
}

void LineEditor::OnMouseMove()
{
	if (!this->isEdit)
	{
		return ;
	}
	POINT pt = this->getMousePosition();
	HDC hdc = this->openDrawer();
	HPEN oldPen = this->updatePen(hdc, RGB(0, 0, 255));
	SetROP2(hdc, R2_NOTXORPEN);
	LineShape().Set(this->x1, this->y1, this->x2, this->y2)->Show(hdc);
	this->x2 = pt.x;
	this->y2 = pt.y;
	LineShape().Set(this->x1, this->y1, this->x2, this->y2)->Show(hdc);
	DeleteObject(this->updatePen(hdc, oldPen));
	this->closeDrawer(hdc);
}
