#include "tool.h"

Tool::Tool(LPCSTR _title, int _menuItemId)
{
	this->title = _title;
	this->menuItemId = _menuItemId;
}

LPCSTR Tool::getTitle()
{
	return this->title;
}

int Tool::getMenuItemId()
{
	return this->menuItemId;
}

const Tool Tool::POINT = Tool("Режим вводу пiкселiв", 1001);
const Tool Tool::LINE = Tool("Режим вводу лiнiй", 1002);
const Tool Tool::RECT = Tool("Режим вводу прямокутникiв", 1003);
const Tool Tool::ELLIPSE = Tool("Режим вводу елiпсiв", 1004);
