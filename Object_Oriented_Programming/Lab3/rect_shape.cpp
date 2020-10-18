#include "rect_shape.h"

void RectShape::Show(HDC hdc)
{
	HBRUSH hBrush;
	HBRUSH hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, this->x1, this->y1, this->x2, this->y2);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}
