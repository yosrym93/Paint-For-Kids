#pragma once

#include "CFigure.h"
class CLine :public CFigure
{
private:
	Point start;
	Point end;
public:
	CLine();
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output*)const;
	virtual bool IsOnFig(int, int) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual CFigure* copy();
	virtual CFigure* paste(Point);
};