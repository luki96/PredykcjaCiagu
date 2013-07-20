#include "TxtFileWriter.h"


TxtFileWriter::TxtFileWriter(void)
{
}


TxtFileWriter::~TxtFileWriter(void)
{
}

void TxtFileWriter::WriteFile(std::string fileName, std::vector<double> dataToFile)
{
	file.open( fileName, std::ios::out);
	if (file.good() == true)
	{
		//file.clear();

		for (int i = 0; i < dataToFile.size(); i++)
		{
			file << dataToFile[i];
			file << std::endl;
		}
		file.close();
	}
}