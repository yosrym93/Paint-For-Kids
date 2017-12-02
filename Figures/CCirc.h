#pragma once
#include "CFigure.h"

class CCirc :public CFigure
{
private:
	Point Center;
	Point Edge;
public:
	CCirc(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsOnFig(int, int) const;
};