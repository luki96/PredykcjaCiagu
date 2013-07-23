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
	delete this->network;
}

void Controller::Run()
{
	while(true)
	{
		gui->PrintApplicationMenu();
		int result = consoleMenuListener->ListenForKey(gui->GetNumberOfMenuOptions());

		switch(result)
		{
			case 0:
				{
					this->gui->ClearScreen();
					this->gui->PrintMessage("Program zakonczy dzialanie.");
					this->gui->PauseProgram();
					exit(0);
					break;
				}
			case 1:
				{
					this->gui->ClearScreen();
					std::ostringstream stringResult;
					this->fileManager->ireader->ReadFile("a.txt");
					this->network->RunNetwork();
					double result = this->network->GetFinalResult();
					stringResult << result;
					this->gui->PrintMessage("Kolejnym wyrazem ciagu jest " + stringResult.str() + ".");
					this->gui->PauseProgram();
					this->gui->ClearScreen();
					break;
				}
			default:
				this->gui->ClearScreen();
				this->gui->PrintMessage("Wybrano niepoprawna opcje.");
				this->gui->PauseProgram();
				this->gui->ClearScreen();
				break;
		}
	}
}
