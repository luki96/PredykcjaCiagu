#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "..\Interfaces\IWritable.h"

/** Klasa s³u¿aca do zapisywania wyników w pliku tekstowym */
class TxtFileWriter: public IWritable
{

private: 	
	/** Zmienna plikowa */
	std::fstream file;

public:
	/** Konstruktor bezargumentowy */
	TxtFileWriter(void);

	/** Destruktor bezargumentowy */ 
	virtual ~TxtFileWriter(void);

	/** Metoda do zapisu do pliku (definicja do metody z interfejsu) */
	virtual bool WriteFile(std::string fileName, std::vector<double> dataToFile);
};

