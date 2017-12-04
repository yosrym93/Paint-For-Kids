#pragma once
#ifndef CUT_ACTION_H
#define CUT_ACTION_H
#include "d:\paintforkids\Actions\Action.h"
#include "d:\paintforkids\Actions\SelectAction.h"
#include "d:\paintforkids\Figures\CFigure.h"
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

