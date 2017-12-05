#include "ExitAction.h"
#include "../paintforkids/ApplicationManager.h"

#include "../paintforkids/GUI/Input.h"
#include "../paintforkids/GUI/output.h"


ExitAction::ExitAction(ApplicationManager *pApp): Action(pApp)
{
}


void ExitAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("EXIT!!");



}

//Execute action (Exit action)
void ExitAction::Execute()
{
	ReadActionParameters();
	pManager->SetClipboard(NULL);
}
