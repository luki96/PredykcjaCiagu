#pragma once
#include "..\Logic\NeuralNetworkComponents\NeuralNetwork.h"

/** Interfejs wykorzystywany do implementacji w klasach propagujacych sieæ
	neuronow¹ i uzyskuj¹cych z niej wyniki.

	UWAGA: Elementy sieci, musz¹ byæ typu NeuralNetwork !!! */ 
class IPropagable
{
public:

	/** Konstruktor bezargumentowy */
	IPropagable(void);

	/** Wirtualny destruktor */
	~IPropagable(void);

	/** Czysto wirtualna metoda do uczenia siecii neuronowej */
	virtual NeuralNetwork* BackPropagationMethod(double, double, double, NeuralNetwork* ) = 0;

	/** Czysto wirtualna metoda, do wykonania ostatnich obliczeñ, na siecii */
	virtual double NetworkResult(double, double, NeuralNetwork* ) = 0;

	virtual double GetEndResult() = 0;

};

