#include "PickByType.h"
#include "ApplicationManager.h"
#include "Figures\CRectangle.h"
#include "Figures\CLine.h"
#include "Figures\CCirc.h"
#include "Figures\CTrig.h"
#include "GUI\input.h"
#include "GUI\Output.h"


PickByType::PickByType(ApplicationManager*pApp):Action(pApp)
{
	no_figs = 0;
	for (int i = 0;i < 4;i++)
		figs[i] = 0;
}


PickByType::~PickByType()
{
}

void PickByType::ReadActionParameters()
{
	for (int i = 0;i < pManager->getFigCount();i++)
	{
		Fig = pManager->DrawnFigs(i);
		if (dynamic_cast<CRectangle*>(Fig))
			figs[0]++;
		else if (dynamic_cast<CTrig*>(Fig))
			figs[1]++;
		else if (dynamic_cast<CCirc*>(Fig))
			figs[2]++;
		else figs[3]++;
		for (int i = 0;i < 4;i++)
			if (figs[i] != 0)no_figs++;



	}
}

void PickByType::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (no_figs > 1)
	{
		//Randomize
		rand_fig_no = rand() % pManager->getFigCount();
		//counting fig instances
		Fig = pManager->DrawnFigs(rand_fig_no);
		if (dynamic_cast<CRectangle*>(Fig))
		{
			picked_fig_no = figs[0];
			pOut->PrintMessage("Pick up all the rectangles!");

		}
		else if (dynamic_cast<CTrig*>(Fig))
		{
			picked_fig_no = figs[1];
			pOut->PrintMessage("Pick up all the triangles!");

		}
		else if (dynamic_cast<CCirc*>(Fig))
		{
			picked_fig_no = figs[2];
			pOut->PrintMessage("Pick up all the circles!");

		}
		else
		{
			picked_fig_no = figs[3];
			pOut->PrintMessage("Pick up all the lines!");

		}

	}else pOut->PrintMessage("You must have at least two or more figures to play to play pick by figure!");


}
