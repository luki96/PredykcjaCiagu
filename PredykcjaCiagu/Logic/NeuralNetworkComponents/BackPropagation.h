#pragma once
#include "NeuralNetwork.h"
#include "..\..\Interfaces\IPropagable.h"


/** Klasa dziedzicząca interfejs IPropagable
	służąca do wykonania propagacji wstecznej */ 
class BackPropagation: public IPropagable
{
public:
	/** Konstruktor bezargumentowy klasy BackPropagation */ 
	BackPropagation(void);

	/** Wirtualny destruktor klasy BackPropagation */ 
	virtual ~BackPropagation(void);

    virtual NeuralNetwork* BackPropagationMethod(NeuralNetwork* );

};

