#include "CRectangle.h"

CRectangle::CRectangle() {}


CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsOnFig(int x, int y) const {

	//Checks if the x & y coordinates lie inside/on the rectangle
	return ((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x))
		&& ((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y));
}

void CRectangle::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Rectangle, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Length: "
		+ to_string(abs(Corner1.x - Corner2.x)) + ", Width: " + to_string(abs(Corner1.y - Corner2.y));
	pOut->PrintMessage(message);
}
CFigure* CRectangle::copy()
{
	return new CRectangle(*this);

}
CFigure* CRectangle::paste(int transX, int transY)
{
	Corner1.x += transX;
	Corner1.y += transY;
	Corner2.x += transX;
	Corner2.y += transY;
	return new CRectangle (*this);
}
Point CRectangle::highestPoint()
{
	return GetHighestPoint(Corner1,Corner2);
}

//Save function for Rectangle ,Read all the parameters 
void CRectangle::Save(ofstream &OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);

	OutFile << rect << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t' << DrawClr << '\t';
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
//Load function for Rectangle ,Read all the parameters 
void CRectangle::Load(ifstream&InFile)
{
	//loading the parameters with a specific format
	string DrawClr;
	string FillClr;
	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = getColorObject(DrawClr);
	InFile >> FillClr;
	//if filled set the fill clr
	if (FillClr=="NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorObject(FillClr);
	}
	FigGfxInfo.BorderWdth = UI.PenWidth;
}
//Sets x and y to the center point coordinates
void CRectangle::getCenter(double &x, double& y)
{
	x = (Corner1.x + Corner2.x) / 2.0;
	y = (Corner1.y + Corner2.y) / 2.0;
}
//Rotates the figure 90 degrees clockwise
void CRectangle::Rotate() {
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
}

