#include "tool.h"

#include "shape_editor.h"
#include "point_editor.h"
#include "line_editor.h"
#include "rect_editor.h"
#include "ellipse_editor.h"

Tool::Tool(LPCSTR _title, int _menuItemId, int _toolbarItemId, Factory _factory)
{
	this->title = _title;
	this->menuItemId = _menuItemId;
	this->toolbarItemId = _toolbarItemId;
	this->factory = _factory;
}

LPCSTR Tool::getTitle()
{
	return this->title;
}

int Tool::getMenuItemId()
{
	return this->menuItemId;
}

int Tool::getToolbarItemId()
{
	return this->toolbarItemId;
}

const Tool Tool::POINT = Tool("Режим вводу пiкселiв", 1001, 6001,
	[](HWND hWnd) -> ShapeEditor { return PointEditor(hWnd); });
const Tool Tool::LINE = Tool("Режим вводу лiнiй", 1002, 6002,
	[](HWND hWnd) -> ShapeEditor { return LineEditor(hWnd); });
const Tool Tool::RECT = Tool("Режим вводу прямокутникiв", 1003, 6003,
	[](HWND hWnd) -> ShapeEditor { return RectEditor(hWnd); });
const Tool Tool::ELLIPSE = Tool("Режим вводу елiпсiв", 1004, 6004,
	[](HWND hWnd) -> ShapeEditor { return EllipseEditor(hWnd); });
