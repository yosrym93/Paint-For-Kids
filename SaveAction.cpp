#include"SaveAction.h"
#include "../paintforkids/ApplicationManager.h"

#include "../paintforkids/GUI/Input.h"
#include "../paintforkids/GUI/output.h"

SaveAction::SaveAction(ApplicationManager *pApp) :Action(pApp)
{
}
void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the name of the file without spaces ");


	fileName = pIn->GetSrting(pOut) + ".txt";
	//Clear the status bar
	OutFile.open(fileName);

	pOut->PrintMessage("Your file has been Successfully Saved");
}

void SaveAction::Execute()
{
	ReadActionParameters();
	if (OutFile.is_open())
	{
		int numberOfFiguers = pManager->getFigCount();
		string DrawClr = getColorName(UI.DrawColor);
		OutFile << DrawClr;
		string FillClr = getColorName(UI.FillColor);
		OutFile << '\t' << FillClr << endl;
		OutFile << numberOfFiguers << endl;
		pManager->SaveAll(OutFile);
		OutFile.close();
	}
}
//utility fn to return a string of the color 
string SaveAction::getColorName(color a)const
{

	if (a == RED)
	{
		return "RED";
	}

	if (a == BLACK)
	{
		return "BLACK";
	}

	if (a == BLUE)
	{
		return "BLUE";
	}

	if (a == GREEN)
	{
		return "GREEN";
	}

	if (a == WHITE)
	{
		return "WHITE";
	}
	return "NO";
}