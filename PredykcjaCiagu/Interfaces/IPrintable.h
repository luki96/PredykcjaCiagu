#pragma once
#include <string>

/** Interfejs umo¿liwiaj¹cy wyœwietlanie danych na ekranie */
class IPrintable
{
public:
	IPrintable(void);

	/** Wirtualny destruktor interfejsu IPrintable */
	virtual ~IPrintable(void);
	
	/** 
	Metoda czysto wirtualna za pomoc¹ której bêd¹ wyœwietlane dane 
	@param message Dane, które maj¹ zostaæ wyœwietlone
	*/
	virtual void Print(std::string message) = 0;
};

