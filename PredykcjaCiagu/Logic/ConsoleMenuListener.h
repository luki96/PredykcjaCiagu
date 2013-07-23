#pragma once
#include <iostream>
#include <cctype>

/** Klasa odpowiada za "nas³uchiwanie" wciœniêcia przycisku w menu g³ównym programu */
class ConsoleMenuListener
{
private:

	/** Metoda sprawdza czy wybrano poprawn¹ opcjê z menu 
	@param int key Kod ASCII wciœniêtego klawisza
	@param int numberOfMenuOptions Iloœæ dostêpnych opcji w menu programu
	@return true, gdy klawisz odpowiada³ numerowi jednej z opcji dostêpnej w menu programu. 
	W przeciwnym wypadku wartosci¹ zwracan¹ jest false
	*/
	bool ValidateKey(int key, int numberOfMenuOptions);

public:

	/** Bezargumentowy konstruktor klasy ConsoleMenuListener */
	ConsoleMenuListener(void);

	/** Destruktor klasy ConsoleMenuListener */
	~ConsoleMenuListener(void);

	/** Metoda nas³uchuje   
	@param int numberOfMenuOptions Iloœæ dostêpnych opcji w menu programu
	@return Numer opcji, która zosta³a wybrana przez u¿ytkownika 
	*/
	int ListenForKey(int numberOfMenuOptions);
};

