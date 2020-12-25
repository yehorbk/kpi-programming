#pragma once

#include "framework.h"
#include "resource.h"

#define OBJECT2_HWND 4000
#define OBJECT2_DATA 4001
#define OBJECT2_FINISH 4002
#define OBJECT3_HWND 5000
#define OBJECT3_DATA 5001
#define OBJECT3_FINISH 5002

struct ChildProcessData
{
	const char* identifierObject2 = "OBJECT2";
	const char* executableObject2 = "Object2.exe";
	long hWndObject2;
	const char* identifierObject3 = "OBJECT3";
	const char* executableObject3 = "Object3.exe";
	long hWndObject3;
};
