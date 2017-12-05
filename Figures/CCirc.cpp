#include "CCirc.h"

CCirc::CCirc() {
}

CCirc::CCirc(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Edge = P2;
	Radius = CalcDistance(Center, Edge);
}

void CCirc::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Center, Edge, FigGfxInfo, Selected);
}
bool CCirc::IsOnFig(int x, int y) const
{
	//Creates a point P(x,y) to use in CalcDistance
	Point P;
	P.x = x;
	P.y = y;
	//to check if the point in the circle wa check the distance between center and the point if it is within the range
	return (Radius >= CalcDistance(Center,P));
}

void CCirc::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Circle, ID: " + to_string(ID) + ", Center (" + to_string(Center.x) + "," + to_string(Center.y)
		+ "), Radius: " + to_string(int(Radius));
	pOut->PrintMessage(message);
}
void CCirc::Save(ofstream &OutFile)
{
	string DrawClr = getColorName(FigGfxInfo.DrawClr);
	OutFile << circ << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t' << Edge.x << '\t' << Edge.y << '\t' << DrawClr << '\t';
	if (FigGfxInfo.isFilled == true)
	{
		string FillClr = getColorName(FigGfxInfo.FillClr);
		OutFile << FillClr << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
void CCirc::Load(ifstream&InFile)
{
	string DrawClr;
	string FillClr;
	InFile >> ID >> Center.x >> Center.y >> Edge.x >> Edge.y;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = getColorObject(DrawClr);
	InFile >> FillClr;
	if (FillClr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.FillClr = getColorObject(FillClr);
	}
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Radius = CalcDistance(Center, Edge);
}
CCirc::~CCirc()
{
}
CFigure* CCirc::copy()
{
	return new CCirc(*this);
}
CFigure* CCirc::paste(Point P)
{
	if(P.y - UI.ToolBarHeight < Radius)
		P.y += Radius;
	Center = P;
	Edge.x = P.x;
	Edge.y = P.y + Radius;
	
	return this;
}