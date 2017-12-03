#include "DeleteAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager *pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters() {
	//Get a pointer to the selected figure and its ID
	SelectedFig = pManager->GetSelectedFigure();
	if (SelectedFig != NULL) 
		DeletedID = pManager->GetSelectedFigure()->GetID();
}

void DeleteAction::Execute() {
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	//Check if a figure is selected
	if (SelectedFig == NULL) 
		pOut->PrintMessage("No figure selected, Please select a figure first");
	else {
		//Delete the selected figure
		delete SelectedFig;
		pManager->SetSelectedFigure(NULL);
		//Rearrange the FigList and the IDs
		pManager->RemoveFig(DeletedID);

		pOut->PrintMessage("Figure(s) Deleted");
	}
}
