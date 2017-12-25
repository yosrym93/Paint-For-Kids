
#ifndef COPY_ACTION_H
#define COPY_ACTION_H
#include "Action.h"
#include "SelectAction.h"
#include "..\Figures\CFigure.h"
class CopyAction :
	public Action
{
private:
	int selectedCount;
	CFigure* const* SelectedFigs;
	CFigure* newSelectedFigures[MaxFigCount];
public:
	CopyAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CopyAction();
};
#endif

