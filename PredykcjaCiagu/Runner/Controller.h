#pragma once
#include <sstream>
#include "..\UI\GUI.h"
#include "..\Logic\ConsoleMenuListener.h"
#include "..\Logic\NetworkManager.h"

/** Klasa odpowiada za sterowanie przep≥ywem dzia≥ania programu */
class Controller
{
private:

	/** Prywatny wskaünik do obiektu klasy GUI */
	GUI* gui;

	/** Prywatny wskaünik do obiektu klasy ConsoleMenuListener */
	ConsoleMenuListener* consoleMenuListener;

	/** Prywatny wskaünik do obiektu klasy NetworkManager */
	NetworkManager* network;

public:
	/** Bezargumentowy konstruktor klasy Controller */
	Controller(void);

	/** Destruktor klasy Controller */
	~Controller(void);

	/** Metoda odpowiada za pÍtlÍ g≥Ûwnπ programu */
	void Run();
};

