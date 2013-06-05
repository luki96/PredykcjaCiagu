#pragma once
#include <iostream>
#include <cctype>

/** Klasa odpowiada za "nasluchiwanie" wcisniecia przycisku w menu glownym programu */
class ConsoleMenuListener
{
private:

	/** Metoda sprawdza czy wybrano poprawna opcje z menu 
	@param int key Kod ASCII wcisnietego klawisza
	@param int numberOfMenuOptions Ilosc dostepnych opcji w menu programu
	@return true, gdy klawisz odpowiadal numerowi jednej z opcji dostepnej w menu programu. 
	W przeciwnym wypadku wartoscia zwracana jest false
	*/
	bool ValidateKey(int key, int numberOfMenuOptions);

public:

	/** Bezargumentowy konstruktor klasy ConsoleMenuListener */
	ConsoleMenuListener(void);

	/** Destruktor klasy ConsoleMenuListener */
	~ConsoleMenuListener(void);

	/** Metoda nasluchuje   
	@param int numberOfMenuOptions Ilosc dostepnych opcji w menu programu
	@return Numer opcji, ktora zostala wybrana przez uzytkownika 
	*/
	int ListenForKey(int numberOfMenuOptions);
};

