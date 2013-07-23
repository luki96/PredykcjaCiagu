#pragma once
#include <string>
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

	/** Statyczna metoda wywolujaca polecenie systemowe czyszczace konsole */
	static void ClearScreen();

	/** Statyczna metoda wywolujaca polecenie systemowe wstrzymujace program */
	static void PauseProgram();

	/** Metoda wyswietla menu glowne programu */
	void PrintApplicationMenu();

	/** Metoda wyswietla wiadomosc na konsoli za pomoca obiektu ConsoleMenu */
	void PrintMessage(std::string message);

	/** Getter dla pola numberOfMenuOptions
	@return Ilosc opcji dostepnych w menu glownym programu
	*/
	int GetNumberOfMenuOptions()
	{
		return numberOfMenuOptions;
	}
};

