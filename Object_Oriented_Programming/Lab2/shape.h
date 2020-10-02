#pragma once

#include "framework.h"

class Shape
{
protected:
	short x1;
	short y1;
	short x2;
	short y2;

public:
	virtual void Show(HDC) = 0;
	Shape* Set(short _x1, short _y1, short _x2, short _y2);
};
