#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

class SelectAction : public Action {
private:
	Point P;
	CFigure* SelectedFig;
public:
	SelectAction(ApplicationManager *pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();
	void Select();
	void Unselect();
};


#endif