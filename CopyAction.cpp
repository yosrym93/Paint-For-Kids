#include "CopyAction.h"
#include"ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Input.h"



CopyAction::CopyAction(ApplicationManager* pApp):Action(pApp),selectedFigure(NULL)
{
}
void CopyAction::ReadActionParameters()
{
	selectedFigure = pManager->GetSelectedFigure();
	Output* pOut = pManager->GetOutput();


	if (selectedFigure != NULL)
		pOut->PrintMessage("Copy figure : Selected figure copied into clipboard");
		
	if (selectedFigure == NULL)
		pOut->PrintMessage("Copy figure : Select a figure first");
}
void CopyAction::Execute()
{
	ReadActionParameters();
	if (selectedFigure != NULL)
		pManager->SetClipboard(selectedFigure);

	
}


CopyAction::~CopyAction()
{
}