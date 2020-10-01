#include "rect_editor.h"
#include "rect_shape.h"

RectEditor::RectEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void RectEditor::OnLBdown()
{
	this->isEdit = true;
	POINT pt = this->getMousePosition();
	this->x1 = pt.x;
	this->y1 = pt.y;
	this->x2 = -1;
	this->y2 = -1;
}

void RectEditor::OnLBup()
{
	this->isEdit = false;
	POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
	RectShape* rectShape = new RectShape();
	(*rectShape).Set(this->x1, this->y1, this->x2, this->y2);
	this->appendShape(rectShape);
	this->redrawWindow();
}

void RectEditor::OnMouseMove()
{
	
}
