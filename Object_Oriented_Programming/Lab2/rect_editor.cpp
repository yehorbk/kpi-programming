#include "rect_editor.h"
#include "rect_shape.h"

RectEditor::RectEditor(HWND hWnd) : ShapeEditor(hWnd) {}

void RectEditor::OnLBdown()
{
	POINT pt = this->getMousePosition();
	this->x1 = pt.x;
	this->y1 = pt.y;
}

void RectEditor::OnLBup()
{
	HDC hdc = this->openDrawer();
	POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
	RectShape rectShape = RectShape();
	rectShape.Set(this->x1, this->y1, this->x2, this->y2);
	rectShape.Show(hdc);
	this->closeDrawer(hdc);
}

void RectEditor::OnMouseMove()
{
	
}

void RectEditor::OnPaint()
{

}
