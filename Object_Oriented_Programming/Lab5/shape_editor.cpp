#include "shape_editor.h"

ShapeEditor::ShapeEditor(HWND _hWnd)
{
	this->pcshape = new Shape*[this->getShapesSize()];
	this->counter = 0;
	this->hWnd = _hWnd;
	this->x1 = this->x2 = this->y1 = this->y2 = -1;
	this->isEdit = false;
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

void ShapeEditor::OnLBup()
{
	POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
	this->isEdit = false;
}

void ShapeEditor::OnMouseMove()
{
	POINT pt = this->getMousePosition();
	this->x2 = pt.x;
	this->y2 = pt.y;
}

void ShapeEditor::OnPaint()
{
	HDC hdc = this->openDrawer();
	for (int i = 0; i < this->counter; i++)
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
	for (int i = 0; i < this->counter; i++)
	{
		this->pcshape[i] = _pcshape[i];
	}
	this->redrawWindow();
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
		delete this->pcshape[--this->counter];
		this->pcshape[this->counter] = NULL;
		this->redrawWindow();
		return true;
	}
	return false;
}

bool ShapeEditor::removeByIndex(int index)
{
	if (this->counter > 0 && index >= 0)
	{
		delete this->pcshape[index];
		for (int i = index; i < this->counter; i++)
		{
			pcshape[i] = pcshape[i + 1];
		}
		counter--;
		this->redrawWindow();
		return true;
	}
	return false;
}

Shape** ShapeEditor::getShapes()
{
	return this->pcshape;
}

int ShapeEditor::getCounter()
{
	return this->counter;
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
	HPEN newPen = CreatePen(PS_DOT, 1, color);
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

int ShapeEditor::getShapesSize()
{
	return 106;
}
