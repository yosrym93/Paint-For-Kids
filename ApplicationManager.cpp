#pragma once
#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\SelectAction.h"
#include"Actions\AddLineAction.h"
#include"Actions\AddCircAction.h"
#include"Actions\AddTrigAction.h"
#include"Actions\DeleteAction.h"
#include"Actions\ChngDrawClrAction.h"
#include"Actions\ChngFillClrAction.h"
#include"Actions\ToPlayAction.h"
#include "PickByColor.h"
#include "PickByType.h"
#include "PickByBoth.h"
#include "PasteAction.h"
#include "CutAction.h"
#include "CopyAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelectedFig = NULL;
	Clipboard = NULL;
	isCopied = false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case DRAW_TRIG:
			pAct = new AddTrigAction(this);
			break;
			
		case CHNG_DRAW_CLR:
			pAct = new ChngDrawClrAction(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new ChngFillClrAction(this);
			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;

		case DEL:
			pAct = new DeleteAction(this);
			break;

		case TO_PLAY:
			pAct = new ToPlayAction(this);
			break;

		case COPY:
			pAct = new CopyAction(this);
			break;

		case CUT:
			pAct = new CutAction(this);
			break;

		case PASTE:
			pAct = new PasteAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}

bool ApplicationManager::GetColor(color &inputColor) {
	
	bool isColor = true;
	//Creating the color toolbar
	pOut->CreateColorToolBar();

	//Inputting draw color action
	ActionType inputColorAction = pIn->GetUserAction();

	switch (inputColorAction) {
	case SET_BLACK:
		inputColor = BLACK;
		break;

	case SET_WHITE:
		inputColor = WHITE;
		break;

	case SET_RED:
		inputColor = RED;
		break;

	case SET_GREEN:
		inputColor = GREEN;
		break;

	case SET_BLUE:
		inputColor = BLUE;
		break;

	default:
		isColor = false;
	}

	//Restoring the draw toolbar
	pOut->CreateDrawToolBar();

	return isColor;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Transfer figures in FigList to playmode
CFigure * ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}
//Transfer FigCount to playmode to avoid unnessecary loops
int ApplicationManager::getFigCount() const
{
	return FigCount;
}
////////////////////////////////////////////////////////////////////////////////////
//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount] = pFig;
		FigList[FigCount]->SetID(FigCount);
		FigCount++;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Removes a figure from the list of figures by its ID , then sorts the array
void ApplicationManager::RemoveFig(int ID) {
	//Loops on all figures ,starting at the index of the deleted one, shifting them back 1 element and setting their ID
	for (int i = ID; i < FigCount - 1; i++) {
		FigList[i] = FigList[i + 1];
		FigList[i]->SetID(i);
	}
	//Reduce FigCount by 1 and nullify the extra pointer (used to point at the deleted figure)
	FigCount--;
	FigList[FigCount] = NULL;
}

////////////////////////////////////////////////////////////////////////////////////
//If a figure is found return a pointer to it.
//if this point (x,y) does not belong to any figure return NULL
CFigure *ApplicationManager::GetFigure(int x, int y) const
{

	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->IsOnFig(x, y))
			return FigList[i];
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetSelectedFigure(CFigure* sf) {

	SelectedFig = sf;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetSelectedFigure() const {
	return SelectedFig;
}
///////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetClipboard(CFigure* f)
{
	if (!IsCopied() && Clipboard != NULL) 
		delete Clipboard;

	Clipboard = f;
	setCopied(false);
}
//////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetClipboard() const
{
	return Clipboard;
}
void ApplicationManager::setCopied(bool C)
{
	isCopied = C;
}
bool ApplicationManager::IsCopied()
{
	return isCopied;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

