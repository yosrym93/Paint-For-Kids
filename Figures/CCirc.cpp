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
//Save function for circle ,Read all the parameters 
void CCirc::Save(ofstream &OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);
	OutFile << circ << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t' << Edge.x << '\t' << Edge.y << '\t' << DrawClr << '\t';
	//if filled save the fill clr
	if (FigGfxInfo.isFilled == true)
	{
		string FillClr = getColorName(FigGfxInfo.FillClr);
		OutFile << FillClr << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
//Load function for circle ,Read all the parameters 
void CCirc::Load(ifstream&InFile)
{
	//loading the parameters with a specific format
	string DrawClr;
	string FillClr;
	InFile >> ID >> Center.x >> Center.y >> Edge.x >> Edge.y;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = getColorObject(DrawClr);
	InFile >> FillClr;
	//if filled set the fill clr
	if (FillClr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorObject(FillClr);
	}
	///set the border width and calc the radius
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
CFigure* CCirc::paste(int transX, int transY)
{
	Center.x += transX;
	Center.y += transY;
	Edge.x += transX;
	Edge.y += transY;
	return new CCirc(*this);
}

Point CCirc::highestPoint()
{
	Point HP;
	HP.x = Center.x;
	HP.y = Center.y - Radius;
	return HP;
}
