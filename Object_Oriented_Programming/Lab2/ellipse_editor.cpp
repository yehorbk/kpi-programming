#include "ellipse_editor.h"
#include "ellipse_shape.h"

EllipseEditor::EllipseEditor(HWND hWnd) : ShapeEditor(hWnd) {}

void EllipseEditor::OnLBdown()
{
	POINT pt = this->getMousePosition();
	this->x1 = pt.x;
	this->y1 = pt.y;

	
}

void EllipseEditor::OnLBup()
{
	HDC hdc = this->openDrawer();
	POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
	EllipseShape ellipseShape = EllipseShape();
	ellipseShape.Set(this->x1, this->y1, this->x2, this->y2);
	ellipseShape.Show(hdc);
	this->closeDrawer(hdc);
}

void EllipseEditor::OnMouseMove()
{
	
}

void EllipseEditor::OnPaint()
{

}
