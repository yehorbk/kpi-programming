#pragma once

#include <map>
#include <string>

#include "cube_shape.h"
#include "ellipse_shape.h"
#include "line_shape.h"
#include "olineo_shape.h"
#include "point_shape.h"
#include "rect_shape.h"

using ShapeFactory = Shape* (*)();

class ShapeSerializationAdapter
{
private:
	std::map<std::string, ShapeFactory> shapeTypes;
public:
	ShapeSerializationAdapter();
	Shape* deserialize(const char* data);
};
