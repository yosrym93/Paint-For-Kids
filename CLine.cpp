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