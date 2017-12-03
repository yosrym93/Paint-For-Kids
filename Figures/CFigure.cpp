#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

//Sets the figure "selected" state

void CFigure::SetSelected(bool s)
{	Selected = s; }

//Returns the figure's "selected" state

bool CFigure::IsSelected() const
{	return Selected; }

//Sends color info to playmode

GfxInfo CFigure::GetGfxInfo() const
{
	return FigGfxInfo;
}

//Sets the figure ID

void CFigure::SetID(int id)
{
	ID = id;
}

//Gets the figure ID

int CFigure::GetID() const
{
	return ID;
}

//Changes the figure's drawing color

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

//Changes the figure's fill color

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}



