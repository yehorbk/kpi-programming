#pragma once

#include "shape.h"

class LineShape : public Shape
{
public:
	void Show(HDC hdc);
	const char* getName();
};
