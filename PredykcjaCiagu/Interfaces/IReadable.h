#pragma once
#include <string>
#include <vector>

/** Interfejs umo¿liwiaj¹cy odczyt danych z pliku */
class IReadable
{
public:

	/** Konstruktor interfejsu IReadable */
	IReadable(void);

	/** Wirtualny destruktor interfejsu IReadable */
	virtual ~IReadable(void);

	/** Metoda czysto wirtualna za pomoc¹ której bêdzie mo¿liwy odczyt pliku
	@param std::string path Œcie¿ka do pliku
	@return true, gdy plik zosta³ poprawnie odczytany.
	W przeciwnym wypadku wartoœci¹ zwracan¹ jest false
	*/
	virtual bool ReadFile(std::string path) = 0;

	/** Czysto wirtualny getter dla tablicy, w której znajduje siê wczytany plik
	@return std::vector<int> tablica zawieraj¹ca zawartoœæ wczytanego pliku
	*/
	virtual std::vector<double> GetData() = 0;

};
