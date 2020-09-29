#pragma once

#include "framework.h"
#include "editor.h"

class ShapeObjectBuilder
{
private:
	Editor* editor;

public:
	ShapeObjectBuilder(void);
	~ShapeObjectBuilder();
	void StartPointEditor();
	void StartLineEditor();
	void StartRectEditor();
	void StartEllipseEditor();
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
};
