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
	double radius = sqrt((Center.x - Edge.x)*(Center.x - Edge.x)+ (Center.y - Edge.y)*(Center.y - Edge.y));
	return (radius >= sqrt((Center.x - x)*(Center.x - x) + (Center.y - y)*(Center.y - y)));
}

void CCirc::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Circle, ID: " + to_string(ID) + ", Center (" + to_string(Center.x) + "," + to_string(Center.y)
		+ "), Radius: " + to_string(int(sqrt((Center.x - Edge.x)*(Center.x - Edge.x) + (Center.y - Edge.y)*(Center.y - Edge.y))));
	pOut->PrintMessage(message);
}