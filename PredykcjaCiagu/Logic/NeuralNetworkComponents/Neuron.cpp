#include "Neuron.h"
using namespace std;

Neuron::Neuron(int numberOfNeuronInputs) : LOWER_LIMIT_WEIGHTS_RANGE(-0.5), 
	UPPER_LIMIT_WEIGHTS_RANGE(0.5)
{
	srand (time(NULL));
	this->numberOfNeuronInputs = numberOfNeuronInputs;
	this->outputFunction = 0.0;
	this->weight = 0.0;
	bias = ((rand()%11) - 5) / 10;
}

Neuron::~Neuron(void)
{
}

bool Neuron::CalculateNeuronInputsWeights()
{
	if (numberOfNeuronInputs <= 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < numberOfNeuronInputs; i++)
		{
			weight = (UPPER_LIMIT_WEIGHTS_RANGE - LOWER_LIMIT_WEIGHTS_RANGE) 
				* ((double)rand() / RAND_MAX) + LOWER_LIMIT_WEIGHTS_RANGE;
			weightsOfNeuronInputs.push_back(weight);
		}
		return true;
	}
	return false;
}

void Neuron::CalculateNeuronOutputFunction(vector<double> neuronInputData)
{
	for (int i = 0; i < numberOfNeuronInputs; i++)
	{
		this->outputFunction +=( (neuronInputData[i] * this->weightsOfNeuronInputs[i]) + bias );
	}
		this->outputFunction = 1/(1 + exp(-(this->outputFunction)));
}