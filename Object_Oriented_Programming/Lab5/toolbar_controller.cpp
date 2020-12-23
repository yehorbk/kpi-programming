#include "toolbar_controller.h"
#include <atlbase.h>

ToolbarController::ToolbarController(HWND hWnd)
{
	this->selectedToolId = -1;
	this->hWndParent = hWnd;
	TBBUTTON tbb[6];
	ZeroMemory(tbb, sizeof(tbb));
	tbb[0].iBitmap = 0;
	tbb[0].fsState = TBSTATE_ENABLED;
	tbb[0].fsStyle = TBSTYLE_BUTTON;
	tbb[0].idCommand = ID_TOOL_POINT;
	tbb[1].iBitmap = 1;
	tbb[1].fsState = TBSTATE_ENABLED;
	tbb[1].fsStyle = TBSTYLE_BUTTON;
	tbb[1].idCommand = ID_TOOL_LINE;
	tbb[2].iBitmap = 2;
	tbb[2].fsState = TBSTATE_ENABLED;
	tbb[2].fsStyle = TBSTYLE_BUTTON;
	tbb[2].idCommand = ID_TOOL_RECT;
	tbb[3].iBitmap = 3;
	tbb[3].fsState = TBSTATE_ENABLED;
	tbb[3].fsStyle = TBSTYLE_BUTTON;
	tbb[3].idCommand = ID_TOOL_ELLIPSE;
	tbb[4].iBitmap = 4;
	tbb[4].fsState = TBSTATE_ENABLED;
	tbb[4].fsStyle = TBSTYLE_BUTTON;
	tbb[4].idCommand = ID_TOOL_OLINEO;
	tbb[5].iBitmap = 5;
	tbb[5].fsState = TBSTATE_ENABLED;
	tbb[5].fsStyle = TBSTYLE_BUTTON;
	tbb[5].idCommand = ID_TOOL_CUBE;
	this->hWndToolbar = CreateToolbarEx(this->hWndParent,
		WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP | TBSTYLE_TOOLTIPS,
		IDC_TOOLBAR, 6, GetModuleHandle(NULL), IDB_TOOLBAR,
		tbb, 6, 24, 24, 24, 24, sizeof(TBBUTTON));
}

bool ToolbarController::OnButtonPress(Tool tool)
{
	this->resetAllButtons();
	if (this->selectedToolId != tool.getToolbarItemId())
	{
		this->selectedToolId = tool.getToolbarItemId();
		SendMessage(this->hWndToolbar, TB_PRESSBUTTON, this->selectedToolId, TRUE);
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
		case ID_TOOL_OLINEO:
			pText = A2W(Tool(Tool::OLINEO).getTitle());
			break;
		case ID_TOOL_CUBE:
			pText = A2W(Tool(Tool::CUBE).getTitle());
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
	GetClientRect(this->hWndParent, &rc);
	GetWindowRect(this->hWndToolbar, &rw);
	MoveWindow(this->hWndToolbar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
}

void ToolbarController::resetAllButtons()
{
	SendMessage(this->hWndToolbar, TB_PRESSBUTTON, Tool(Tool::POINT).getToolbarItemId(), FALSE);
	SendMessage(this->hWndToolbar, TB_PRESSBUTTON, Tool(Tool::LINE).getToolbarItemId(), FALSE);
	SendMessage(this->hWndToolbar, TB_PRESSBUTTON, Tool(Tool::RECT).getToolbarItemId(), FALSE);
	SendMessage(this->hWndToolbar, TB_PRESSBUTTON, Tool(Tool::ELLIPSE).getToolbarItemId(), FALSE);
	SendMessage(this->hWndToolbar, TB_PRESSBUTTON, Tool(Tool::OLINEO).getToolbarItemId(), FALSE);
	SendMessage(this->hWndToolbar, TB_PRESSBUTTON, Tool(Tool::CUBE).getToolbarItemId(), FALSE);
}
