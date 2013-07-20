#pragma once
#include <vector>

/** Interfejs umożliwiający zapis do pliku */
class IWritable
{
public:
	public:

	/** Konstruktor interfejsu */
	IWritable(void);

	/** Wirtualny destruktor interfejsu  */
	virtual ~IWritable(void);

	/** Metoda czysto wirtualna za pomoca ktorej bedzie mozliwy zapis do pliku
	*/
	virtual void WriteFile(std::string fileName, std::vector<double> dataToFile) = 0;

};

