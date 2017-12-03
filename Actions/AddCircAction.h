#pragma once
#include"Action.h"
class AddCircAction :public Action
{
private:
	Point P1, P2;
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager *pApp);
	
	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();

};
