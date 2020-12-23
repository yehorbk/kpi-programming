#include "main_editor.h"
#include "stdio.h"

#define EXP_OK 1
#define EXP_NO_FIGURES 0
#define EXP_CANNOT_OPEN_FILE -1

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
		this->exportOne();
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

void MainEditor::exportOne()
{
	if (this->shapeEditor)
	{
		Shape* shape = this->shapeEditor->getShapes()[this->shapeEditor->getCounter() - 1];
		FILE* fp;
		fopen_s(&fp, this->projectFileName, "a+");
		if (fp != NULL)
		{
			fprintf(fp, "%s\n", shape->serialize());
			fclose(fp);
		}
	}
}

void MainEditor::exportProject()
{
	if (this->shapeEditor)
	{
		Shape** shapes = this->shapeEditor->getShapes();
		int count = this->shapeEditor->getCounter();
		if (count == 0)
		{
			this->showExportMessage(EXP_NO_FIGURES);
			return;
		}
		FILE* fp;
		fopen_s(&fp, this->projectFileName, "w+");
		if (fp != NULL)
		{
			for (int i = 0; i < count; i++)
			{
				fprintf(fp, "%s\n", shapes[i]->serialize());
			}
			fclose(fp);
			this->showExportMessage(EXP_OK);
			return;
		}
		this->showExportMessage(EXP_CANNOT_OPEN_FILE);
	}
	else
	{
		this->showExportMessage(EXP_NO_FIGURES);
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

void MainEditor::selectObject(int index)
{
	if (this->shapeEditor)
	{
		this->shapeEditor->selectShape(index);
	}
}

void MainEditor::deleteObject(int index)
{
	if (this->shapeEditor)
	{
		this->shapeEditor->removeByIndex(index);
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

void MainEditor::showExportMessage(int status)
{
	const char* message;
	switch (status)
	{
	default:
	case EXP_OK:
		message = "Данi успiшно експортованi в файл editor-objects.txt";
		break;
	case EXP_NO_FIGURES:
		message = "Помилка експортування: на полотнi не знайдено жодної фiгури!";
		break;
	case EXP_CANNOT_OPEN_FILE:
		message = "Помилка експортування: не вдається вiдкрити файл для запису даних!";
		break;
	}
	MessageBoxA(this->hWnd, message, "Експорт", MB_OK);
}
