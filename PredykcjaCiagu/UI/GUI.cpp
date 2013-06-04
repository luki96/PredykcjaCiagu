#include "GUI.h"


GUI::GUI(void)
{
	this->consoleMenu = new ConsoleMenu;
	this->numberOfMenuOptions = consoleMenu->GetSizeOfMenuOptions();
}


GUI::~GUI(void)
{
	delete this->consoleMenu;
}

void GUI::PrintApplicationMenu()
{
	this->consoleMenu->PrintMenu();
}
