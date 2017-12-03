#include "AddCircAction.h"
#include "../Figures/CCirc.h"

#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

AddCircAction::AddCircAction(ApplicationManager *pApp) :Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center Point");

	//Read center and store in point P1
	pIn->GetDrawPoint(P1.x, P1.y, pOut);

	pOut->PrintMessage("New Circle: Click at Edge ");

	//Read Edge and store in point P2
	pIn->GetDrawCircPoint(P2.x, P2.y, pOut, P1.x, P1.y);

	CircGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
									//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth(); 
	pOut->ClearStatusBar();


}


void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Circle with the parameters read from the user
	CCirc *R = new CCirc(P1, P2, CircGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(R);

}