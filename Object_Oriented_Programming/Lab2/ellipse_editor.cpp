#include "ellipse_editor.h"
#include "ellipse_shape.h"

EllipseEditor::EllipseEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void EllipseEditor::OnLBdown()
{
	POINT pt = this->getMousePosition();
	this->x1 = pt.x;
	this->y1 = pt.y;
}

void EllipseEditor::OnLBup()
{
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
	
}
