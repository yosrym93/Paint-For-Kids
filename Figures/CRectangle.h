#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsOnFig(int, int) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual CFigure* copy();
	virtual CFigure* paste(int, int);
	virtual Point highestPoint();
	virtual void getCenter(double&, double&);
	virtual void Rotate();
};

#endif