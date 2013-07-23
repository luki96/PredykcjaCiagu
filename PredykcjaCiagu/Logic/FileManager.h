#pragma once
#include "..\Interfaces\IReadable.h"
#include "..\Interfaces\IWritable.h"
#include "..\Data\TxtFileReader.h"

/** Klasa odpowiada za zarz¹dzanie klasami odczytuj¹cymi / zapisuj¹cymi pliki */
class FileManager
{
public:

	/** Prywatny wskaŸnik typu IReadable, pod który bdzie mo¿na "podpi¹æ" 
	klasy implementujace ten interfejs */
	IReadable* ireader;

	/** Prywatny wskaŸnik typu IWritable, pod który bdzie mo¿na "podpi¹æ" 
	klasy implementujace ten interfejs */
	IWritable* iwriter;

public:
	
	/** Konstruktor klasy FileManager */
	FileManager(void);
	
	/** Wirtualny destruktor klasy FileManager */
	virtual ~FileManager(void);
};

