#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager *pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure: Click a figure");

	//Read clicked point and store in P
	pIn->GetPointClicked(P.x, P.y);

	//Clear the status bar
	pOut->ClearStatusBar();
}

//Execute the action
void SelectAction::Execute()
{
	//Reads the point that the user clicked
	ReadActionParameters();

	//Set SelectedFig to the clicked figure (if any)
	SelectedFig = pManager->GetFigure(P.x, P.y);

	//Checks if a figure was clicked, and whether the clicked figure is already selected
	if (SelectedFig != NULL) {
		if (SelectedFig->IsSelected())
			Unselect();
		else if (pManager->GetSelectedFigure() == NULL) {
			Select();
		}
	}
}

//Selected an unselected figure
void SelectAction::Select() { 
	SelectedFig->SetSelected(true);
	pManager->SetSelectedFigure(SelectedFig); //Set the ApplicationManager SelectedFig pointer
}

//Unselect a selected figure
void SelectAction::Unselect() {
	SelectedFig->SetSelected(false);
	SelectedFig = NULL;
	pManager->SetSelectedFigure(SelectedFig);	//Resets the ApplicationManager pointer (NULL indicates no figure selected)
}