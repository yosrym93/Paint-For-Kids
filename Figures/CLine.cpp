#include "CLine.h"


CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	start = P1;
	end = P2;
}

void CLine::Draw(Output* pOut)const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(start, end, FigGfxInfo, Selected);

}

bool CLine::IsOnFig(int x, int y) const
{
	int x1 = start.x;
	int y1 = start.y;
	int x2 = end.x;
	int y2 = end.y;

	double AB = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	double AP = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
	double PB = sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y));
	if (AB - (AP + PB) <= 0.25 && AB - (AP + PB) >= -0.25)
		return true;
	else
		return false;
}

void CLine::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Line, ID: " + to_string(ID) + ", Corner 1: (" + to_string(start.x) + "," + to_string(start.y)
		+ "), Corner 2: (" + to_string(end.x) + "," + to_string(end.y) + "), Length: "
		+ to_string(int(sqrt((start.x - end.x)*(start.x - end.x) + (start.y - end.y)*(start.y - end.y))));
	pOut->PrintMessage(message);
}