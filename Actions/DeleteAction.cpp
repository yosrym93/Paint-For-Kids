#include "DeleteAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager *pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters() {
	//Initialise local SelectedFigs and selectedCount 
	SelectedFigs = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();
}

void DeleteAction::Execute() {
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	//Check if a figure is selected
	if (SelectedFigs[0] == NULL) 
		pOut->PrintMessage("Delete figure : Select a figure first");
	else {
		for (int i = 0; i < selectedCount; i++) {
			//Gets the deleted figure ID
			DeletedID = SelectedFigs[i]->GetID();

			//Remove the figure from the FigList by ID
			pManager->RemoveFig(DeletedID);

			//Delete the selected figure
			delete SelectedFigs[i];
		}
		pManager->ClearSelectedFigs();
		pOut->PrintMessage("Figure(s) Deleted");
	}
}
