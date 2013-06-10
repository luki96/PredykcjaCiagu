#pragma once
#include "..\Logic\NeuralNetworkComponents\NeuralNetwork.h"

/** Interfejs do wstecznej propagacji sieci neuronowyc
	Wa¿ne: Interfejs obs³uguje tylko sieci neuronowe 
	skonwertowane do typu NeuralNetwork */
class IPropagable
{
public:
	/** Konstruktor bezargumentowy IPropagable */
	IPropagable(void);
	/** Wirtualny destruktor IPropagable */ 
	virtual ~IPropagable(void);
	/** Wirtualna metoda do propagacji wsteczne */ 
	virtual NeuralNetwork* Propagation(NeuralNetwork* ) = 0; 
};

