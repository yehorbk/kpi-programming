#pragma once

#include "shape.h"

class PointShape : public Shape
{
public:
	const char* getName();
	void Show(HDC hdc);
};
