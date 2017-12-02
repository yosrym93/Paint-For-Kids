#pragma once
#include "Figures\CFigure.h"
#include "Actions\Action.h"

class PickByColor :
	public Action
{
	CFigure* Fig;
	int  no_colors,rand_fig_no,picked_color_no;
	int clrs[6];
public:
	PickByColor(ApplicationManager*);
	~PickByColor();
	void ReadActionParameters();
	void Execute();

};

