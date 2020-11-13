#include "line_shape.h"

void LineShape::Show(HDC hdc)
{
	MoveToEx(hdc, this->x1, this->y1, NULL);
	LineTo(hdc, this->x2, this->y2);
}
