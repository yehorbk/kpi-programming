#pragma once

#include "string.h"

#include "cube_shape.h"
#include "ellipse_shape.h"
#include "line_shape.h"
#include "olineo_shape.h"
#include "point_shape.h"
#include "rect_shape.h"

class ShapeSerializationAdapter
{
public:
	const char* serialize(Shape* shape);
	// Shape* deserialize(const char);
};
