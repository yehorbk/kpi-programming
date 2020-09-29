#pragma once

#include "editor.h"

class PointEditor : public Editor
{
public:
	void OnLBdown(HWND hWnd);
	void OnLBup(HWND hWnd);
	void OnMouseMove(HWND hWnd);
	void OnPaint(HWND hWnd);
};
