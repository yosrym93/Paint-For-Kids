#include "PickByType.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCirc.h"
#include "..\Figures\CTrig.h"
#include "..\Figures\CLine.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PickByType::PickByType(ApplicationManager*pApp) :Action(pApp)
{
	no_figs = 0;
	rigSel = 0;
	wrgSel = 0;
	for (int i = 0;i < 4;i++)
		figs[i] = 0;
}
void PickByType::PrntScore(int S)
{
	Output* pOut = pManager->GetOutput();

	string message;
	if (S == 1)
	{
		rigSel++;
		message = "Right!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else 	if (S == 2)
	{
		wrgSel++;
		message = "Wrong!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else
		message = "YOU WIN!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	pOut->PrintMessage(message);


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




	}		for (int i = 0;i < 4;i++)
		if (figs[i] != 0)no_figs++;
}

void PickByType::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (no_figs > 1)
	{
		CFigure* clickedFig;
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
		while (picked_fig_no > 0)
		{
			{

				pIn->GetPointClicked(P.x, P.y);
				if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
				{
					clickedFig = pManager->GetFigure(P.x, P.y);
					if (clickedFig != NULL)
					{

						if ((dynamic_cast<CLine*>(clickedFig)) && (dynamic_cast<CLine*>(Fig)))
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else if ((dynamic_cast<CTrig*>(clickedFig)) && (dynamic_cast<CTrig*>(Fig)))
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else if ((dynamic_cast<CCirc*>(clickedFig)) && (dynamic_cast<CCirc*>(Fig)))
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else if ((dynamic_cast<CRectangle*>(clickedFig)) && (dynamic_cast<CRectangle*>(Fig)))
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else 
						{
							PrntScore(2);
							clickedFig->Hide();
							pManager->UpdateInterface();
						}
					}
				}
				else
				{
					pOut->PrintMessage("Toolbar clicked, game aborted.");
					picked_fig_no = -1;
				}


			}
			if (picked_fig_no == 0)
				PrntScore(3);



		}
	}
	else
		pOut->PrintMessage("You must have at least two or more figures to play to play pick by figure!");
	for (int i = 0; i < pManager->getFigCount();i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();





}
