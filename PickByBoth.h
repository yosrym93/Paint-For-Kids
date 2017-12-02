#pragma once
#include "Actions\Action.h"
#include "Figures\CFigure.h"
class PickByBoth :
	public Action

{
	CFigure* Fig;
	int  no_combs, rand_fig_no, picked_comb_no;
	int combinations[23];
public:
	PickByBoth(ApplicationManager*);
	~PickByBoth();
	void ReadActionParameters();
	void Execute();
};

