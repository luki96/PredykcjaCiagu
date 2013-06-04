#pragma once
#include "..\UI\GUI.h"
#include "..\Logic\ConsoleMenuListener.h"

/** Klasa odpowiada za sterowanie przeplywem dzialania programu */
class Controller
{
private:

	/** Prywatny wskaznik do obiektu klasy GUI */
	GUI* gui;

	/**  */
	ConsoleMenuListener* consoleMenuListener ;

public:
	/** Bezargumentowy konstruktor klasy Controller */
	Controller(void);

	/** Destruktor klasy Controller */
	~Controller(void);

	/** Metoda odpowiada za petle glowna programu */
	void Run();
};

