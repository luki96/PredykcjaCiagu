#include "TxtFileReader.h"
using namespace std;

TxtFileReader::TxtFileReader(void)
{
}


TxtFileReader::~TxtFileReader(void)
{
}

bool TxtFileReader::ReadFile(string path)
{
	int tmpData;
	file.open(path, ios::in);
	if (file.good())
	{
		while (!file.eof())
		{
			file >> tmpData;
			this->data.push_back(tmpData);
		}
		file.close();
		return true;
	}
	return false;
}
