#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Runner\Runner.h"

using namespace std;

/** Glowna klasa programu */
int main (int argc, char* argv[])
{
	Runner* runner = new Runner;
	runner->RunProgram();
	delete runner;
	_CrtDumpMemoryLeaks();
	return 0;
}