#pragma once

#include "line_shape.h"
#include "ellipse_shape.h"

class OLineOShape : public LineShape, public EllipseShape
{
public:
	void Show(HDC hdc);
	const char* getName();
};
