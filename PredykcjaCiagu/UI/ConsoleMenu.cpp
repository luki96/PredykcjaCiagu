#include "ConsoleMenu.h"
using namespace std;

ConsoleMenu::ConsoleMenu(void)
{
	this->menuOptions.push_back("1. Predykcja kolejnego wyrazu ciagu");
	this->menuOptions.push_back("0. Zakoncz program");
}


ConsoleMenu::~ConsoleMenu(void)
{
}

void ConsoleMenu::PrintMenu()
{
	for (unsigned int i = 0; i < menuOptions.size(); i++)
	{
		Print(menuOptions[i]);
	}
}

void ConsoleMenu::Print(string message)
{
	cout << message << endl;
}
