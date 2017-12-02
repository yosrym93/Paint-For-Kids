#pragma once
#include "Action.h"

class AddTrigAction :public Action
{
private:
	Point P1, P2, P3;
	GfxInfo TrigGfxInfo;
public:
	AddTrigAction(ApplicationManager*);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();


};
