#include "shape_object_builder.h"
#include "point_editor.h"
#include "line_editor.h"
#include "rect_editor.h"
#include "ellipse_editor.h"

ShapeObjectBuilder::ShapeObjectBuilder(HWND _hWnd) {
	this->hWnd = _hWnd;
	this->shapeEditor = NULL;
}

ShapeObjectBuilder::~ShapeObjectBuilder() {
	delete(this->hWnd);
	delete(this->shapeEditor);
}

void ShapeObjectBuilder::StartPointEditor()
{
	this->shapeEditor = new PointEditor(this->hWnd);
}

void ShapeObjectBuilder::StartLineEditor()
{
	this->shapeEditor = new LineEditor(this->hWnd);
}

void ShapeObjectBuilder::StartRectEditor()
{
	this->shapeEditor = new RectEditor(this->hWnd);
}

void ShapeObjectBuilder::StartEllipseEditor()
{
	this->shapeEditor = new EllipseEditor(this->hWnd);
}

void ShapeObjectBuilder::OnLBdown()
{
	if (this->shapeEditor)
	{
		this->shapeEditor->OnLBdown();
	}
}

void ShapeObjectBuilder::OnLBup()
{
	if (this->shapeEditor)
	{
		this->shapeEditor->OnLBup();
	}
}

void ShapeObjectBuilder::OnMouseMove()
{
	if (this->shapeEditor)
	{
		this->shapeEditor->OnMouseMove();
	}
}

void ShapeObjectBuilder::OnPaint()
{
	if (this->shapeEditor)
	{
		this->shapeEditor->OnPaint();
	}
}
