#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class BringToForward :public Action
{
	CFigure* SelectedFig;
	int SelectedID;
public:

	BringToForward(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();

};
