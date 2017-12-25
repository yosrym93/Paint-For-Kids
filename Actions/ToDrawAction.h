#pragma once
#include "Action.h"

class ToDrawAction : public Action {
public:
	ToDrawAction(ApplicationManager *pApp);

	//Doesn't do anything , won't be called, it must be overriden as it is pure virtual in Action class
	virtual void ReadActionParameters() {};

	//Executes the switch to draw mode
	virtual void Execute();
};
