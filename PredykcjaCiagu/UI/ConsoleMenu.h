#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "..\Interfaces\IPrintable.h"

/** Klasa odpowiada za reprezentacje menu glownego programu */
class ConsoleMenu : public IPrintable
{
private:

	/** Tablica zawieraj¹ca opcje dostêpne w menu programu */
	std::vector<std::string> menuOptions;

public:

	/** Bezargumentowy konstruktor klasy ConsoleMenu */
	ConsoleMenu(void);

	/** Wirtualny destruktor klasy ConsoleMenu */
	virtual ~ConsoleMenu(void);

	/** Implementacja metody z interfejsu IPrintable 
	@param std::string message Wiadomoœæ, która ma zostaæ wyœwietlona
	*/
	virtual void Print(std::string message);

	/** Metoda wyœwietla za pomoc¹ metody print z interfejsu IPrintable menu programu */
	void PrintMenu();

	/** Getter dla pola menuOptions
	@return Rozmiar tablicy menuOptions
	*/
	int GetSizeOfMenuOptions()
	{
		return menuOptions.size();
	}
};

