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

ShapeEditor* Tool::getEditor(HWND hWnd)
{
	return this->factory(hWnd);
}

const Tool Tool::POINT = Tool("–ежим вводу пiкселiв", 1001, 6001,
	[](HWND hWnd) -> ShapeEditor* { return new PointEditor(hWnd); });
const Tool Tool::LINE = Tool("–ежим вводу лiнiй", 1002, 6002,
	[](HWND hWnd) -> ShapeEditor* { return new LineEditor(hWnd); });
const Tool Tool::RECT = Tool("–ежим вводу пр€мокутникiв", 1003, 6003,
	[](HWND hWnd) -> ShapeEditor* { return new RectEditor(hWnd); });
const Tool Tool::ELLIPSE = Tool("–ежим вводу елiпсiв", 1004, 6004,
	[](HWND hWnd) -> ShapeEditor* { return new EllipseEditor(hWnd); });
const Tool Tool::OLINEO = Tool("–ежим вводу лiнiй з кружочками на кiнц€х", 1005, 6005,
	[](HWND hWnd) -> ShapeEditor* { return new EllipseEditor(hWnd); });
const Tool Tool::CUBE = Tool("–ежим вводу кубiв", 1006, 6006,
	[](HWND hWnd) -> ShapeEditor* { return new EllipseEditor(hWnd); });
