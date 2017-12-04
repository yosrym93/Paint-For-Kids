
#ifndef COPY_ACTION_H
#define COPY_ACTION_H
#include "d:\paintforkids\Actions\Action.h"
#include "d:\paintforkids\Actions\SelectAction.h"
#include "d:\paintforkids\Figures\CFigure.h"
class CopyAction :
	public Action
{
private:
	CFigure* selectedFigure;
public:
	CopyAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CopyAction();
};
#endif

