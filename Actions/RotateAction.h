#pragma once
#include "Action.h"
class RotateAction : public Action
{
	CFigure* const* SelectedFigs; //pointer to selected figures
	int selectedCount; //number of selected figuresS
public:
	RotateAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
};

