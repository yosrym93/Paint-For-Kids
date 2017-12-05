#include "CLine.h"

CLine::CLine()
{
}


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

bool CLine::IsOnFig(int x, int y) const
{
	//Creates a point P(x,y) to use in CalcDistance
	Point P;
	P.x = x; 
	P.y = y;
	//Calculate distances AB, AP, and PB, where A and B are the start and the end respectively
	double AB = CalcDistance(start,end);
	double AP = CalcDistance(start,P);
	double PB = CalcDistance(end, P);
	//P is on the line if AB = (AP+PB) , 0.25 is an error margin
	return (abs(AB - (AP + PB)) <= 0.25);
}

void CLine::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Line, ID: " + to_string(ID) + ", Corner 1: (" + to_string(start.x) + "," + to_string(start.y)
		+ "), Corner 2: (" + to_string(end.x) + "," + to_string(end.y) + "), Length: "
		+ to_string(int(CalcDistance(start,end)));
	pOut->PrintMessage(message);
}

void CLine::Save(ofstream &OutFile)
{
	string DrawClr = getColorName(FigGfxInfo.DrawClr);
	OutFile << line << '\t' << ID << '\t' << start.x << '\t' << start.y << '\t' << end.x << '\t' << end.y << '\t' << DrawClr << '\t' << endl;
}
void CLine::Load(ifstream &InFile)
{
	string DrawClr;
	InFile >> ID >> start.x >> start.y >> end.x >> end.y;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = getColorObject(DrawClr);
	//FigGfxInfo.isFilled = false;
	FigGfxInfo.BorderWdth = UI.PenWidth;

}
CFigure* CLine::copy()
{
	return new CLine(*this);
	/*CFigure*f;
	f = this;
	return f;*/

}
CFigure* CLine::paste(Point P)
{
	if (start == GetHighestPoint(start, end)) {
		int transX = P.x - start.x;
		int transY = P.y - start.y;
		start = P;
		end.x += transX;
		end.y += transY;
	}
	else {
		int transX = P.x - end.x;
		int transY = P.y - end.y;
		end = P;
		start.x += transX;
		start.y += transY;
	}

	return this;
}