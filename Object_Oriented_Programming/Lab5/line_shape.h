#pragma once

#include "shape.h"

class LineShape : public Shape
{
public:
	const char* getName();
	void Show(HDC hdc);
};
