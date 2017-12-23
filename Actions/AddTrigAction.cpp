#include "AddTrigAction.h"
#include "../Figures/CTrig.h"

#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"


AddTrigAction::AddTrigAction(ApplicationManager *pApp) :Action(pApp)
{
}

void AddTrigAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at Corner 1");

	//Read corner 1 and store in point P1
	pIn->GetDrawPoint(P1.x, P1.y, pOut);

	pOut->PrintMessage("New Triangle: Click at Corner 2 ");

	//Read corner 2 and store in point P2
	pIn->GetDrawPoint(P2.x, P2.y, pOut);

	pOut->PrintMessage("New Triangle: Click at Corner 3 ");

	//Read corner 3 and store in point P3
	pIn->GetDrawPoint(P3.x, P3.y, pOut);

	TrigGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TrigGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TrigGfxInfo.FillClr = pOut->getCrntFillColor();
	TrigGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();

}


void AddTrigAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTrig *R = new CTrig(P1, P2, P3, TrigGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(R);

}