
#include"CTrig.h"

CTrig::CTrig(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure (FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
void CTrig::Draw(Output* pOut) const 
{
	//Call Output::DrawTrig to draw a triangle on the screen	
	pOut->DrawTrig(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
bool CTrig::IsOnFig(int, int) const
{
	///empty
	return true;
}