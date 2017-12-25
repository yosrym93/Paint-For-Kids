#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool PlayHidden;		//hides figures in playmode.

	double CalcDistance(Point, Point) const; //utility function to measure the length between two points

public:
	//default constructor 
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	GfxInfo GetGfxInfo()const;	//returns info about the figure to play mode.
	void SetID(int id);				//Sets ID to figure's index in FigList.
	int GetID() const;				//Gets the ID of the figure
	void Hide();					//Hides figures in playmode.
	void Show();					//Shows figures in playmode.
	bool HiddenStatus();			//Shows Current Figure status in playmode.

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool IsOnFig(int, int) const = 0;  //Checks if a given point is on the figure
	Point GetHighestPoint(Point A, Point B);
	Point GetHighestPoint(Point A, Point B, Point C);
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	string getColorName(color)const;// return string of the color 
	color getColorObject(string)const;
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar
	virtual CFigure* copy() = 0; //Copy figure
	virtual CFigure* paste(int, int) = 0;	//Paste figure
	virtual Point highestPoint() = 0;	//Returns the highest point on the figure
	virtual void Rotate() {};
	virtual ~CFigure();
};

#endif