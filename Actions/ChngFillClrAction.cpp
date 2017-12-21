#include "ChngFillClrAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChngFillClrAction::ChngFillClrAction(ApplicationManager *pApp) :Action(pApp)
{}

void ChngFillClrAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Initialise local SelectedFigs and selectedCount 
	SelectedFigs = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();

	//Sets IsSelectedFig
	if (SelectedFigs[0] == NULL)
		IsSelectedFig = false;
	else
		IsSelectedFig = true;

	//Prints a custom message depending on whether a figure is selected
	string message;

	if (!IsSelectedFig)
		message = "Please pick the fill color";
	else
		message = "What fill color do you want to change the selected figure(s) to ?";

	pOut->PrintMessage(message);

	//Sets IsColor and DrawClr
	//GetColor returns true if a color is clicked, false otherwise
	if (!pManager->GetColor(FillClr))
		IsColor = false;
	else
		IsColor = true;

	pOut->ClearStatusBar();
}

void ChngFillClrAction::Execute() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Reads the input draw color
	ReadActionParameters();

	//Executes only if a color is selected
	if (IsColor) {
		//Changes current draw color if no figure is selected
		if (!IsSelectedFig) {
			pOut->setIsFilled(true);
			pOut->setCrntFillColor(FillClr);
		}

		//Changes selected figure(s) draw color
		else {
			for (int i = 0; i < selectedCount; i++)
				SelectedFigs[i]->ChngFillClr(FillClr);
		}
	}
}
