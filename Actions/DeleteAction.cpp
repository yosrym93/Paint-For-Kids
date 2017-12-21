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
			//RemoveSelectedFigure resorts the array so the required figure to delete will always be the first one
			DeletedFig = SelectedFigs[0];

			//Removes the deleted figure from the SelectedFigs array
			pManager->RemoveSelectedFigure(SelectedFigs[0]);

			//Gets the deleted figure ID
			DeletedID = DeletedFig->GetID();

			//Delete the selected figure
			delete DeletedFig;

			//Remove the figure from the FigList by ID
			pManager->RemoveFig(DeletedID);
		}
		pOut->PrintMessage("Figure(s) Deleted");
	}
}
