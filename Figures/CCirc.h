#pragma once
#include "CFigure.h"

class CCirc :public CFigure
{
private:
	Point Center;
	Point Edge;
	double Radius;
public:
	CCirc();
	CCirc(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsOnFig(int, int) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual CFigure* copy();
	virtual CFigure* paste(int, int);
	virtual Point highestPoint();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	~CCirc();
};