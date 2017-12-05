#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsOnFig(int x, int y) const {

	//Checks if the x & y coordinates lie inside/on the rectangle
	return ((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x))
		&& ((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y));
}

void CRectangle::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Rectangle, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Length: "
		+ to_string(abs(Corner1.x - Corner2.x)) + ", Width: " + to_string(abs(Corner1.y - Corner2.y));
	pOut->PrintMessage(message);
}
CFigure* CRectangle::copy()
{
	return new CRectangle(*this);
	//CFigure*f;
	//f=this;
	//return f;
}
CFigure* CRectangle::paste(Point P)
{
	if (Corner1 == GetHighestPoint(Corner1, Corner2)) {
		int transX = P.x - Corner1.x;
		int transY = P.y - Corner1.y;
		Corner1 = P;
		Corner2.x += transX;
		Corner2.y += transY;
	}
	else {
		int transX = P.x - Corner2.x;
		int transY = P.y - Corner2.y;
		Corner2 = P;
		Corner1.x += transX;
		Corner1.y += transY;
	}
	return this;
}