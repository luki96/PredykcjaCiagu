#include "Controller.h"


Controller::Controller(void)
{
	this->gui = new GUI;
	this->consoleMenuListener = new ConsoleMenuListener;
	this->dataConverter = new DataConverter;
	this->fileManager = new FileManager;
}


Controller::~Controller(void)
{
	delete this->gui;
	delete this->consoleMenuListener;
	delete this->dataConverter;
	delete this->fileManager;
}

void Controller::Run()
{
	gui->PrintApplicationMenu();
	consoleMenuListener->ListenForKey(gui->GetNumberOfMenuOptions());
}
