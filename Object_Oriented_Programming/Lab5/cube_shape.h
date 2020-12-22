#pragma once

#include "line_shape.h"
#include "rect_shape.h"

class CubeShape : public RectShape, public LineShape
{
public:
	const char* getName();
	void Show(HDC hdc);
};
