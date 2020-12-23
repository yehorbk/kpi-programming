#pragma once

#include "framework.h"
#include "shape_editor.h"
#include "shape.h"
#include "tool.h"

#define EXP_STATUS_MANUALLY 1
#define EXP_STATUS_AUTO 0

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
	void init(HWND hWnd);
	void Start(Tool tool);
	void enableEditor();
	void disableEditor();
	void OnLBdown();
	void OnLBup();
	void OnMouseMove();
	void OnPaint();
	void exportProject(int status);
	void importProject();
	void selectObject(int index);
	void deleteObject(int index);
	void deleteLastObject();
	void clearAll();
	const char* getLastObjectLocalized();
	const char** getAllObjectsLocalized();
};
