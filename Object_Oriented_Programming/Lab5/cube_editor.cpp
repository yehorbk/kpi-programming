#include "cube_editor.h"
#include "cube_shape.h"

CubeEditor::CubeEditor(HWND _hWnd) : ShapeEditor(_hWnd) {}

void CubeEditor::OnLBup()
{
	this->isEdit = false;
	POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
	CubeShape* cubeShape = new CubeShape();
	(*cubeShape).Shape::Set(this->x1, this->y1, this->x2, this->y2);
	this->appendShape(dynamic_cast<RectShape*>(cubeShape));
	this->redrawWindow();
}

void CubeEditor::OnMouseMove()
{
	if (!this->isEdit)
	{
		return;
	}
	POINT pt = this->getMousePosition();
	HDC hdc = this->openDrawer();
	HPEN oldPen = this->updatePen(hdc, RGB(0, 0, 255));
	SetROP2(hdc, R2_NOTXORPEN);
	CubeShape cubeShape = CubeShape();
	cubeShape.Shape::Set(this->x1, this->y1, this->x2, this->y2);
	cubeShape.Show(hdc);
	this->x2 = pt.x;
	this->y2 = pt.y;
	cubeShape = CubeShape();
	cubeShape.Shape::Set(this->x1, this->y1, this->x2, this->y2);
	cubeShape.Show(hdc);
	DeleteObject(this->updatePen(hdc, oldPen));
	this->closeDrawer(hdc);
}
