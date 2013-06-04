#pragma once
#include "..\UI\ConsoleMenu.h"

/** Klasa odpowiada za interfejs aplikacji */
class GUI
{
private:

	/** Prywatny wskaznik do obiektu klasy ConsoleMenu */
	ConsoleMenu* consoleMenu;

	int numberOfMenuOptions;

public:

	/** Bezargumentowy konstruktor klasy GUI */
	GUI(void);

	/** Wirtualny destruktor klasy GUI */
	virtual ~GUI(void);

	/** Metoda wyswietla menu glowne programu */
	void PrintApplicationMenu();

	int GetNumberOfMenuOptions()
	{
		return numberOfMenuOptions;
	}
};

