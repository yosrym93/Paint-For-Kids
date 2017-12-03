#include "PickByBoth.h"
#include "ApplicationManager.h"
#include "Figures\CRectangle.h"
#include "Figures\CLine.h"
#include "Figures\CCirc.h"
#include "Figures\CTrig.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include <iostream>
using namespace std;



PickByBoth::PickByBoth(ApplicationManager* pApp):Action(pApp)
{
	no_combs = 0;
	for (int i = 0;i < 23;i++)
		combinations[i] = 0;
}


PickByBoth::~PickByBoth()
{

}

void PickByBoth::ReadActionParameters()
{
	for (int i = 0; i < pManager->getFigCount();i++) {
		Fig = pManager->DrawnFigs(i);
		if ((Fig->GetGfxInfo().isFilled) && !(dynamic_cast<CLine*>(Fig))) //counts combinations occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[0]++;
				else if (dynamic_cast<CTrig*>(Fig))
					combinations[1]++;
				else 
					combinations[2]++;
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[3]++;
				else if (dynamic_cast<CTrig*>(Fig))
					combinations[4]++;
				else 
					combinations[5]++;
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[6]++;
				else if (dynamic_cast<CTrig*>(Fig))
					combinations[7]++;
				else 
					combinations[8]++;
			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[9]++;
				else if (dynamic_cast<CTrig*>(Fig))
					combinations[10]++;
				else 
					combinations[11]++;
			}
			else
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[12]++;
				else if (dynamic_cast<CTrig*>(Fig))
					combinations[13]++;
				else 
					combinations[14]++;
			}
		}
		else {
			if (dynamic_cast<CRectangle*>(Fig))
				combinations[15]++;
			else if (dynamic_cast<CTrig*>(Fig))
				combinations[16]++;
			else if (dynamic_cast<CCirc*>(Fig))
				combinations[17]++;
			else
			{

				if (Fig->GetGfxInfo().DrawClr == BLACK)
					combinations[18]++;

				else if (Fig->GetGfxInfo().DrawClr == WHITE)
					combinations[19]++;

				else if (Fig->GetGfxInfo().DrawClr == BLUE)
					combinations[20]++;

				else if (Fig->GetGfxInfo().DrawClr == GREEN)
					combinations[21]++;

				else
					combinations[22]++;
				
			}
		}
	}

	for (int i = 0;i < 23;i++)
		if (combinations[i] != 0)
			no_combs++;


}

void PickByBoth::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

	if (no_combs > 1)
	{
		//Randomize
		rand_fig_no = rand() % pManager->getFigCount();
		//Counting the the color instances.
		Fig = pManager->DrawnFigs(rand_fig_no);
		if ((Fig->GetGfxInfo().isFilled) && !(dynamic_cast<CLine*>(Fig)))
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[0];
					pOut->PrintMessage("Pick up all the black rectangles!");

				}
				else if (dynamic_cast<CTrig*>(Fig))
				{
					picked_comb_no = combinations[1];
					pOut->PrintMessage("Pick up all the black triangles!");

				}
				else
				{
					picked_comb_no = combinations[2];
					pOut->PrintMessage("Pick up all the black circles!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[3];
					pOut->PrintMessage("Pick up all the white rectangles!");

				}
				else if (dynamic_cast<CTrig*>(Fig))
				{
					picked_comb_no = combinations[4];
					pOut->PrintMessage("Pick up all the white triangles!");

				}
				else
				{
					picked_comb_no = combinations[5];
					pOut->PrintMessage("Pick up all the white circles!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[6];
					pOut->PrintMessage("Pick up all the blue rectangles!");

				}
				else if (dynamic_cast<CTrig*>(Fig))
				{
					picked_comb_no = combinations[7];
					pOut->PrintMessage("Pick up all the blue triangles!");

				}
				else
				{
					picked_comb_no = combinations[8];
					pOut->PrintMessage("Pick up all the blue circles!");

				}


			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[9];
					pOut->PrintMessage("Pick up all the green rectangles!");

				}
				else if (dynamic_cast<CTrig*>(Fig))
				{
					picked_comb_no = combinations[10];
					pOut->PrintMessage("Pick up all the green triangles!");

				}
				else
				{
					picked_comb_no = combinations[11];
					pOut->PrintMessage("Pick up all the green circles!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[12];
					pOut->PrintMessage("Pick up all the red rectangles!");

				}
				else if (dynamic_cast<CTrig*>(Fig))
				{
					picked_comb_no = combinations[13];
					pOut->PrintMessage("Pick up all the red triangles!");

				}
				else
				{
					picked_comb_no = combinations[14];
					pOut->PrintMessage("Pick up all the red circles!");

				}

			}
		}
		else
		{
			if (dynamic_cast<CRectangle*>(Fig))
			{
				picked_comb_no = combinations[15];
				pOut->PrintMessage("Pick up all the unfilled rectangles!");

			}
			else if (dynamic_cast<CTrig*>(Fig))
			{
				picked_comb_no = combinations[16];
				pOut->PrintMessage("Pick up all the unfilled triangles!");

			}
			else if (dynamic_cast<CCirc*>(Fig))
			{
				picked_comb_no = combinations[17];
				pOut->PrintMessage("Pick up all the unfilled circles!");

			}
			else
			{
				if (Fig->GetGfxInfo().DrawClr == BLACK)
				{
					picked_comb_no = combinations[18];
					pOut->PrintMessage("Pick up black lines!");
				}
				else if (Fig->GetGfxInfo().DrawClr == WHITE)
				{
					picked_comb_no = combinations[19];
					pOut->PrintMessage("Pick up black white lines!");
				}
				else if (Fig->GetGfxInfo().DrawClr == BLUE)
				{
					picked_comb_no = combinations[20];
					pOut->PrintMessage("Pick up blue lines!");

				}
				else if (Fig->GetGfxInfo().DrawClr == GREEN)
				{
					picked_comb_no = combinations[21];
					pOut->PrintMessage("Pick up green lines!");

				}
				else 
				{
					picked_comb_no = combinations[22];
					pOut->PrintMessage("Pick up red lines!");

				}

			}

		}

	}
	else pOut->PrintMessage("You must have at least two or more combinations to play pick by both!");

}
