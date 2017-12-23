#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#define MaxFigCount 200 //Max no. of figs
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <fstream>
#include <iostream>


//Main class that manages everything in the application.
class ApplicationManager
{

private:
	int FigCount;						//Actual number of figures
	CFigure* FigList[MaxFigCount];		//List of all figures (Array of pointers)
	CFigure* SelectedFigs[MaxFigCount]; //array of pointers to the selected figures
	CFigure* Clipboard[MaxFigCount];	//Pointer to the copied/cut figure

	int selectedCount;					//Number of selected figures
	int clipboardCount;					//Number of figures in clipboard

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions -- //
	
	ActionType GetUserAction() const;  //Reads the input command from the user and returns the corresponding action type
	void ExecuteAction(ActionType) ;   //Creates an action and executes it 
	bool GetColor(color&);			   //Reads a color from the color toolbar

	// -- Figures Management Functions -- // 

	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	int getFigCount() const;				//Returns number of figures
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* DrawnFigs(int) const;			//Transfer figures in FigList to playmode
	void RemoveFig(int);					//Removes the deleted figure from the array and resorts
	void ClearFigList();					//Deletes all figures and nullifies the FigList

	// -- Select Functions -- //

	int GetSelectedCount() const;					//Returns the number of selected figures
	void AddSelectedFigure(CFigure*);				//Adds a figure to the SelectedFigs array
	void RemoveSelectedFigure(CFigure*);			//Removes a figure from the SelectedFigs array
	CFigure* const* GetSelectedFigures() const;		//Returns a pointer to the SelectedFigs array
	void ClearSelectedFigs();                       //Cleares the SelectedFig array
	
	// -- Copy/Cut/Paste Functions -- //

	void setClipboardCount(int);			//Sets no of figs currently in the clipboard
	int getClipboardCount();				//Gets the number of figs currently in the clipboard
	void SetClipboard(CFigure**);			//Sets the clipboard array
	void SetClipboard(CFigure*const* );		//Sets the clipboard array (overloaded)
	CFigure*const* GetClipboard()const;		//Gets the array of figs in the clipboard
	void clearClipboard();					//Clears the clipboard array


	// -- Save/Load Functions -- //
	
	void SaveAll(ofstream&OutFile);				//Saves all figures

	// -- BTF/STB Functions -- //

	void SortBTF(int);			//Brings a figure to the front then resorts the FigList
	void SortSTB(int);			//Sends a figure to the back then resorts the FigList

	// -- Interface Management Functions -- //

	Input *GetInput() const;		//Return pointer to the input
	Output *GetOutput() const;		//Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	
};

#endif