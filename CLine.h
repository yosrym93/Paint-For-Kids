#pragma once

#include"Figures\CFigure.h"
class CLine :public CFigure
{
private:
	Point start;
	Point end;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output*)const;
	virtual bool IsOnFig(int, int) const;
};