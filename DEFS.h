#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRIG,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,  //Change the filling color
	
	SELECT,			//Select a figure(s)
	DEL,			//Delete a figure(s)
	COPY,			//Copy a figure(s)
	CUT,			//Cut a figure(s)
	PASTE,			//Paste a figure(s)
	ROTATE,			//Rotate a figure(s)
	BTF,			//Bring to front
	STB,			//Send to back
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	TO_PLAY,		//Switch interface to Play mode
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	
	P_H_TYPE,		//Pick and hide, by type
	P_H_COLOR,		//Pick and hide, by color
	P_H_BOTH,		//Pick and hide, by type and color

	SET_BLACK,		//pick black color
	SET_WHITE,		//pick white color
	SET_RED,		//pick red color
	SET_GREEN,		//pick green color
	SET_BLUE,		//pick blue color
};

struct Point	//To be used for figures points
{ int x,y; 
//Operator == for Points
bool operator== (Point A) {
	return ((x == A.x) && (y == A.y));
}
};



struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

enum shape
{
	line,
	rect,
	trig,
	circ,
};

#endif