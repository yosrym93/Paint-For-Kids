#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOR	//Color Selector mode
};

enum DrawMenuItem //The items of the Draw menu 
{
	//Note: Items are ordered here as they appear in menu
	ITM_LINE,				//Line item in menu
	ITM_RECT,				//Recangle item in menu
	ITM_TRIG,				//Triangle item in menu
	ITM_CIRC,				//Circle item in menu
	ITM_CHNG_DRAW_CLR,		//Change draw color item in menu
	ITM_CHNG_FILL_CLR,		//Change fill color item in menu
	ITM_SELECT,				//Select item in menu
	ITM_DELETE,				//Delete item in menu
	ITM_COPY,				//Copy item in menu
	ITM_CUT,				//Cut item in menu
	ITM_PASTE,				//Paste item in menu
	ITM_ROTATE,				//Rotate item in menu
	ITM_BTF,				//Bring to front item in menu
	ITM_STB,				//Send to back item in menu
	ITM_SAVE,				//Save item in menu
	ITM_LOAD,				//Load item in menu
	ITM_TO_PLAY,			//To Play mode item in menu
	ITM_EXIT,				//Exit item

	DRAW_ITM_COUNT			//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	ITM_P_H_TYPE,		//Play and hide by type item in menu
	ITM_P_H_COLOR,		//Play and hide by color item in menu
	ITM_P_H_BOTH,		//Play and hide by both color and type item in menu
	ITM_TO_DRAW,		//To draw mode item in menu
	ITM_EXIT2,			//Exit item in menu
	

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};


enum ColorMenuItem //The items of the Color menu (you should add more items)
{
	ITM_BLACK,		//Black color item in menu
	ITM_WHITE,		//White color item in menu	
	ITM_RED,		//Red color item in menu
	ITM_GREEN,		//Green color item in menu
	ITM_BLUE,		//Blue color item in menu

	COLOR_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};




__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	
	bool isFilled;

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif