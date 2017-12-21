#include "SendToBack.h"
#include "../paintforkids/ApplicationManager.h"

#include "../paintforkids/GUI/Input.h"
#include "../paintforkids/GUI/output.h"


SendToBack::SendToBack(ApplicationManager *pApp) :Action(pApp)
{
}
//Read parameters for the STB action
void SendToBack::ReadActionParameters()
{
	//a pointer to the selected Fig.
	SelectedFig = pManager->GetSelectedFigure();
	//if there is a figure selected store its id
	if (SelectedFig != NULL)
		SelectedID = pManager->GetSelectedFigure()->GetID();
}
//excute the STB action
void SendToBack::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	// if there is a selected figure send it back
	if (SelectedFig)
	{
		pManager->SortSTB(SelectedID);
		pOut->PrintMessage("Figure (S) Shifted");
	}
	//else printing select a figure first
	else
		pOut->PrintMessage("Send To Back : Select a figure first");

}