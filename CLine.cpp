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

bool CLine:: IsOnFig(int x, int y) const
{
	/// saybha le yosry m5tsh baly enha tab3k ;)
	//to check if the point is on figure we calculate the slope and compare with it
	double slope;
	slope =  (end.y - start.y) / (end.x - start.x);
	double c = start.y - (slope*start.x);
	//return (slope == (end.y - y) / (end.x - x));
	return (y == (slope*x + c));
}