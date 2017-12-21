#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class DeleteAction : public Action {
	int DeletedID; //ID of the deleted figure (for use in RemoveFig())
	int selectedCount; //Number of selected figures
	CFigure* const* SelectedFigs; //Pointer to the selected figures
	CFigure* DeletedFig; //temporary pointer used to store the figure being currently deleted
public:
	DeleteAction(ApplicationManager *pApp);

	//Reads draw color parameters
	virtual void ReadActionParameters();

	//Changes current/selected figure draw color
	virtual void Execute();
};