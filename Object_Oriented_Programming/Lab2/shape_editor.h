#pragma once

#include "framework.h"
#include "editor.h"
#include "shape.h"

class ShapeEditor : public Editor
{
private:
	Shape* pcshape[105];
	int counter;
	int getShapesSize();

protected:
	HWND hWnd;
	short x1;
	short y1;
	short x2;
	short y2;
	bool isEdit;
	POINT getMousePosition();
	HDC openDrawer();
	void closeDrawer(HDC hdc);
	HPEN updatePen(HDC hdc, COLORREF color);
	HPEN updatePen(HDC hdc, HPEN hpen);
	void redrawWindow();

public:
	ShapeEditor(HWND _hWnd);
	void OnLBdown();
	void OnPaint();
	void init(Shape** _pcshape, int _counter);
	bool appendShape(Shape* shape);
	bool removeLastShape();
	Shape** getShapes();
	int getCounter();
};
