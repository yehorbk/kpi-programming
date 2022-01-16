#include "shape.h"

#include <string>
#include <typeinfo>

Shape* Shape::Set(short _x1, short _y1, short _x2, short _y2)
{
	this->x1 = _x1;
	this->y1 = _y1;
	this->x2 = _x2;
	this->y2 = _y2;
	return this;
}

const char* Shape::serialize()
{
	std::string result =
		std::string(typeid(*this).name()) + "\t" +
		std::to_string(this->x1) + "\t" +
		std::to_string(this->y1) + "\t" +
		std::to_string(this->x2) + "\t" +
		std::to_string(this->y2);
	char* ptr = new char[result.size() + 1];
	strcpy_s(ptr, result.size() + 1, result.c_str());
	return ptr;
}

const char* Shape::getParamContent()
{
	std::string result =
		"i�'�=" + std::string(this->getName()) + ", " +
		"x1=" + std::to_string(this->x1) + ", " +
		"y1=" + std::to_string(this->y1) + ", " +
		"x2=" + std::to_string(this->x2) + ", " +
		"y2=" + std::to_string(this->y2);
	char* ptr = new char[result.size() + 1];
	strcpy_s(ptr, result.size() + 1, result.c_str());
	return ptr;
}
