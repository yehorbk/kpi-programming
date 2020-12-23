#pragma once

#include "line_shape.h"
#include "rect_shape.h"

class CubeShape : public RectShape, public LineShape
{
public:
	void Show(HDC hdc);
	const char* getName();
};
