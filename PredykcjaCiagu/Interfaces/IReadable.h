#pragma once

/** Interfejs umozliwiajacy odczyt danych z pliku */
class IReadable
{
public:

  /** Konstruktor interfejsu IReadable */
	IReadable(void);

	/** Wirtualny destruktor interfejsu IReadable */
	virtual ~IReadable(void);
};
