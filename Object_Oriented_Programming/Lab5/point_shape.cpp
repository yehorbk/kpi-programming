#include "point_shape.h"

void PointShape::Show(HDC hdc)
{
	SetPixel(hdc, this->x1, this->y1, RGB(0, 0, 0));
}

const char* PointShape::getName()
{
	return "Пiксель";
}
