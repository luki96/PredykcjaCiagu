#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Runner\Runner.h"

using namespace std;

/**
@mainpage
@note Projekt realizowany w ramach przedmiotu Biologicznie motywowane metody sztucznej inteligencji
@author £ukasz Kuœnierczyk
@author £ukasz Fornalczyk
@date 24.07.2013
*/

/** G³ówna klasa programu */
int main (int argc, char* argv[])
{
	Runner* runner = new Runner;
	runner->RunProgram();
	delete runner;
	_CrtDumpMemoryLeaks();
	return 0;
}