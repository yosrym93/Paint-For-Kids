#include"CTrig.h"

CTrig::CTrig() {}

CTrig::CTrig(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure (FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
void CTrig::Draw(Output* pOut) const 
{
	//Call Output::DrawTrig to draw a triangle on the screen	
	pOut->DrawTrig(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
bool CTrig::IsOnFig(int x, int y) const
{
	int x1 = Corner1.x;
	int y1 = Corner1.y;
	int x2 = Corner2.x;
	int y2 = Corner2.y;
	int x3 = Corner3.x;
	int y3 = Corner3.y;

	/* Calculate area of triangle ABC */
	float A = Area(x1, y1, x2, y2, x3, y3);

	/* Calculate area of triangle PBC */
	float A1 = Area(x, y, x2, y2, x3, y3);

	/* Calculate area of triangle PAC */
	float A2 = Area(x1, y1, x, y, x3, y3);

	/* Calculate area of triangle PAB */
	float A3 = Area(x1, y1, x2, y2, x, y);

	/* Check if sum of A1, A2 and A3 is same as A */
	//Creates a point P(x,y) to use in CalcDistance
	Point P;
	P.x = x;
	P.y = y;

	bool L1 = isOnBorder(Corner1, Corner2, P);
	bool L2 = isOnBorder(Corner1, Corner3, P);
	bool L3 = isOnBorder(Corner2, Corner3, P);
	return (A == A1 + A2 + A3) || L1 || L2 || L3;
}


// A utility function to calculate area of triangle formed by (x1, y1), (x2, y2) and (x3, y3) 

float CTrig::Area(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

// A utility function to check if Point (x,y) lies on the line between (x1,y1) and (x2,y2)

bool CTrig::isOnBorder(Point A, Point B, Point P) const {
	//Calculate distances AB, AP, and PB, where A and B are the start and the end respectively
	double AB = CalcDistance(A, B);
	double AP = CalcDistance(A, P);
	double PB = CalcDistance(B, P);
	//P is on the line if AB = (AP+PB) , 0.35 is an error margin
	return (abs(AB - (AP + PB)) <= 0.35);
}

void CTrig::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Triangle, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Corner 3: (" + to_string(Corner3.x) 
		+ "," + to_string(Corner3.y) + ")";
	pOut->PrintMessage(message);
}

//Save function for Triangle,Read all the parameters 
void CTrig::Save(ofstream &OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);
	OutFile << trig << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t' << Corner3.x << '\t' << Corner3.y << '\t' << DrawClr << '\t';
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
//Load function for Triangle ,Read all the parameters 
void CTrig::Load(ifstream&InFile)
{
	//loadding the parameters with a specific format
	string DrawClr;
	string FillClr;
	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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
	FigGfxInfo.BorderWdth = UI.PenWidth;

}
CFigure* CTrig::copy()
{
	return new CTrig(*this);
}
CFigure* CTrig::paste(int transX,int transY)
{
	Corner1.x += transX;
	Corner2.x += transX;
	Corner3.x += transX;
	Corner1.y += transY;
	Corner2.y += transY;
	Corner3.y += transY;
	return new CTrig(*this);
}

Point CTrig::highestPoint()
{
	return GetHighestPoint(Corner1,Corner2,Corner3);
}
//Sets x and y to the center point coordinates
void CTrig::getCenter(double &x, double& y)
{
	x = (Corner1.x + Corner2.x + Corner3.x) / 3.0;
	y = (Corner1.y + Corner2.y + Corner3.y) / 3.0;
}
//Rotates the figure 90 degrees clockwise
void CTrig::Rotate() {
	double CenterX, CenterY, newX, newY;
	//Gets the center point coordinates (Point not used as it holds int values)
	getCenter(CenterX, CenterY);
	//Compute new coordinates for Corner 1
	newX = CenterY - Corner1.y + CenterX;
	newY = Corner1.x - CenterX + CenterY;
	Corner1.x = round(newX);
	Corner1.y = round(newY);
	//Compute new coordinates for Corner 2
	newX = CenterY - Corner2.y + CenterX;
	newY = Corner2.x - CenterX + CenterY;
	Corner2.x = round(newX);
	Corner2.y = round(newY);
	//Compute new coordinates for Corner 3
	newX = CenterY - Corner3.y + CenterX;
	newY = Corner3.x - CenterX + CenterY;
	Corner3.x = round(newX);
	Corner3.y = round(newY);
}

