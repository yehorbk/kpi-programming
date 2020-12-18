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
	MainEditor()
	{
		this->hWnd = NULL;
		this->shapeEditor = NULL;
		this->isEditorEnabled = FALSE;
	};
	MainEditor(const MainEditor&);
	MainEditor& operator=(MainEditor&);
	void setUpEditor(ShapeEditor* _shapeEditor);

public:
	~MainEditor();
	static MainEditor& getInstance()
	{
		static MainEditor instance;
		return instance;
	};
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
