#pragma once
#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H

#include "Actions\Action.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
class PasteAction :
	public Action
{
private:
	CFigure * figure;
	Point P;


public:
	PasteAction(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();


};
#endif

