#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1315;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 72;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = MILKYWHITE;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 4;	//width of the figures frames
	UI.isFilled = false;

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem

	string MenuItemImages[DRAW_ITM_COUNT];
	
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_TRIG] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\drawcolor1.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\fillcolor.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\rotate.jpg";
	MenuItemImages[ITM_BTF] = "images\\MenuItems\\bringtofront.jpg";
	MenuItemImages[ITM_STB] = "images\\MenuItems\\sendtoback.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_TO_PLAY] = "images\\MenuItems\\Menu_play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 5);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;

	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0,0, UI.width, UI.height - UI.ToolBarHeight);

	string MenuItemImages2[PLAY_ITM_COUNT];
	
	MenuItemImages2[ITM_P_H_TYPE] = "images\\MenuItems\\Pickbyshape.jpg";
	MenuItemImages2[ITM_P_H_COLOR] = "images\\MenuItems\\Pickbycolor.jpg";
	MenuItemImages2[ITM_P_H_BOTH] = "images\\MenuItems\\Pickbyboth.jpg";
	MenuItemImages2[ITM_TO_DRAW] = "images\\MenuItems\\ToDraw.jpg";
	MenuItemImages2[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages2[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 5);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateColorToolBar() const
{
	UI.InterfaceMode = MODE_COLOR;

	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.height - UI.ToolBarHeight);

	string MenuItemImages2[COLOR_ITM_COUNT];
	
	MenuItemImages2[ITM_BLACK] = "images\\MenuItems\\Black.jpg";
	MenuItemImages2[ITM_WHITE] = "images\\MenuItems\\White.jpg";
	MenuItemImages2[ITM_RED] = "images\\MenuItems\\Red.jpg";
	MenuItemImages2[ITM_GREEN] = "images\\MenuItems\\Green.jpg";
	MenuItemImages2[ITM_BLUE] = "images\\MenuItems\\Blue.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i<COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages2[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 5);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + 5 , UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

bool Output::getIsFilled() const {
	return UI.isFilled;
}

void Output::setCrntDrawColor(color c) {
	UI.DrawColor = c;
}

void Output::setCrntFillColor(color c) {
	UI.FillColor = c;
}

void Output::setIsFilled(bool isF) {
	UI.isFilled = isF;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const //modified to implement the drawcirc function
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = CircGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);
	drawstyle style;
	if (CircGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	float radius=sqrt((P1.x-P2.x)*(P1.x-P2.x) + (P1.y-P2.y)*(P1.y-P2.y));
	
	pWind->DrawCircle(P1.x, P1.y,radius, style);
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = LineGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);
	drawstyle style;
	style = FRAME;
	pWind->DrawLine(P1.x,P1.y,P2.x,P2.y,style);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Output::DrawTrig(Point P1, Point P2, Point P3, GfxInfo TrigGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TrigGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TrigGfxInfo.BorderWdth);
	drawstyle style;
	if (TrigGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TrigGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

