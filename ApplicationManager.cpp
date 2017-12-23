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
#include "ToDrawAction.h"
#include "SaveAction.h"
#include"LoadAction.h"
#include"ExitAction.h"
#include"BringToForward.h"
#include"SendToBack.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	clipboardCount = 0;
	//Create an array of figure pointers and set them to NULL
	//and intialise SelectedFigs array to NULL
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
		SelectedFigs[i] = NULL;
		Clipboard[i] = NULL;
	}
	//initialise selectedCount to 0
	selectedCount = 0;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Reads the input command from the user and returns the corresponding action type
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
		//Figures' Drawing Actions//
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
		
		//Color Change Actions//
		case CHNG_DRAW_CLR:
			pAct = new ChngDrawClrAction(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new ChngFillClrAction(this);
			break;

		//Select Action//
		case SELECT:
			pAct = new SelectAction(this);
			break;

		//Delete Action//
		case DEL:
			pAct = new DeleteAction(this);
			break;

		//Copy, Cut and Paste Actions//
		case COPY:
			pAct = new CopyAction(this);
			break;

		case CUT:
			pAct = new CutAction(this);
			break;

		case PASTE:
			pAct = new PasteAction(this);
			break;

		//Send To Back/ Bring To Front Actions//
		case STB:
			pAct = new SendToBack(this);
			break;

		case BTF:
			pAct = new BringToForward(this);
			break;

		//Play Mode Actions//
		case P_H_TYPE:
			pAct = new PickByType(this);
			break;

		case P_H_COLOR:
			pAct = new PickByColor(this);
			break;

		case P_H_BOTH:
			pAct = new PickByBoth(this);
			break;

		//Save and Load Actions//
		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		// Other Actions //
		case TO_PLAY:
			pAct = new ToPlayAction(this);
			break;

		case TO_DRAW:
			pAct = new ToDrawAction(this);
			break;

		case EXIT:
			pAct = new ExitAction(this);
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

////////////////////////////////////////////////////////////////////////////////////
//Reads a color from the color toolbar
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
////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//


//Transfer figures in FigList to playmode
CFigure * ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}
////////////////////////////////////////////////////////////////////////////////////
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
		if (FigList[i]->HiddenStatus() == false)
			if (FigList[i]->IsOnFig(x, y))
				return FigList[i];
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Deletes all figures and nullifies the FigList (used with load)
void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	ClearSelectedFigs();
}



//==================================================================================//
//							Select Functions										//
//==================================================================================//

//Returns the number of selected figures
int ApplicationManager::GetSelectedCount() const {
	return selectedCount;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns a pointer to SelectedFigs array
CFigure* const* ApplicationManager::GetSelectedFigures() const {
	return SelectedFigs;
}
///////////////////////////////////////////////////////////////////////////////////
//Adds a figure to the SelectedFigs array
void ApplicationManager::AddSelectedFigure(CFigure* sf) {

	SelectedFigs[selectedCount] = sf;
	selectedCount++;
}
////////////////////////////////////////////////////////////////////////////////////
//Removes a figure from the SelectedFigs array
void ApplicationManager::RemoveSelectedFigure(CFigure* sf) {

	for (int i = 0; i < selectedCount; i++) {
		if (SelectedFigs[i] == sf) {
			SelectedFigs[i] = SelectedFigs[selectedCount - 1];
			SelectedFigs[selectedCount - 1] = NULL;
			selectedCount--;
			return;
		}
	}
}

void ApplicationManager::ClearSelectedFigs() {
	for (int i = 0; i < selectedCount; i++)
	{
		SelectedFigs[i] = NULL;
	}
	selectedCount = 0;
}

//==================================================================================//
//							Copy/Cut/Paste Functions								//
//==================================================================================//
//Sets no of figs currently in the clipboard
void ApplicationManager::setClipboardCount(int c)
{
	clipboardCount = c;
}
//////////////////////////////////////////////////////////////////////////////////
//Gets the number of figs currently in the clipboard
int ApplicationManager::getClipboardCount()
{
	return clipboardCount;
}
//////////////////////////////////////////////////////////////////////////////////
//Sets the clipboard array
void ApplicationManager::SetClipboard(CFigure** f)
{
	clearClipboard();
	for (int i = 0; i<selectedCount;i++)
	Clipboard[i] = f[i];
	setClipboardCount(selectedCount);
}
//////////////////////////////////////////////////////////////////////////////////
//Sets the clipboard array (overloaded)
void ApplicationManager::SetClipboard(CFigure*const* f)
{
	clearClipboard();
	for (int i = 0; i<selectedCount;i++)
		Clipboard[i] = f[i];
	setClipboardCount(selectedCount);
}
//////////////////////////////////////////////////////////////////////////////////
//Gets the array of figs in the clipboard
CFigure*const* ApplicationManager::GetClipboard() const
{
	return Clipboard;
}

//////////////////////////////////////////////////////////////////////////////////
//Clears the clipboard array
void ApplicationManager::clearClipboard()
{
	if ( Clipboard != NULL)
		for (int i = 0;i < clipboardCount;i++)
		{
			delete Clipboard[i];
			pOut->PrintMessage("Alhamdulillah");
			Clipboard[i] = NULL;
		}
}


//==================================================================================//
//				  Send to back/ Bring to forward Functions							//
//==================================================================================//

//Sorts the shapes accroding to the action (Bring To Forward)
void ApplicationManager::SortBTF(int index)
{
	//checking if the index sent is not the first shape 
	if (index != FigCount-1)
	{
		// putting the shape in temp
		CFigure* temp = FigList[index];
		int i;
		//Loops on all figures ,starting at the index of the Selected One, shifitng them 1 element  and setting their ID
		for (i = index; i < FigCount - 1; i++)
		{
			FigList[i] = FigList[i + 1];
			FigList[i]->SetID(i);
		}
		FigList[i] = temp;
		FigList[i]->SetID(i);
	}
}
//////////////////////////////////////////////////////////////////////////////////
//Sorts the shapes accroding to the action (Send To Back)
void ApplicationManager::SortSTB(int index)
{
	//checking if the element sent is not the last shape 
	if (index !=0)
	{
		//putting the shape in temp
		CFigure* temp = FigList[index];
		int i;
		//Loops on all figures ,starting at the index of the Selected One, shifting them back 1 element and setting their ID
		for (i = index; i>0; i--)
		{
			FigList[i] = FigList[i - 1];
			FigList[i]->SetID(i);
		}
		FigList[i] = temp;
		FigList[i]->SetID(i);
	}
}
//==================================================================================//
//							Save/Load Functions										//
//==================================================================================//

//Saves all figures in the FigList
void ApplicationManager::SaveAll(ofstream&OutFile)
{
	//Loop on each figure ,then saving it 
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->HiddenStatus() == false)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }


////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	ClearFigList();
	delete pIn;
	delete pOut;
}
