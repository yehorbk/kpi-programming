#pragma once

#include "shape.h"

class PointShape : public Shape
{
public:
	void Show(HDC hdc);
	const char* getName();
};
