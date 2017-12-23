
#ifndef COPY_ACTION_H
#define COPY_ACTION_H
#include "Actions\Action.h"
#include "Actions\SelectAction.h"
#include "Figures\CFigure.h"
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

