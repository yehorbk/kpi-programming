#include "ellipse_shape.h"

void EllipseShape::Show(HDC hdc)
{
	Ellipse(hdc, this->x1, this->y1, this->x2, this->y2);
}
