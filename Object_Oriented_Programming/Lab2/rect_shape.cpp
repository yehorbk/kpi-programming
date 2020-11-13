#include "rect_shape.h"

void RectShape::Show(HDC hdc)
{
	Rectangle(hdc, this->x1, this->y1, this->x2, this->y2);
}
