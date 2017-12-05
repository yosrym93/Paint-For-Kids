#include "PasteAction.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include"GUI\Output.h"


PasteAction::PasteAction(ApplicationManager* pApp):Action(pApp)
{
}
void PasteAction::ReadActionParameters()
{
	figure = pManager->GetClipboard();

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (figure != NULL)
	{
		//Read clicked point and store in P
		pOut->PrintMessage("Paste figure : Click any where");
		pIn->GetDrawPoint(P.x, P.y, pOut);
	}
	if (figure == NULL)
		pOut->PrintMessage("Paste figure : Clipboard is empty, copy or cut a figure first");
}
void PasteAction::Execute()
{



	ReadActionParameters();

	if (figure != NULL)
	{
		
		if (pManager->IsCopied())
			figure = pManager->GetClipboard()->copy();
		else
			figure = pManager->GetClipboard();
		pManager->AddFigure(figure->paste(P));
		pManager->setCopied(true);
	}


}

