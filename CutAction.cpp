#include "CutAction.h"
#include"ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Input.h"



CutAction::CutAction(ApplicationManager*pApp):Action(pApp) , selectedFigure(NULL)
{
}
void CutAction::ReadActionParameters()
{
	//selectedFigure = pManager->GetSelectedFigure();
	Output* pOut = pManager->GetOutput();


	if (selectedFigure != NULL)
		pOut->PrintMessage("Cut figure : Selected figure moved into clipboard");

	if (selectedFigure == NULL)
		pOut->PrintMessage("Cut figure : Select a figure first");
}
void CutAction::Execute()
{
	ReadActionParameters();
	if (selectedFigure != NULL)
	{
		selectedFigure->SetSelected(false);
		//pManager->SetSelectedFigure(NULL);
		pManager->SetClipboard(selectedFigure);
		pManager->RemoveFig(selectedFigure->GetID());
		
	}
}



CutAction::~CutAction()
{
}
