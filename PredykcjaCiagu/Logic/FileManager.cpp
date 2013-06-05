#include "FileManager.h"


FileManager::FileManager(void)
{
	this->ireader = new TxtFileReader;
}


FileManager::~FileManager(void)
{
	delete this->ireader;
}
