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
	PointEditor* pointEditor = new PointEditor(this->hWnd);
	this->setUpEditor(pointEditor);
}

void ShapeObjectBuilder::StartLineEditor()
{
	LineEditor* lineEditor = new LineEditor(this->hWnd);
	this->setUpEditor(lineEditor);
}

void ShapeObjectBuilder::StartRectEditor()
{
	RectEditor* rectEditor = new RectEditor(this->hWnd);
	this->setUpEditor(rectEditor);
}

void ShapeObjectBuilder::StartEllipseEditor()
{
	EllipseEditor* ellipseEditor = new EllipseEditor(this->hWnd);
	this->setUpEditor(ellipseEditor);
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

void ShapeObjectBuilder::setUpEditor(ShapeEditor* _shapeEditor)
{
	if (this->shapeEditor)
	{
		_shapeEditor->init(this->shapeEditor->getShapes(),
			this->shapeEditor->getCounter());
	}
	this->shapeEditor = _shapeEditor;
}
