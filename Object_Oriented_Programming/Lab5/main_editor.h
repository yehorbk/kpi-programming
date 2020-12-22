#pragma once

#include "framework.h"
#include "tool.h"
#include "shape.h"
#include "shape_editor.h"

class MainEditor
{
private:
	HWND hWnd;
	ShapeEditor* shapeEditor;
	bool isEditorEnabled;
	const char* projectFileName;
	MainEditor()
	{
		this->hWnd = NULL;
		this->shapeEditor = NULL;
		this->isEditorEnabled = FALSE;
		this->projectFileName = "editor-objects.txt";
	};
	MainEditor(const MainEditor&);
	MainEditor& operator=(MainEditor&);
	void setUpEditor(ShapeEditor* _shapeEditor);
	void showExportMessage(int status);

public:
	~MainEditor();
	static MainEditor& getInstance()
	{
		static MainEditor instance;
		return instance;
	};
	void setHwnd(HWND);
	void Start(Tool tool);
	void enableEditor();
	void disableEditor();
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
	void OnPaint();
	void exportProject();
	void importProject();
	void selectObject(int index);
	void deleteObject(int index);
	void undo();
	void clearAll();
	const char* getLastSerialized();
};
