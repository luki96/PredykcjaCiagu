#pragma once
#include "Neuron.h"
#include "NeuralNetwork.h"
#include "..\..\Interfaces\IPropagable.h"
#include <iostream>
#include <math.h>
#include "..\..\Logic\DataConverter.h"

using namespace std;

/** Klasa dziedzicz�ca interfejs IPropagable
	s�u��ca do wykonania propagacji wstecznej */ 
class BackPropagation: public IPropagable
{

private:

	/** Wsp�czynnik uczenia sieci */ 
	 double factor;

	 /** Obiekt do konwersji danych */
	 DataConverter* converter; 

public:
	/** Konstruktor bezargumentowy klasy BackPropagation */ 
	BackPropagation(void);

	/** Wirtualny destruktor klasy BackPropagation */ 
	virtual ~BackPropagation(void);

	/** Wirtualna metoda z interfejsu IPropagable, pozwalaj�ca na wsteczn� propagacj� sieci neuronowej */
    virtual NeuralNetwork* BackPropagationMethod(double, double, double, NeuralNetwork* );

	/** Wirtualna metoda z interfejsu IPropagable, pozwalaj�ca na uzyskanie wynik�w z sieci neuronowej */
	 virtual double NetworkResult(double, double, NeuralNetwork* );

};

