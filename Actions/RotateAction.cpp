#include "RotateAction.h"



RotateAction::RotateAction(ApplicationManager *pApp) :Action(pApp)
{
}

void RotateAction::ReadActionParameters()
{
	//Initialise local SelectedFigs and selectedCount 
	SelectedFigs = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();
}

void RotateAction::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//if one figure is selected bring it to the front
	if (SelectedFigs[0])
	{
		for(int i = 0; i < selectedCount; i++)
			SelectedFigs[i]->Rotate();
		pOut->PrintMessage("Rotate Action : Figure rotated by 90 degrees");
	}
	//else print one figure needs to be selected
	else
		pOut->PrintMessage("Rotate Action: Select a figure first");

}


