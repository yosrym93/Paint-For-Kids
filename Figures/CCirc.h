#pragma once
#include "CFigure.h"

class CCirc :public CFigure
{
private:
	Point Center;
	Point Edge;
	double Radius;
public:
	CCirc(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsOnFig(int, int) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual CFigure* copy();
	virtual CFigure* paste(Point);
};