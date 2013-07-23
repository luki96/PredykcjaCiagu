#include "GUI.h"
using namespace std;

GUI::GUI(void)
{
	this->consoleMenu = new ConsoleMenu;
	this->numberOfMenuOptions = consoleMenu->GetSizeOfMenuOptions();
}


GUI::~GUI(void)
{
	delete this->consoleMenu;
}

void GUI::ClearScreen()
{
	system("cls");
}

void GUI::PauseProgram()
{
	system("pause");
}

void GUI::PrintApplicationMenu()
{
	this->consoleMenu->PrintMenu();
}

void GUI::PrintMessage(string message)
{
	this->consoleMenu->Print(message);
}
