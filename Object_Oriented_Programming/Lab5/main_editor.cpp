#include "main_editor.h"

#include <fstream>
#include <string>
#include <stdio.h>

#include "shape_serialization_adapter.h"

#define EXP_OK 1
#define EXP_NO_EDITOR 0
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

void MainEditor::init(HWND _hWnd)
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
		this->exportProject(EXP_STATUS_AUTO);
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

void MainEditor::exportProject(int status)
{
	if (this->shapeEditor)
	{
		Shape** shapes = this->shapeEditor->getShapes();
		int count = this->shapeEditor->getCounter();
		FILE* fp;
		fopen_s(&fp, this->projectFileName, "w+");
		if (fp != NULL)
		{
			for (int i = 0; i < count; i++)
			{
				fprintf(fp, "%s\n", shapes[i]->serialize());
			}
			fclose(fp);
			if (status == EXP_STATUS_MANUALLY)
			{
				this->showExportMessage(EXP_OK);
			}
			return;
		}
		this->showExportMessage(EXP_CANNOT_OPEN_FILE);
	}
	else
	{
		this->showExportMessage(EXP_NO_EDITOR);
	}
}

void MainEditor::importProject()
{
	std::ifstream file(this->projectFileName);
	if (file.is_open())
	{	
		ShapeSerializationAdapter shapeSerializationAdapter = ShapeSerializationAdapter();
		ShapeEditor* currentEditor;
		if (this->shapeEditor)
		{
			currentEditor = this->shapeEditor;
		}
		else
		{
			Tool tool = Tool::POINT;
			currentEditor = tool.getEditor(this->hWnd);
		}
		currentEditor->clearAllShapes();
		Shape** shapes = currentEditor->getShapes();
		int counter = currentEditor->getCounter();
		std::string line;
		while (std::getline(file, line))
		{
			if (line != "")
			{
				shapes[counter++] = shapeSerializationAdapter.deserialize(line.c_str());
			}
		}
		currentEditor->init(shapes, counter);
		this->shapeEditor = currentEditor;
		this->OnPaint();
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
		this->exportProject(EXP_STATUS_AUTO);
	}
}

void MainEditor::deleteLastObject()
{
	if (this->shapeEditor)
	{
		this->shapeEditor->removeLastShape();
		this->exportProject(EXP_STATUS_AUTO);
	}
}

void MainEditor::clearAll()
{
	if (this->shapeEditor)
	{
		this->shapeEditor->clearAllShapes();
		this->exportProject(EXP_STATUS_AUTO);
	}
}

const char* MainEditor::getLastObjectLocalized()
{
	if (this->shapeEditor && this->isEditorEnabled)
	{
		Shape* shape = this->shapeEditor->getShapes()[this->shapeEditor->getCounter() - 1];
		return shape->getParamContent();
	}
	return NULL;
}

const char** MainEditor::getAllObjectsLocalized()
{
	if (this->shapeEditor)
	{
		Shape** shapes = this->shapeEditor->getShapes();
		int counter = this->shapeEditor->getCounter();
		if (counter > 0)
		{
			const char** serializedShapes = new const char* [counter];
			for (int i = 0; i < counter; i++)
			{
				serializedShapes[i] = shapes[i]->getParamContent();
			}
			serializedShapes[counter] = NULL;
			return serializedShapes;
		}
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
	case EXP_NO_EDITOR:
		message = "Помилка експортування: з початку використання програми не було введено жодної фiгури!";
		break;
	case EXP_CANNOT_OPEN_FILE:
		message = "Помилка експортування: не вдається вiдкрити файл для запису даних!";
		break;
	}
	MessageBoxA(this->hWnd, message, "Експорт", MB_OK);
}
