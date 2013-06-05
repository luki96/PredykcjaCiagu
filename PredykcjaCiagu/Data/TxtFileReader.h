#pragma once
#include <string>
#include <vector>
#include "..\Interfaces\IReadable.h"

class TxtFileReader : public IReadable
{
private:

	std::vector<std::string> data;

public:
	TxtFileReader(void);
	virtual ~TxtFileReader(void);
	virtual bool ReadFile(std::string path);
};

