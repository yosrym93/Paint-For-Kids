#pragma once
#include "Figures\CFigure.h"

#include "Actions\Action.h"
class PickByType :
	public Action
{
	CFigure* Fig;
	int  no_figs, rand_fig_no, picked_fig_no;
	int figs[4];
public:
	PickByType(ApplicationManager*);
	~PickByType();
	void ReadActionParameters();
	void Execute();
};

