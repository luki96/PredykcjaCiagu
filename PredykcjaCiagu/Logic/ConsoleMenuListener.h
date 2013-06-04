#pragma once
#include <iostream>
#include <cctype>

/** Klasa odpowiada za "nasluchiwanie" wcisniecia przycisku w menu glownym programu */
class ConsoleMenuListener
{
private:

	/** Metoda sprawdza czy wybrano poprawna opcje z menu */
	bool ValidateKey(int key, int numberOfMenuOptions);

public:

	/** Bezargumentowy konstruktor klasy ConsoleMenuListener */
	ConsoleMenuListener(void);

	/** Destruktor klasy ConsoleMenuListener */
	~ConsoleMenuListener(void);

	int ListenForKey(int numberOfMenuOptions);
};

