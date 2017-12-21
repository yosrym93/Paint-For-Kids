#include "SelectAction.h"


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
		else
			Select();
	}
}

//Selected an unselected figure
void SelectAction::Select() { 
	SelectedFig->SetSelected(true); //Sets the figure as "selected"
	pManager->AddSelectedFigure(SelectedFig); //Add the figure to ApplicationManager's SelectedFigs array
	Output* pOut = pManager->GetOutput(); //Get a Pointer to the Output Interface
	SelectedFig->PrintInfo(pOut); //Print the selected figure info on the status bar
}

//Unselect a selected figure
void SelectAction::Unselect() {
	SelectedFig->SetSelected(false); //Sets the figure as "unselected"
	pManager->RemoveSelectedFigure(SelectedFig);	//Removes the figure from ApplicationManager's SelectedFigs array
}