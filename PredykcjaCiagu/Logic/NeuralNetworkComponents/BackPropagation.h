#pragma once
#include "Neuron.h"
#include "NeuralNetwork.h"
#include "..\..\Interfaces\IPropagable.h"
#include <iostream>
#include <math.h>

using namespace std;

/** Klasa dziedzicz¹ca interfejs IPropagable
	s³u¿¹ca do wykonania wstecznej propagacji */
class BackPropagation: public IPropagable
{

private:

	/** Wspó³czynnik uczenia sieci */ 
	 double eta;

	 /** Maksymalny dopuszczalny b³¹d */ 
	 double ERROR; 

public:
	/** Wynik koncowy */ 
	double endResult;

	/** Konstruktor bezargumentowy klasy BackPropagation */ 
	BackPropagation(void);

	/** Wirtualny destruktor klasy BackPropagation */ 
	virtual ~BackPropagation(void);

	/** Wirtualna metoda z interfejsu IPropagable, pozwalaj¹ca na wsteczn¹ propagacjê sieci neuronowej */
    virtual NeuralNetwork* BackPropagationMethod(double, double, double, NeuralNetwork* );

	/** Wirtualna metoda z interfejsu IPropagable, pozwalaj¹ca na uzyskanie wyników z sieci neuronowej */
	 virtual double NetworkResult(double, double, NeuralNetwork* );

	 /** Obliczenie b³êdu z neuronu wyjœciowego (b³¹d: (|Wartoœæ oczekiwana - Wartoœæ otrzymana|) */
	 double CalculateOutputNeuronAnswearError(double networkAnswear, double expectedAnswear);

	 /** Geeter do zmiennej endResult */ 
	 double GetEndResult()
	 {
		 return endResult;
	 }

};

