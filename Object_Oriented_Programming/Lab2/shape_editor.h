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

public:
	ShapeEditor(HWND _hWnd);
	void OnPaint();
	void init(Shape** _pcshape, int _counter);
	bool appendShape(Shape* shape);
	bool removeLastShape();
	POINT getMousePosition();
	HDC openDrawer();
	void closeDrawer(HDC hdc);
	void redrawWindow();
	Shape** getShapes();
	int getCounter();
};
