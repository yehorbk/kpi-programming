#include "shape_editor.h"

ShapeEditor::ShapeEditor(HWND _hWnd)
{
	this->hWnd = _hWnd;
	this->counter = 0;
	this->isEdit = false;
}

int ShapeEditor::getShapesSize()
{
	return sizeof(this->pcshape) / sizeof(*this->pcshape);
}

void ShapeEditor::OnLBdown()
{
	POINT pt = this->getMousePosition();
	this->x1 = pt.x;
	this->y1 = pt.y;
	this->x2 = pt.x;
	this->y2 = pt.y;
	this->isEdit = true;
}

void ShapeEditor::OnPaint()
{
	HDC hdc = this->openDrawer();
	for (int i = 0; i < this->getShapesSize(); i++)
	{
		if (this->pcshape[i])
		{
			this->pcshape[i]->Show(hdc);
		}
	}
	this->closeDrawer(hdc);
}

void ShapeEditor::init(Shape** _pcshape, int _counter)
{
	this->counter = _counter;
	for (int i = 0; i < this->getShapesSize(); i++)
	{
		this->pcshape[i] = _pcshape[i];
	}
}

bool ShapeEditor::appendShape(Shape* shape)
{
	if (this->counter < this->getShapesSize())
	{
		this->pcshape[this->counter++] = shape;
		return true;
	}
	return false;
}

bool ShapeEditor::removeLastShape()
{
	if (this->counter > 0)
	{
		this->pcshape[--this->counter] = NULL;
		this->redrawWindow();
		return true;
	}
	return false;
}

POINT ShapeEditor::getMousePosition()
{
	POINT result;
	GetCursorPos(&result);
	ScreenToClient(this->hWnd, &result);
	return result;
}

HDC ShapeEditor::openDrawer()
{
	return GetDC(this->hWnd);
}

void ShapeEditor::closeDrawer(HDC hdc)
{
	ReleaseDC(this->hWnd, hdc);
}

HPEN ShapeEditor::updatePen(HDC hdc, COLORREF color)
{
	HPEN newPen = CreatePen(PS_SOLID, 1, color);
	return (HPEN)SelectObject(hdc, newPen);
}

HPEN ShapeEditor::updatePen(HDC hdc, HPEN hpen)
{
	return (HPEN)SelectObject(hdc, hpen);
}

void ShapeEditor::redrawWindow()
{
	InvalidateRect(this->hWnd, NULL, TRUE);
}

Shape** ShapeEditor::getShapes()
{
	return this->pcshape;
}

int ShapeEditor::getCounter()
{
	return this->counter;
}
