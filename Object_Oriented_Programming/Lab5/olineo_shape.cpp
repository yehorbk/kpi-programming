#include "olineo_shape.h"

void OLineOShape::Show(HDC hdc)
{
	short offset = 10;
	MoveToEx(hdc, (*this).Shape::x1, (*this).Shape::y1, NULL);
	LineTo(hdc, (*this).Shape::x2, (*this).Shape::y2);
	Ellipse(hdc, (*this).Shape::x1 - offset, (*this).Shape::y1 - offset, (*this).Shape::x1 + offset, (*this).Shape::y1 + offset);
	Ellipse(hdc, (*this).Shape::x2 - offset, (*this).Shape::y2 - offset, (*this).Shape::x2 + offset, (*this).Shape::y2 + offset);
}

const char* OLineOShape::getName()
{
	return "Лiнiя з кружочками на кiнцях";
}

