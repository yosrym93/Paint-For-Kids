#pragma once
#include "Action.h"
#include<fstream>


class SaveAction :public Action
{
	ofstream OutFile;
	string fileName;
	//utility fuction to get the name of the color in string type
	string getColorName(color)const;

public:
	SaveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
};
