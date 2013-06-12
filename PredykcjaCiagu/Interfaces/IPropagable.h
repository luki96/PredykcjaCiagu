#pragma once
#include "..\Logic\NeuralNetworkComponents\NeuralNetwork.h"

class IPropagable
{
public:

	IPropagable(void);

	~IPropagable(void);

	virtual NeuralNetwork* BackPropagationMethod(int, int, NeuralNetwork* ) = 0;
};

