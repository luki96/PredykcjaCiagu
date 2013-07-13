#include "DataConverter.h"
using namespace std;

DataConverter::DataConverter(void) : DIVISIOR(1000)
{
}


DataConverter::~DataConverter(void)
{
}



void DataConverter::ConvertDataToSigmoidFunctionRange(std::vector<int> data)
{
	unsigned int size = data.size();
	for (unsigned int i = 0; i < size; i++)
	{
		double tmpData = data.at(i);
		tmpData /= this->DIVISIOR;
		this->convertedData.push_back(tmpData); 
	}
}


double DataConverter::ConvertData(double data)
{
	data = 1/(1 + exp(-(data)));

	return data;
}