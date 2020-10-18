#include "rect_editor.h"
#include "rect_shape.h"

RectEditor::RectEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void RectEditor::OnLBup()
{
	this->isEdit = false;
	POINT pt = this->getMousePosition();
	this->x2 = 2 * this->x1 - pt.x;
	this->y2 = 2 * this->y1 - pt.y;
	this->x1 = pt.x;
	this->y1 = pt.y;
	RectShape* rectShape = new RectShape();
	(*rectShape).Set(this->x1, this->y1, this->x2, this->y2);
	this->appendShape(rectShape);
	this->redrawWindow();
}

void RectEditor::OnMouseMove()
{
	if (!this->isEdit)
	{
		return;
	}
	POINT pt = this->getMousePosition();
	HDC hdc = this->openDrawer();
	HPEN oldPen = this->updatePen(hdc, RGB(0, 0, 255));
	SetROP2(hdc, R2_NOTXORPEN);
	int x = 2 * this->x1 - this->x2;
	int y = 2 * this->y1 - this->y2;
	RectShape().Set(this->x2, this->y2, x, y)->Show(hdc);
	this->x2 = pt.x;
	this->y2 = pt.y;
	x = 2 * this->x1 - this->x2;
	y = 2 * this->y1 - this->y2;
	RectShape().Set(this->x2, this->y2, x, y)->Show(hdc);
	DeleteObject(this->updatePen(hdc, oldPen));
	this->closeDrawer(hdc);
}
