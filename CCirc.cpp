#include "CCirc.h"


CCirc::CCirc(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Edge = P2;
}

void CCirc::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Center, Edge, FigGfxInfo, Selected);
}
bool CCirc::IsOnFig(int x, int y) const
{
	//to check if the point in the circle wa check the distance between center and the point if it is within the range
	double radius = abs(Center.x - Edge.x);
	return (radius >= abs(x - Center.x));
}