#pragma once
#include "Action.h"

class ChngDrawClrAction : public Action {
	ActionType inputColorAction;
	color DrawClr;
	int selectedCount; //number of selected figures
	CFigure* const* SelectedFigs; //pointer to selected figures
	//If a figure is selected
	bool IsSelectedFig;
	//If a color was picked in the color toolbar
	bool IsColor;
public:
	ChngDrawClrAction(ApplicationManager *pApp);

	//Reads draw color parameters
	virtual void ReadActionParameters();

	//Changes current/selected figure draw color
	virtual void Execute();
};

