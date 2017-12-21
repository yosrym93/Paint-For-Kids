#include"BringToForward.h"
#include "../paintforkids/ApplicationManager.h"

#include "../paintforkids/GUI/Input.h"
#include "../paintforkids/GUI/output.h"


BringToForward::BringToForward(ApplicationManager *pApp) :Action(pApp)
{
}

//Read parameters for BTF action
void BringToForward::ReadActionParameters()
{
	//a pointer to the selected Fig.
	SelectedFig = pManager->GetSelectedFigures()[0];
	//if there is a figure selected store its id
	if (SelectedFig != NULL)
		SelectedID = pManager->GetSelectedFigures()[0]->GetID();
}
//excute BTF action
void BringToForward::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	// if there is a selected figure Bring it forward
	if (SelectedFig)
	{
		pManager->SortBTF(SelectedID);
		pOut->PrintMessage("Figure Shifted ");
	}
	// else printing select a figure first
	else
		pOut->PrintMessage("Bring To Forward: Select a figure first");

}