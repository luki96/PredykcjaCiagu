#pragma once
#include <string>
#include <vector>

/** Interfejs umozliwiajacy odczyt danych z pliku */
class IReadable
{
public:

	/** Konstruktor interfejsu IReadable */
	IReadable(void);

	/** Wirtualny destruktor interfejsu IReadable */
	virtual ~IReadable(void);

	/** Metoda czysto wirtualna za pomoca ktorej bedzie mozliwy odczyt pliku
	@param std::string path Sciezka do pliku
	@return true, gdy plik zostal poprawnie odczytany.
	W przeciwnym wypadku wartoscia zwracana jest false
	*/
	virtual bool ReadFile(std::string path) = 0;

	/** Czysto wirtualny getter dla tablicy, w ktorej znajduje sie wczytany plik
	@return std::vector<int> tablica zawierajaca zawartosc wczytanego pliku
	*/
	virtual std::vector<double> GetData() = 0;

};
