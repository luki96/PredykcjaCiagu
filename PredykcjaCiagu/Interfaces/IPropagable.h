#pragma once
#include "..\Logic\NeuralNetworkComponents\NeuralNetwork.h"

/** Interfejs wykorzystywany do implementacji w klasach propaguj¹cych sieæ
	neuronow¹ i uzyskuj¹cych z niej wyniki. Umo¿liwia zwiêkszenie uniwersalnoœci i
	³atwoœæ wprowadzania zmian. Implementuje metody do uczenia sieci i wykonywania 
	na niej obliczeñ 

	UWAGA: Elementy sieci, musz¹ byæ typu NeuralNetwork !!! */ 
class IPropagable
{
public:

	/** Konstruktor bezargumentowy */
	IPropagable(void);

	/** Wirtualny destruktor */
	~IPropagable(void);

	/** Czysto wirtualna metoda do uczenia sieci neuronowej */
	virtual NeuralNetwork* BackPropagationMethod(double, double, double, NeuralNetwork* ) = 0;

	/** Czysto wirtualna metoda, do wykonania ostatnich obliczeñ, na siecii */
	virtual double NetworkResult(double, double, NeuralNetwork* ) = 0;

	virtual double GetEndResult() = 0;

};

