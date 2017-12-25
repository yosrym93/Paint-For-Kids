#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"

class PickByColor :
	public Action
{
	CFigure* Fig;
	int  no_colors, rand_fig_no, picked_color_no, wrgSel, rigSel;
	int clrs[6];
	Point P;
	color AssignColor(CFigure*);
	void PrntScore(int);
public:
	PickByColor(ApplicationManager*);
	~PickByColor();
	void ReadActionParameters();
	void Execute();

};

