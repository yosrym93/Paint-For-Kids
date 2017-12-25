#include"SaveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"

SaveAction::SaveAction(ApplicationManager *pApp) :Action(pApp)
{
}
//Read the parameters for the save action 
void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the name of the file without spaces ");


	fileName = pIn->GetSrting(pOut) + ".txt";
	//Clear the status bar
	OutFile.open(fileName);
	//check if the file is opened
	if (OutFile.is_open())
	{
		pOut->PrintMessage("Your file has been Successfully Saved");
	}
	else {
		pOut->PrintMessage("Unable to save file");
	}
}

void SaveAction::Execute()
{
	ReadActionParameters();
	//check if the file is opened
	if (OutFile.is_open())
	{
		//save in the file the current draw clr & fill clr & number of figuers 
		int numberOfFiguers = pManager->getFigCount();
		string DrawClr = getColorName(UI.DrawColor);
		OutFile << DrawClr;
		string FillClr = getColorName(UI.FillColor);
		OutFile << '\t' << FillClr << endl;
		OutFile << numberOfFiguers << endl;
		//calling the function saveAll in the application manager that have the access to the figlist
		pManager->SaveAll(OutFile);
		//close the file after saveing
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