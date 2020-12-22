#pragma once

#include "shape.h"

class RectShape : public Shape
{
public:
	const char* getName();
	void Show(HDC hdc);
};
