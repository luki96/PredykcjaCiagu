#include "TxtFileWriter.h"


TxtFileWriter::TxtFileWriter(void)
{
}


TxtFileWriter::~TxtFileWriter(void)
{
}

bool TxtFileWriter::WriteFile(std::string fileName, std::vector<double> dataToFile)
{
	file.open( fileName, std::ios::out);
	if (file.good() == true)
	{
		for (unsigned int i = 0; i < dataToFile.size(); i++)
		{
			file << dataToFile[i];
			file << std::endl;
		}
		file.close();
		return true;
	}
	return false;
}