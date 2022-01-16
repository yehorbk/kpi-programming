#pragma once

#include "framework.h"

class Editor
{
public:
	virtual void OnLBdown() = 0;
	virtual void OnLBup() = 0;
	virtual void OnMouseMove() = 0;
	virtual void OnPaint() = 0;
};
