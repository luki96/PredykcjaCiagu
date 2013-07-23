#pragma once
#include "Controller.h"

/** Nadrzêdna klasa uruchomieniowo / menad¿erska */
class Runner
{
private:

	/** Prywatny wskaŸnik do obiektu klasy Controller */
	Controller* controller;

public:

	/** Bezargumentowy konstruktor klasy Runner */
	Runner(void);

	/** Destruktor klasy Runner */
	~Runner(void);

	/** Metoda uruchamiaj¹ca program */
	void RunProgram();
};

