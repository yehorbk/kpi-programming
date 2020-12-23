#include "shape_serialization_adapter.h"

#include <string>
#include <typeinfo>

ShapeSerializationAdapter::ShapeSerializationAdapter()
{
	this->shapeTypes[typeid(CubeShape).name()] = []() -> Shape* { return dynamic_cast<RectShape*>(new CubeShape()); };
	this->shapeTypes[typeid(EllipseShape).name()] = []() -> Shape* { return new EllipseShape(); };
	this->shapeTypes[typeid(LineShape).name()] = []() -> Shape* { return new LineShape(); };
	this->shapeTypes[typeid(OLineOShape).name()] = []() -> Shape* { return dynamic_cast<LineShape*>(new OLineOShape()); };
	this->shapeTypes[typeid(PointShape).name()] = []() -> Shape* { return new PointShape(); };
	this->shapeTypes[typeid(RectShape).name()] = []() -> Shape* { return new RectShape(); };
}

Shape* ShapeSerializationAdapter::deserialize(const char* data)
{
	std::string stringData = std::string(data);
	std::string parsedData[5];
	for (int i = 0; i < sizeof(parsedData) / sizeof(*parsedData); i++)
	{
		parsedData[i] = stringData.substr
		(
			0,
			stringData.find("\t")
		);
		stringData = stringData.substr
		(
			stringData.find("\t") + std::string("\t").size(),
			stringData.size()
		);
	}
	auto iterator = this->shapeTypes.find(parsedData[0].c_str());
	if (iterator == this->shapeTypes.end())
	{
		return NULL;
	}
	ShapeFactory shapeFactory = iterator->second;
	Shape* result = shapeFactory();
	result->Set
	(
		std::stoi(parsedData[1]),
		std::stoi(parsedData[2]),
		std::stoi(parsedData[3]),
		std::stoi(parsedData[4])
	);
	return result;
}
