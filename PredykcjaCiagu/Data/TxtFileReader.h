#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "..\Interfaces\IReadable.h"

/** Klasa odpowiada za odczyt plikow tekstowych */
class TxtFileReader : public IReadable
{
private:

	/** Tablica w ktorej bedzie zapisana zawartosc wczytywanego pliku */
	std::vector<std::string> data;

	/** Zmienna plikowa */
	std::fstream file;

public:

	/** Konstruktor klasy TxtFileReader */
	TxtFileReader(void);
	
	/** Wirtualny destruktor klasy TxtFileReader */
	virtual ~TxtFileReader(void);

	/** Implementacja metody z interfejsu IReadable 
	@param std::string path Sciezka wraz z nazwa pliku
	@return true, jezeli powiedzie sie operacja otwracia i odczytu pliku.
	W przeciwnym wypadku wartoscia zwracana jest false
	*/
	virtual bool ReadFile(std::string path);
	
	/** Getter dla pola data
	@return tablica zawierajaca wczytany plik z dysku
	*/
	std::vector<std::string> GetData()
	{
		return data;
	}
};

