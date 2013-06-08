#pragma once
#include "..\UI\GUI.h"
#include "..\Logic\ConsoleMenuListener.h"
#include "..\Logic\DataConverter.h"
#include "..\Logic\FileManager.h"

/** Klasa odpowiada za sterowanie przeplywem dzialania programu */
class Controller
{
private:

	/** Prywatny wskaznik do obiektu klasy GUI */
	GUI* gui;

	/** Prywatny wskaznik do obiektu klasy ConsoleMenuListener */
	ConsoleMenuListener* consoleMenuListener;

	/** Prywatny wskaznik do obiektu klasy DataConverter */
	DataConverter* dataConverter;

	/** Prywatny wskaznik do obiektu klasy FileManager */
	FileManager* fileManager;

public:
	/** Bezargumentowy konstruktor klasy Controller */
	Controller(void);

	/** Destruktor klasy Controller */
	~Controller(void);

	/** Metoda odpowiada za petle glowna programu */
	void Run();
};

