#pragma once
#include"Action.h"
#include "fstream"


class LoadAction :public Action
{
private:
	ifstream InputFile;
	string fileName;
	//utility function to get the name of the color in color type
	color getColorObject(string)const;
public:
	LoadAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
