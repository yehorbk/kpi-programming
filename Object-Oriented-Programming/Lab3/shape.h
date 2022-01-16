#pragma once

#include "framework.h"

class Shape
{
protected:
	short x1 = -1;
	short y1 = -1;
	short x2 = -1;
	short y2 = -1;

public:
	virtual void Show(HDC) = 0;
	Shape* Set(short _x1, short _y1, short _x2, short _y2);
};
