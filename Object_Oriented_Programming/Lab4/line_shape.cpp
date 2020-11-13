#include "line_shape.h"

void LineShape::Show(HDC hdc)
{
	MoveToEx(hdc, (*this).Shape::x1, (*this).Shape::y1, NULL);
	LineTo(hdc, (*this).Shape::x2, (*this).Shape::y2);
}
