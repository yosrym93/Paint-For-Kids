#pragma once
#include "Action.h"
 
class ExitAction :public Action
{
public:
	ExitAction(ApplicationManager *pApp);
	
	virtual void ReadActionParameters();

	//Execute action (Exit action)
	virtual void Execute();


};
