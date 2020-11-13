#include "cube_shape.h"

void CubeShape::Show(HDC hdc)
{
	int differenceX = (*this).Shape::x2 - (*this).Shape::x1;
	int differenceY = (*this).Shape::x2 - (*this).Shape::x1;
	Rectangle(hdc, (*this).Shape::x1, (*this).Shape::y1, (*this).Shape::x2 + differenceX, (*this).Shape::y2 - differenceY);
	MoveToEx(hdc, (*this).Shape::x1, (*this).Shape::y1, NULL);
	LineTo(hdc, (*this).Shape::x1 - differenceX, (*this).Shape::y1 + differenceY);
	MoveToEx(hdc, (*this).Shape::x1, (*this).Shape::y2 - differenceY, NULL);
	LineTo(hdc, (*this).Shape::x1 - differenceX, (*this).Shape::y2);
	MoveToEx(hdc, (*this).Shape::x1 - differenceX, (*this).Shape::y1 + differenceY, NULL);
	LineTo(hdc, (*this).Shape::x1 - differenceX, (*this).Shape::y2);
	MoveToEx(hdc, (*this).Shape::x2 + differenceX, (*this).Shape::y1, NULL);
	LineTo(hdc, (*this).Shape::x2, (*this).Shape::y1 + differenceY);
	MoveToEx(hdc, (*this).Shape::x2 + differenceX, (*this).Shape::y2 - differenceY, NULL);
	LineTo(hdc, (*this).Shape::x2, (*this).Shape::y2);
	MoveToEx(hdc, (*this).Shape::x2, (*this).Shape::y1 + differenceY, NULL);
	LineTo(hdc, (*this).Shape::x2, (*this).Shape::y2);
	MoveToEx(hdc, (*this).Shape::x1 - differenceX, (*this).Shape::y1 + differenceY, NULL);
	LineTo(hdc, (*this).Shape::x2, (*this).Shape::y1 + differenceY);
	MoveToEx(hdc, (*this).Shape::x1 - differenceX, (*this).Shape::y2, NULL);
	LineTo(hdc, (*this).Shape::x2, (*this).Shape::y2);
}
