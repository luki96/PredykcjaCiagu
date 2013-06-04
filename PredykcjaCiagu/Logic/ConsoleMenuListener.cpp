#include "ConsoleMenuListener.h"
using namespace std;

ConsoleMenuListener::ConsoleMenuListener()
{
}


ConsoleMenuListener::~ConsoleMenuListener(void)
{
}

bool ConsoleMenuListener::ValidateKey(int key, int numberOfMenuOptions)
{
	// isdigit sprawdza czy znak podany jako argument jest liczb¹ czy nie 
	if ( (!isdigit(key)) || (key > numberOfMenuOptions - 1) )
		return false;
	else
		return true;
}

int ConsoleMenuListener::ListenForKey(int numberOfMenuOptions)
{
	char key;
	while(true)
	{
		cin >> key;
		bool result = ValidateKey(key, numberOfMenuOptions);
		if (result == true)
			break;
	}
	return key;
}
