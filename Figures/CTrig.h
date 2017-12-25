#pragma once
#include "CFigure.h"

class CTrig : public CFigure
{
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTrig();
	CTrig(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsOnFig(int, int) const;
	float Area(int, int, int, int, int, int) const;
	bool isOnBorder(Point, Point, Point) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual CFigure* copy();
	virtual CFigure* paste(int, int);
	virtual Point highestPoint();
	virtual void getCenter(double&, double&);	//Sets x and y to the center point coordinates
	virtual void Rotate();		//Rotates the figure 90 degrees clockwise
};