#pragma once
#include <vector>

/** Interfejs umo¿liwiaj¹cy zapis do pliku */
class IWritable
{
public:
	public:

	/** Konstruktor interfejsu */
	IWritable(void);

	/** Wirtualny destruktor interfejsu  */
	virtual ~IWritable(void);

	/** Metoda czysto wirtualna za pomoca ktorej bedzie mozliwy zapis do pliku
	@param std::string path Œcie¿ka do pliku
	@param std::vector<double> dataToFile Dane, które nale¿y zapisaæ
	@return true, gdy plik zostal poprawnie odczytany.
	W przeciwnym wypadku wartoscia zwracana jest false
	*/
	virtual bool WriteFile(std::string path, std::vector<double> dataToFile) = 0;

};

