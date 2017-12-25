#include "ToDrawAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ToDrawAction::ToDrawAction(ApplicationManager *pApp) :Action(pApp)
{
}

void ToDrawAction::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	pOut->CreateDrawToolBar();
	pOut->PrintMessage("Switched to Draw Mode! Let's Draw! ");
}

