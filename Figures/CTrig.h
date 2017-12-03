#pragma once
#include "CFigure.h"

class CTrig : public CFigure
{
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTrig(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsOnFig(int, int) const;
	float Area(int, int, int, int, int, int) const;
	bool isOnLine(int, int, int, int, int, int) const;
	virtual void PrintInfo(Output* pOut) const;
};