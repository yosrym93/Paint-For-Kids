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

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	void Select();
	void Unselect();
};


#endif