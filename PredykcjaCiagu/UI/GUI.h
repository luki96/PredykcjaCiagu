#pragma once
#include <string>
#include "..\UI\ConsoleMenu.h"

/** Klasa odpowiada za interfejs aplikacji */
class GUI
{
private:

	/** Prywatny wskaŸnik do obiektu klasy ConsoleMenu */
	ConsoleMenu* consoleMenu;

	/** Iloœæ opcji dostêpnych w menu g³ównym programu */
	int numberOfMenuOptions;

public:

	/** Bezargumentowy konstruktor klasy GUI */
	GUI(void);

	/** Wirtualny destruktor klasy GUI */
	virtual ~GUI(void);

	/** Statyczna metoda wywo³uj¹ca polecenie systemowe czyszcz¹ce konsolê */
	static void ClearScreen();

	/** Statyczna metoda wywo³uj¹ca polecenie systemowe wstrzymuj¹ce program */
	static void PauseProgram();

	/** Metoda wyœwietla menu g³ówne programu */
	void PrintApplicationMenu();

	/** Metoda wyœwietla wiadomoœæ na konsoli za pomoc¹ obiektu ConsoleMenu */
	void PrintMessage(std::string message);

	/** Getter dla pola numberOfMenuOptions
	@return Iloœæ opcji dostêpnych w menu g³ównym programu
	*/
	int GetNumberOfMenuOptions()
	{
		return numberOfMenuOptions;
	}
};

