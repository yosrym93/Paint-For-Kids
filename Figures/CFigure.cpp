#include "CFigure.h"

CFigure::CFigure()
{
	Selected = false;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }
//Sends color info to playmode
GfxInfo CFigure::GetGfxInfo() const
{
	return FigGfxInfo;
}

void CFigure::SetID(int id)
{
	ID = id;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::getColorName(color name)const
{

	if (name == RED)
	{
		return "RED";
	}

	if (name == BLACK)
	{
		return "BLACK";
	}

	if (name == BLUE)
	{
		return "BLUE";
	}

	if (name == GREEN)
	{
		return "GREEN";
	}

	if (name == WHITE)
	{
		return "WHITE";
	}
}

color CFigure::getColorObject(string name)const
{
	if (name == "RED")
	{
		return RED;
	}

	if (name == "BLACK")
	{
		return BLACK;
	}

	if (name == "BLUE")
	{
		return BLUE;
	}

	if (name == "GREEN")
	{
		return GREEN;
	}

	if (name == "WHITE")
	{
		return WHITE;
	}

}
CFigure::~CFigure()
{
}