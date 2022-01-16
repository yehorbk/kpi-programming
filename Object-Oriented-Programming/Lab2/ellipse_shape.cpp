#include "ellipse_shape.h"

void EllipseShape::Show(HDC hdc)
{
	Arc(hdc, this->x1, this->y1, this->x2, this->y2, 0, 0, 0, 0);
}
