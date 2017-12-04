#include "PasteAction.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include"GUI\Output.h"


PasteAction::PasteAction(ApplicationManager* pApp):Action(pApp)
{
}
void PasteAction ::ReadActionParameters()
{
	figure = pManager->GetClipboard();

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (figure != NULL)
		pOut->PrintMessage("Paste figure : Click any where");

	if (figure == NULL)
		pOut->PrintMessage("Paste figure : Clipboard is empty, copy or cut a figure first");

	//Read clicked point and store in P
	pIn->GetPointClicked(P.x, P.y);

}
void PasteAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	if (figure != NULL)
	{ 
		pManager->AddFigure(figure);



}


PasteAction::~PasteAction()
{
}
