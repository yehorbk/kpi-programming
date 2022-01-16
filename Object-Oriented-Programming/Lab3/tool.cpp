#include "tool.h"

Tool::Tool(LPCSTR _title, int _menuItemId, int _toolbarItemId)
{
	this->title = _title;
	this->menuItemId = _menuItemId;
	this->toolbarItemId = _toolbarItemId;
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

const Tool Tool::POINT = Tool("����� ����� �i����i�", 1001, 6001);
const Tool Tool::LINE = Tool("����� ����� �i�i�", 1002, 6002);
const Tool Tool::RECT = Tool("����� ����� �����������i�", 1003, 6003);
const Tool Tool::ELLIPSE = Tool("����� ����� ��i��i�", 1004, 6004);
