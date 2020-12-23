#pragma once

#include "shape.h"

class EllipseShape : public Shape
{
public:
	void Show(HDC hdc);
	const char* getName();
};
