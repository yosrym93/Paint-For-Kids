#pragma once
#include "Action.h"

class ToPlayAction : public Action {
public:
	ToPlayAction(ApplicationManager *pApp);

	//Doesn't do anything , won't be called, it must be overriden as it is pure virtual in Action class
	virtual void ReadActionParameters() {} ;

	//Executes the switch to play mode
	virtual void Execute();
};
