#include "shape_object_builder.h"

ShapeObjectBuilder::ShapeObjectBuilder() {}

ShapeObjectBuilder::~ShapeObjectBuilder() {}

void ShapeObjectBuilder::StartPointEditor()
{
	//this->shapeEditor = new PointEditor();
}

void ShapeObjectBuilder::StartLineEditor()
{
	//this->shapeEditor = new LineEditor();
}

void ShapeObjectBuilder::StartRectEditor()
{
	//this->shapeEditor = new RectEditor();
}

void ShapeObjectBuilder::StartEllipseEditor()
{
	//this->shapeEditor = new EllipseEditor();
}

void ShapeObjectBuilder::OnLBdown(HWND hWnd)
{
	this->shapeEditor->OnLBdown(hWnd);
}

void ShapeObjectBuilder::OnLBup(HWND hWnd)
{
	this->shapeEditor->OnLBup(hWnd);
}

void ShapeObjectBuilder::OnMouseMove(HWND hWnd)
{
	this->shapeEditor->OnMouseMove(hWnd);
}

void ShapeObjectBuilder::OnPaint(HWND hWnd)
{
	this->shapeEditor->OnPaint(hWnd);
}
