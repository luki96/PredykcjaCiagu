#pragma once
#include <sstream>
#include "..\UI\GUI.h"
#include "..\Logic\ConsoleMenuListener.h"
#include "..\Logic\FileManager.h"
#include "..\Logic\NetworkManager.h"

/** Klasa odpowiada za sterowanie przeplywem dzialania programu */
class Controller
{
private:

	/** Prywatny wskaznik do obiektu klasy GUI */
	GUI* gui;

	/** Prywatny wskaznik do obiektu klasy ConsoleMenuListener */
	ConsoleMenuListener* consoleMenuListener;

	/** Prywatny wskaznik do obiektu klasy FileManager */
	FileManager* fileManager;

	/** Prywatny wskaünik do obiektu klasy NetworkManager */
	NetworkManager* network;

public:
	/** Bezargumentowy konstruktor klasy Controller */
	Controller(void);

	/** Destruktor klasy Controller */
	~Controller(void);

	/** Metoda odpowiada za petle glowna programu */
	void Run();
};

