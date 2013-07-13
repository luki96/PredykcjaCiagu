#include "Controller.h"


Controller::Controller(void)
{
	this->gui = new GUI;
	this->consoleMenuListener = new ConsoleMenuListener;
	this->fileManager = new FileManager;
	this->network = new NetworkManager();
}


Controller::~Controller(void)
{
	delete this->gui;
	delete this->consoleMenuListener;
	delete this->fileManager;
}

void Controller::Run()
{
	gui->PrintApplicationMenu();
	int result = consoleMenuListener->ListenForKey(gui->GetNumberOfMenuOptions());

	switch(result)
	{
		case 0:
			{
				exit(0);
				break;
			}
		case 1:
			{
				this->fileManager->ireader->ReadFile("a.txt");
//				this->dataConverter->ConvertDataToSigmoidFunctionRange(this->fileManager->ireader->GetData());
				this->network->RunNetwork();
			}
		default:
			break;
	}
}
