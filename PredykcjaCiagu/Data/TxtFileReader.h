#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "..\Interfaces\IReadable.h"

/** Klasa odpowiada za odczyt plików tekstowych */
class TxtFileReader : public IReadable
{
private:

	/** Tablica w której bêdzie zapisana zawartoœæ wczytywanego pliku */
	std::vector<double> data;

	/** Zmienna plikowa */
	std::fstream file;

public:

	/** Konstruktor klasy TxtFileReader */
	TxtFileReader(void);
	
	/** Wirtualny destruktor klasy TxtFileReader */
	virtual ~TxtFileReader(void);

	/** Implementacja metody z interfejsu IReadable 
	@param std::string path Œcie¿ka wraz z nazw¹ pliku
	@return true, jezeli powiedzie siê operacja otwracia i odczytu pliku.
	W przeciwnym wypadku wartoœci¹ zwracan¹ jest false
	*/
	virtual bool ReadFile(std::string path);
	
	/** Implementacja gettera dla pola data z interfejsu IReadable
	@return tablica zawieraj¹ca wczytany plik z dysku
	*/
	std::vector<double> GetData()
	{
		return data;
	}
};

