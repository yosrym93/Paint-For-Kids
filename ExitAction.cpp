#include "ExitAction.h"
#include "../paintforkids/ApplicationManager.h"

#include "../paintforkids/GUI/Input.h"
#include "../paintforkids/GUI/output.h"


ExitAction::ExitAction(ApplicationManager *pApp): Action(pApp)
{}


void ExitAction::ReadActionParameters()
{}

//Execute action (Exit action)
void ExitAction::Execute()
{
	pManager->clearClipboard();
}
