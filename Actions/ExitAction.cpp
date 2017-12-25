#include "ExitAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"


ExitAction::ExitAction(ApplicationManager *pApp): Action(pApp)
{}


void ExitAction::ReadActionParameters()
{}

//Execute action (Exit action)
void ExitAction::Execute()
{
	pManager->clearClipboard();
}
