#pragma once
#include "..\Interfaces\IReadable.h"
#include "..\Data\TxtFileReader.h"

/** Klasa odpowiada za zarzadzanie klasami odczytujacymi / zapisujacymi pliki */
class FileManager
{
public:

	/** Prywatny wskaznik typu IReadable, pod ktory bedzie mozna "podpiac" 
	klasy implementujace ten interfejs */
	IReadable* ireader;

public:
	
	/** Konstruktor klasy FileManager */
	FileManager(void);
	
	/** Wirtualny destruktor klasy FileManager */
	virtual ~FileManager(void);
};

