#pragma once
#include <string>

/** Interfejs umozliwiajacy wyswietlanie danych na ekranie */
class IPrintable
{
public:
	IPrintable(void);

	/** Wirtualny destruktor interfejsu IPrintable */
	virtual ~IPrintable(void);
	
	/** 
	Metoda czysto wirtualna za pomoca ktorej beda wyswietlane dane 
	@param message Dane, ktore maja zostac wyswietlone
	*/
	virtual void Print(std::string message) = 0;
};

