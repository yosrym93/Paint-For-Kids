#include "CopyAction.h"
#include"..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Input.h"
#include "PasteAction.h"



CopyAction::CopyAction(ApplicationManager* pApp):Action(pApp)
{
	for (int i = 0; i < MaxFigCount; i++) 
		newSelectedFigures[i] = NULL;
}
void CopyAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	SelectedFigs = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();

	if (SelectedFigs[0] != NULL)
		pOut->PrintMessage("Copy figure : Selected figures copied into clipboard");
		
	if (SelectedFigs[0] == NULL)
		pOut->PrintMessage("Copy figure : Select a figure first");
}
void CopyAction::Execute()
{
	ReadActionParameters();
	if (SelectedFigs[0] != NULL)
	{
		for (int i = 0; i < selectedCount;i++)
		{
			newSelectedFigures[i] = SelectedFigs[i]->copy();
			newSelectedFigures[i]->SetSelected(false);
			
		}
		pManager->SetClipboard(newSelectedFigures);
	}
	
}


CopyAction::~CopyAction()
{
}
