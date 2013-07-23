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

	/** Implementacja metody z interfejsu IWritable 
	@param std::string fileName Œcie¿ka wraz z nazw¹ pliku
	@param std::vector<double> dataToFile Dane, które nale¿y zapisaæ
	@return true, jezeli powiedzie siê operacja otwracia i zapisu do pliku.
	W przeciwnym wypadku wartoœci¹ zwracan¹ jest false
	*/
	virtual bool WriteFile(std::string fileName, std::vector<double> dataToFile);
};

