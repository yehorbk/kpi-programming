#pragma once

#include "line_shape.h"
#include "ellipse_shape.h"

class OLineOShape : public LineShape, public EllipseShape
{
public:
	const char* getName();
	void Show(HDC hdc);
};
