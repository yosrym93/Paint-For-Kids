#include "ToPlayAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Output.h"

ToPlayAction::ToPlayAction(ApplicationManager *pApp) :Action(pApp)
{}

void ToPlayAction::Execute() {
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	pOut->CreatePlayToolBar();
	pOut->PrintMessage("Switched to Play Mode! Let's Play!");
}