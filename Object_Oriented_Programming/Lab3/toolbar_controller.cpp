#include "toolbar_controller.h"
#include <atlbase.h>

ToolbarController::ToolbarController(HWND hWnd)
{
	this->selectedToolId = -1;
	this->parent = hWnd;
	TBBUTTON tbb[4];
	ZeroMemory(tbb, sizeof(tbb));
	tbb[0].iBitmap = STD_FILENEW;
	tbb[0].fsState = TBSTATE_ENABLED;
	tbb[0].fsStyle = TBSTYLE_BUTTON;
	tbb[0].idCommand = ID_TOOL_POINT;
	tbb[1].iBitmap = STD_FILEOPEN;
	tbb[1].fsState = TBSTATE_ENABLED;
	tbb[1].fsStyle = TBSTYLE_BUTTON;
	tbb[1].idCommand = ID_TOOL_LINE;
	tbb[2].iBitmap = STD_FILESAVE;
	tbb[2].fsState = TBSTATE_ENABLED;
	tbb[2].fsStyle = TBSTYLE_BUTTON;
	tbb[2].idCommand = ID_TOOL_RECT;
	tbb[3].iBitmap = STD_CUT;
	tbb[3].fsState = TBSTATE_ENABLED;
	tbb[3].fsStyle = TBSTYLE_BUTTON;
	tbb[3].idCommand = ID_TOOL_ELLIPSE;
	this->instance = CreateToolbarEx(this->parent,
		WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP | TBSTYLE_TOOLTIPS,
		IDC_TOOLBAR, 1, HINST_COMMCTRL, IDB_STD_SMALL_COLOR,
		tbb, 4, 0, 0, 0, 0, sizeof(TBBUTTON));
}

bool ToolbarController::OnButtonPress(Tool tool)
{
	this->resetAllButtons();
	if (this->selectedToolId != tool.getToolbarItemId())
	{
		this->selectedToolId = tool.getToolbarItemId();
		SendMessage(this->instance, TB_PRESSBUTTON, this->selectedToolId, TRUE);
		return TRUE;
	}
	else {
		this->selectedToolId = -1;
		return FALSE;
	}
}

void ToolbarController::OnNotify(WPARAM wParam, LPARAM lParam)
{
	USES_CONVERSION;
	LPNMHDR pnmh = (LPNMHDR)lParam;
	LPCWSTR pText = L"";
	if (pnmh->code == TTN_NEEDTEXT)
	{
		LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
		switch (lpttt->hdr.idFrom)
		{
		case ID_TOOL_POINT:
			pText = A2W(Tool(Tool::POINT).getTitle());
			break;
		case ID_TOOL_LINE:
			pText = A2W(Tool(Tool::LINE).getTitle());
			break;
		case ID_TOOL_RECT:
			pText = A2W(Tool(Tool::RECT).getTitle());
			break;
		case ID_TOOL_ELLIPSE:
			pText = A2W(Tool(Tool::ELLIPSE).getTitle());
			break;
		default:
			pText = L"ўось невiдоме";
			break;
		}
		lstrcpy(lpttt->szText, pText);
	}
}

void ToolbarController::OnSize()
{
	RECT rc, rw;
	GetClientRect(this->parent, &rc);
	GetWindowRect(this->instance, &rw);
	MoveWindow(this->instance, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
}

void ToolbarController::generateButtons()
{
	/*ZeroMemory(tbb, sizeof(tbb));
	*/	
}

void ToolbarController::resetAllButtons()
{
	SendMessage(this->instance, TB_PRESSBUTTON, Tool(Tool::POINT).getToolbarItemId(), FALSE);
	SendMessage(this->instance, TB_PRESSBUTTON, Tool(Tool::LINE).getToolbarItemId(), FALSE);
	SendMessage(this->instance, TB_PRESSBUTTON, Tool(Tool::RECT).getToolbarItemId(), FALSE);
	SendMessage(this->instance, TB_PRESSBUTTON, Tool(Tool::ELLIPSE).getToolbarItemId(), FALSE);
}


/*TBBUTTON pointButton, lineButton, rectButton, ellipseButton;
	pointButton.iBitmap = STD_FILENEW;
	pointButton.idCommand = ID_TOOL_POINT;
	lineButton.iBitmap = STD_FILEOPEN;
	lineButton.idCommand = ID_TOOL_LINE;
	rectButton.iBitmap = STD_FILESAVE;
	rectButton.idCommand = ID_TOOL_RECT;
	ellipseButton.iBitmap = STD_PRINT;
	ellipseButton.idCommand = ID_TOOL_ELLIPSE;
	this->tbb[0] = pointButton;
	this->tbb[1] = lineButton;
	this->tbb[2] = rectButton;
	this->tbb[3] = ellipseButton;
	for (int i = 0; i < sizeof(this->tbb) / sizeof(*this->tbb); i++)
	{
		tbb[i].fsState = TBSTATE_ENABLED;
		tbb[i].fsStyle = TBSTYLE_BUTTON;
	}*/

/*TBBUTTON tbb[4];

	ZeroMemory(tbb, sizeof(tbb));
	tbb[0].iBitmap = STD_FILENEW;
	tbb[0].fsState = TBSTATE_ENABLED;
	tbb[0].fsStyle = TBSTYLE_BUTTON;
	tbb[0].idCommand = ID_TOOL_POINT;

	tbb[1].iBitmap = STD_FILENEW;
	tbb[1].fsState = TBSTATE_ENABLED;
	tbb[1].fsStyle = TBSTYLE_BUTTON;
	tbb[1].idCommand = ID_TOOL_LINE;

	tbb[2].iBitmap = STD_FILENEW;
	tbb[2].fsState = TBSTATE_ENABLED;
	tbb[2].fsStyle = TBSTYLE_BUTTON;
	tbb[2].idCommand = ID_TOOL_RECT;

	tbb[3].iBitmap = STD_FILENEW;
	tbb[3].fsState = TBSTATE_ENABLED;
	tbb[3].fsStyle = TBSTYLE_BUTTON;
	tbb[3].idCommand = ID_TOOL_ELLIPSE;


	HWND hwndToolBar = CreateToolbarEx(hWnd,
		WS_CHILD | WS_VISIBLE | WS_BORDER
		| WS_CLIPSIBLINGS | CCS_TOP,
		6000,
		1, HINST_COMMCTRL, IDB_STD_SMALL_COLOR,
		tbb,
		4,
		0, 0, 0, 0,
		sizeof(TBBUTTON));

		TBBUTTON* pointButton = new TBBUTTON();
	TBBUTTON* lineButton = new TBBUTTON();
	TBBUTTON* rectButton = new TBBUTTON();
	TBBUTTON* ellipseButton = new TBBUTTON();
	pointButton->iBitmap = STD_FILENEW;
	pointButton->fsState = TBSTATE_ENABLED;
	pointButton->fsStyle = TBSTYLE_BUTTON;
	pointButton->idCommand = ID_TOOL_POINT;
	lineButton->iBitmap = STD_FILEOPEN;
	lineButton->fsState = TBSTATE_ENABLED;
	lineButton->fsStyle = TBSTYLE_BUTTON;
	lineButton->idCommand = ID_TOOL_LINE;
	rectButton->iBitmap = STD_FILESAVE;
	rectButton->fsState = TBSTATE_ENABLED;
	rectButton->fsStyle = TBSTYLE_BUTTON;
	rectButton->idCommand = ID_TOOL_RECT;
	ellipseButton->iBitmap = STD_PRINT;
	ellipseButton->fsState = TBSTATE_ENABLED;
	ellipseButton->fsStyle = TBSTYLE_BUTTON;
	ellipseButton->idCommand = ID_TOOL_ELLIPSE;
	this->tbb[0] = pointButton;
	this->tbb[1] = lineButton;
	this->tbb[2] = rectButton;
	this->tbb[3] = ellipseButton;


	/*this->generateButtons();
	HWND hWndToolbar = CreateToolbarEx(hWnd,
		WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP,
		IDC_TOOLBAR, 1, HINST_COMMCTRL, IDB_STD_SMALL_COLOR, this->tbb,
		4, 0, 0, 0, 0, sizeof(TBBUTTON));*/