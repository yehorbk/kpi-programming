#include "main_editor.h"
#include "stdio.h"

MainEditor::~MainEditor()
{
	if (this->shapeEditor)
	{
		Shape** shapes = this->shapeEditor->getShapes();
		for (int i = 0; i < this->shapeEditor->getCounter(); i++)
		{
			delete shapes[i];
		}
		delete shapes;
	}
	delete this->shapeEditor;
}

void MainEditor::setHwnd(HWND _hWnd)
{
	this->hWnd = _hWnd;
}

void MainEditor::Start(Tool tool)
{
	if (this->hWnd)
	{
		ShapeEditor* shapeEditor = tool.getEditor(this->hWnd);
		this->setUpEditor(shapeEditor);
	}
}

void MainEditor::enableEditor()
{
	this->isEditorEnabled = TRUE;
}

void MainEditor::disableEditor()
{
	this->isEditorEnabled = FALSE;
}

void MainEditor::OnLBdown()
{
	if (this->shapeEditor && this->isEditorEnabled)
	{
		this->shapeEditor->OnLBdown();
	}
}

void MainEditor::OnLBup()
{
	if (this->shapeEditor && this->isEditorEnabled)
	{
		this->shapeEditor->OnLBup();
	}
}

void MainEditor::OnMouseMove()
{
	if (this->shapeEditor && this->isEditorEnabled)
	{
		this->shapeEditor->OnMouseMove();
	}
}

void MainEditor::OnPaint()
{
	if (this->shapeEditor)
	{
		this->shapeEditor->OnPaint();
	}
}

void MainEditor::exportProject()
{
	if (this->shapeEditor)
	{
		Shape** shapes = this->shapeEditor->getShapes(); // TODO
		FILE* fp;
		fopen_s(&fp, this->projectFileName, "w+");
		if (fp != NULL)
		{
			fprintf(fp, "name=Коло, x1=10, x2=20, y1=30, y2=40");
			fclose(fp);
		}
	}
}

void MainEditor::importProject()
{

}

void MainEditor::undo()
{
	if (this->shapeEditor)
	{
		this->shapeEditor->removeLastShape();
	}
}

void MainEditor::clearAll()
{
	if (this->shapeEditor)
	{
		Shape** shapes = this->shapeEditor->getShapes();
		for (int i = 0; i < this->shapeEditor->getCounter(); i++)
		{
			delete shapes[i];
		}
		this->shapeEditor->init(shapes, 0);
	}
}

const char* MainEditor::getLastSerialized()
{
	if (this->shapeEditor && this->isEditorEnabled)
	{
		Shape* shape = this->shapeEditor->getShapes()[this->shapeEditor->getCounter() - 1];
		return shape->serialize();
	}
	return NULL;
}

void MainEditor::setUpEditor(ShapeEditor* _shapeEditor)
{
	if (this->shapeEditor)
	{
		_shapeEditor->init(this->shapeEditor->getShapes(),
			this->shapeEditor->getCounter());
		delete this->shapeEditor;
	}
	this->shapeEditor = _shapeEditor;
	this->enableEditor();
}
