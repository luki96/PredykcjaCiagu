#include "Runner.h"


Runner::Runner(void)
{
	this->controller = new Controller;
}


Runner::~Runner(void)
{
	delete this->controller;
}

void Runner::RunProgram()
{
	this->controller->Run();
}
