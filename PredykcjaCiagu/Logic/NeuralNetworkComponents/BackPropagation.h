#pragma once
#include "Neuron.h"
#include "NeuralNetwork.h"
#include "..\..\Interfaces\IPropagable.h"
#include "..\..\Logic\DataConverter.h"

/** Klasa dziedzicz¹ca interfejs IPropagable
	s³u¿¹ca do wykonania propagacji wstecznej */ 
class BackPropagation: public IPropagable
{
private:

		DataConverter* converter;

public:
	/** Konstruktor bezargumentowy klasy BackPropagation */ 
	BackPropagation(void);

	/** Wirtualny destruktor klasy BackPropagation */ 
	virtual ~BackPropagation(void);

	/** Wirtualna metoda z interfejsu IPropagable, pozwalaj¹ca na wsteczn¹ propagacjê sieci neuronowej */
    virtual NeuralNetwork* BackPropagationMethod(int, int, NeuralNetwork* );

	/** Wirtualna metoda z interfejsu IPropagable, pozwalaj¹ca na uzyskanie wyników z sieci neuronowej */
	virtual double NetworkResult(int, int, NeuralNetwork* );

};

