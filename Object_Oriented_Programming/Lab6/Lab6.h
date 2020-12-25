#pragma once

#include "framework.h"
#include "resource.h"

#define OBJECT2_HWND 4000
#define OBJECT2_DATA 4001
#define OBJECT3_HWND 5000
#define OBJECT3_DATA 5001

struct ChildProcessData
{
	long hWndObject2;
	long hWndObject3;
};
