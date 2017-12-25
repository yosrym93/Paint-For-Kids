#include"BringToForward.h"
#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/output.h"


BringToForward::BringToForward(ApplicationManager *pApp) :Action(pApp)
{
}

//Read parameters for BTF action
void BringToForward::ReadActionParameters()
{
	//Checks if a single figure is selected
	if (pManager->GetSelectedFigures()[1] == NULL && pManager->GetSelectedFigures()[0] != NULL) {
		//a pointer to the selected Fig.
		SelectedFig = pManager->GetSelectedFigures()[0];
		//if there is a figure selected store its id
		SelectedID = pManager->GetSelectedFigures()[0]->GetID();
	}
	else
		//NULL if no figures, or more than one figure are selected
		SelectedFig = NULL;
}
//excute BTF action
void BringToForward::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//if one figure is selected bring it to the front
	if (SelectedFig)
	{
		pManager->SortBTF(SelectedID);
		pOut->PrintMessage("Figure brought to the front");
	}
	//else print one figure needs to be selected
	else
		pOut->PrintMessage("Bring To Forward: One figure needs to be selected");

}