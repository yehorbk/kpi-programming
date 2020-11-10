#pragma once

#include "framework.h"
#include "shape.h"
#include "shape_editor.h"

class MainEditor 
{
private:
	HWND hWnd;
	Shape** pshape;
	ShapeEditor* shapeEditor;
	bool isEditorEnabled;
	void setUpEditor(ShapeEditor* _shapeEditor);

public:
	MainEditor(HWND);
	~MainEditor();
	void Start(Shape*);
	void enableEditor();
	void disableEditor();
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
	void OnPaint();
	void undo();
};
