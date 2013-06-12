#pragma once
#include "NeuralNetwork.h"
#include "..\..\Interfaces\IPropagable.h"


/** Klasa dziedzicz¹ca interfejs IPropagable
	s³u¿¹ca do wykonania propagacji wstecznej */ 
class BackPropagation: public IPropagable
{
public:
	/** Konstruktor bezargumentowy klasy BackPropagation */ 
	BackPropagation(void);

	/** Wirtualny destruktor klasy BackPropagation */ 
	virtual ~BackPropagation(void);

    virtual NeuralNetwork* BackPropagationMethod(int, int, NeuralNetwork* );

};

