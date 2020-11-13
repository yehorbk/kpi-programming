#pragma once

#include "framework.h"
#include "shape_editor.h"

class ShapeObjectBuilder
{
private:
	HWND hWnd;
	ShapeEditor* shapeEditor;
	bool isEditorEnabled;
	void setUpEditor(ShapeEditor* _shapeEditor);

public:
	ShapeObjectBuilder(HWND);
	~ShapeObjectBuilder();
	void StartPointEditor();
	void StartLineEditor();
	void StartRectEditor();
	void StartEllipseEditor();
	void enableEditor();
	void disableEditor();
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
	void OnPaint();
	void undo();
};
