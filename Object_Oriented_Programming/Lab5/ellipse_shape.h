#pragma once

#include "shape.h"

class EllipseShape : public Shape
{
public:
	const char* getName();
	void Show(HDC hdc);
};
