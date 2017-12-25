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
//Save function for Line ,Read all the parameters 
void CLine::Save(ofstream &OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);
	OutFile << line << '\t' << ID << '\t' << start.x << '\t' << start.y << '\t' << end.x << '\t' << end.y << '\t' << DrawClr << '\t' << endl;
}
//Load function for Line ,Read all the parameters 
void CLine::Load(ifstream &InFile)
{
	//loading the parameters with a specific format
	string DrawClr;
	InFile >> ID >> start.x >> start.y >> end.x >> end.y;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = getColorObject(DrawClr);
	FigGfxInfo.BorderWdth = UI.PenWidth;

}
CFigure* CLine::copy()
{
	return new CLine(*this);
}
CFigure* CLine::paste(int transX,int transY)
{
	start.x += transX;
	start.y += transY;
	end.x += transX;
	end.y += transY;
	return new CLine(*this);
}

Point CLine::highestPoint()
{
	return GetHighestPoint(start,end);
}

//Sets x and y to the center point coordinates
void CLine::getCenter(double &x, double& y)
{
	x = (start.x + end.x) / 2.0;
	y = (start.y + end.y) / 2.0;
}
//Rotates the figure 90 degrees clockwise
void CLine::Rotate() {
	double CenterX, CenterY, newX, newY;
	//Gets the center point coordinates (Point not used as it holds int values)
	getCenter(CenterX, CenterY);
	//Compute new coordinates for Corner 1
	newX = CenterY - start.y + CenterX;
	newY = start.x - CenterX + CenterY;
	start.x = round(newX);
	start.y = round(newY);
	//Compute new coordinates for Corner 2
	newX = CenterY - end.y + CenterX;
	newY = end.x - CenterX + CenterY;
	end.x = round(newX);
	end.y = round(newY);
}
