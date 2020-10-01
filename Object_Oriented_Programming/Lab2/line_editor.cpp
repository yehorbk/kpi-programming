#include "line_editor.h"
#include "line_shape.h"

LineEditor::LineEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void LineEditor::OnLBdown()
{
	POINT pt = this->getMousePosition();
	this->x1 = pt.x;
	this->y1 = pt.y;
}

void LineEditor::OnLBup()
{
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
	/*POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
	LineShape lineShape = LineShape();
	lineShape.Set(this->x1, this->y1, this->x2, this->y2);
	HDC hdc = this->openDrawer();
	lineShape.Show(hdc);
	this->closeDrawer(hdc);*/
}
