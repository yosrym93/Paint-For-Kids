#include "AddLineAction.h"
#include "../Figures/CLine.h"

#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"
AddLineAction::AddLineAction(ApplicationManager * pApp) :Action(pApp)
{}
void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at Start Point");

	//Read 1st corner and store in point P1
	pIn->GetDrawPoint(P1.x, P1.y, pOut);

	pOut->PrintMessage("New Line: Click at End Point");

	//Read 2nd corner and store in point P2
	pIn->GetDrawPoint(P2.x, P2.y, pOut);

	LineGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth(); 
	pOut->ClearStatusBar();

}
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Line with the parameters read from the user
	CLine *R = new CLine(P1, P2, LineGfxInfo);

	//Add the Line to the list of figures
	pManager->AddFigure(R);
}