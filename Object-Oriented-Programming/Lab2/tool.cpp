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

const Tool Tool::POINT = Tool("����� ����� �i����i�", 1001);
const Tool Tool::LINE = Tool("����� ����� �i�i�", 1002);
const Tool Tool::RECT = Tool("����� ����� �����������i�", 1003);
const Tool Tool::ELLIPSE = Tool("����� ����� ��i��i�", 1004);
