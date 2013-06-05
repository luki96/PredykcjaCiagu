#pragma once
#include "..\UI\ConsoleMenu.h"

/** Klasa odpowiada za interfejs aplikacji */
class GUI
{
private:

	/** Prywatny wskaznik do obiektu klasy ConsoleMenu */
	ConsoleMenu* consoleMenu;

	/** Ilosc opcji dostepnych w menu glownym programu */
	int numberOfMenuOptions;

public:

	/** Bezargumentowy konstruktor klasy GUI */
	GUI(void);

	/** Wirtualny destruktor klasy GUI */
	virtual ~GUI(void);

	/** Metoda wyswietla menu glowne programu */
	void PrintApplicationMenu();

	/** Getter dla pola numberOfMenuOptions
	@return Ilosc opcji dostepnych w menu glownym programu
	*/
	int GetNumberOfMenuOptions()
	{
		return numberOfMenuOptions;
	}
};

