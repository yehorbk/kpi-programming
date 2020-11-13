#pragma once

#include "framework.h"
#include "tool.h"
#include "shape.h"
#include "shape_editor.h"

class MainEditor 
{
private:
	HWND hWnd;
	ShapeEditor* shapeEditor;
	bool isEditorEnabled;
	void setUpEditor(ShapeEditor* _shapeEditor);

public:
	MainEditor();
	~MainEditor();
	void setHwnd(HWND);
	void Start(Tool tool);
	void enableEditor();
	void disableEditor();
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
	void OnPaint();
	void undo();
};
