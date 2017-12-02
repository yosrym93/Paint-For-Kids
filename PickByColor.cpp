#include "PickByColor.h"
#include "CMUgraphicsLib\colors.cpp" 
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"



PickByColor::PickByColor(ApplicationManager*pApp) :Action(pApp)
{
	no_colors = 0;
	for (int i = 0;i < 6;i++)
		clrs[i] = 0;
}


PickByColor::~PickByColor()
{
}

void PickByColor::ReadActionParameters()
{

	for (int i = 0; i < pManager->getFigCount();i++) {
		Fig = pManager->DrawnFigs(i);
		if (Fig->GetGfxInfo().isFilled) //counts color occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
				clrs[0]++;
			else if (Fig->GetGfxInfo().FillClr == WHITE)
				clrs[1]++;
			else if (Fig->GetGfxInfo().FillClr == BLUE)
				clrs[2]++;
			else if (Fig->GetGfxInfo().FillClr == GREEN)
				clrs[3]++;
			else if (Fig->GetGfxInfo().FillClr == RED)
				clrs[4]++;
		}
		else clrs[5]++; //unfilled
	}

	for (int i = 0;i < 6;i++)
		if (clrs[i] != 0)no_colors++;

	
}


void PickByColor::Execute()
{


	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

	if (no_colors > 1)
	{
		//Randomize
		rand_fig_no = rand() % pManager->getFigCount();
		//Counting the the color instances.
		Fig = pManager->DrawnFigs(rand_fig_no);
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				picked_color_no = clrs[0];
				pOut->PrintMessage("Select figures colored black!");
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				picked_color_no = clrs[1];
				pOut->PrintMessage("Select figures colored white!");
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				picked_color_no = clrs[2];
				pOut->PrintMessage("Select figures colored blue!");

			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				picked_color_no = clrs[3];
				pOut->PrintMessage("Select figures colored green!");

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				picked_color_no = clrs[4];
				pOut->PrintMessage("Select figures colored red!");

			}
		}
		else
		{
			picked_color_no = clrs[5]; //unfilled
			pOut->PrintMessage("Select figures with no color and lines!");

		}
		


	}
	else 			pOut->PrintMessage("You must have at least two or more colors to play pick by color!");
}
