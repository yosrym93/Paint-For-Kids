#include"CTrig.h"

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
	bool L1 = isOnLine(x1, y1, x2, y2, x, y);
	bool L2 = isOnLine(x3, y3, x2, y2, x, y);
	bool L3 = isOnLine(x1, y1, x3, y3, x, y);
	return (A == A1 + A2 + A3) || L1 || L2 || L3;
}


// A utility function to calculate area of triangle formed by (x1, y1), (x2, y2) and (x3, y3) 

float CTrig::Area(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

// A utility function to check if Point (x,y) lies on the line between (x1,y1) and (x2,y2)

bool CTrig::isOnLine(int x1, int y1, int x2, int y2, int x, int y) const {

	double AB = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	double AP = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
	double PB = sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y));
	return (AB - (AP + PB) <= 0.35 && AB - (AP + PB) >= -0.35);
}

void CTrig::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Triangle, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Corner 3: (" + to_string(Corner3.x) 
		+ "," + to_string(Corner3.y) + ")";
	pOut->PrintMessage(message);
}