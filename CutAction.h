#pragma once
#ifndef CUT_ACTION_H
#define CUT_ACTION_H
#include "Actions\Action.h"
#include "Actions\SelectAction.h"
#include "Figures\CFigure.h"
class CutAction :
	public Action
{
private:
	CFigure* selectedFigure;
public:
	CutAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CutAction();
};
#endif

