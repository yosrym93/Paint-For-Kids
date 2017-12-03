#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class DeleteAction : public Action {
	int DeletedID;
	CFigure* SelectedFig;
public:
	DeleteAction(ApplicationManager *pApp);

	//Reads draw color parameters
	virtual void ReadActionParameters();

	//Changes current/selected figure draw color
	virtual void Execute();
};