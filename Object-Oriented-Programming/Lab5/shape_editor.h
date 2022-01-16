#pragma once

#include "framework.h"
#include "editor.h"
#include "shape.h"
#include "rect_shape.h"

class ShapeEditor : public Editor
{
private:
	Shape** pcshape;
	int counter;

protected:
	HWND hWnd;
	short x1;
	short y1;
	short x2;
	short y2;
	bool isEdit;
	POINT getMousePosition();
	int getShapesSize();
	HDC openDrawer();
	void closeDrawer(HDC hdc);
	HPEN updatePen(HDC hdc, COLORREF color);
	HPEN updatePen(HDC hdc, HPEN hpen);
	void redrawWindow();

public:
	ShapeEditor(HWND _hWnd);
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
	void OnPaint();
	void init(Shape** _pcshape, int _counter);
	bool selectShape(int index);
	bool appendShape(Shape* shape);
	bool removeByIndex(int index);
	bool removeLastShape();
	bool clearAllShapes();
	Shape** getShapes();
	int getCounter();
};
