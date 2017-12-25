#include "CFigure.h"

CFigure::CFigure()
{
	Selected = false;
	PlayHidden = false;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	PlayHidden = false;
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

//Hides Figures
void CFigure::Hide()
{
	PlayHidden = true;
}
//Shows Figures
void CFigure::Show()
{
	PlayHidden = false;
}
//Gives Current Status
bool CFigure::HiddenStatus()
{
	return PlayHidden;
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

Point CFigure::GetHighestPoint(Point A, Point B) {
	if (A.y < B.y)
		return A;
	return B;
}

Point CFigure::GetHighestPoint(Point A, Point B, Point C) {
	if (A.y < B.y && A.y < C.y)
		return A;
	if (B.y < C.y)
		return B;
	return C;
}

//Utility function to measure the length between two points
double CFigure::CalcDistance(Point A, Point B) const {
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
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