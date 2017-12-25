#pragma once
#ifndef CUT_ACTION_H
#define CUT_ACTION_H
#include "Action.h"
#include "SelectAction.h"
#include "..\Figures\CFigure.h"
class CutAction :
	public Action
{
private:
	CFigure*const* SelectedFigs;
	int selectedCount;

public:
	CutAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CutAction();
};
#endif

