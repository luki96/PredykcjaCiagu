#include "BackPropagation.h"


BackPropagation::BackPropagation(void)
{
}


BackPropagation::~BackPropagation(void)
{
}

NeuralNetwork* BackPropagation::BackPropagationMethod(int x, int y, NeuralNetwork* net)
{
	int NETWORK_ONE = 2, NETWORK_TWO = 5, NETWORK_THREE = 1;
	int i = 0;
	int tab = 0;
	std::vector<double> neuronsResults;
	double firstREsult = 0;

	while (i < NETWORK_ONE)
	{
		std::vector<double> parameters;

		if (i == 0)
		{
			parameters[0] = x;
		}
		else if (i == 1)
		{
			parameters[0] = y;
		}
		else
		{
			parameters[0] = 0;
		}

		net->head->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsResults[tab] = net->head->neurons[i]->GetOutputFunction();

		i++;
		tab++;
	}

	i = 0;

	while (i < NETWORK_TWO)
	{
		std::vector<double> parameters;

		parameters[0] = neuronsResults[0];
		parameters[1] = neuronsResults[1];

		net->head->next->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsResults[tab] = net->head->next->neurons[i]->GetOutputFunction();

		i++;
		tab++;
	}

	i = 0;

	while (i < NETWORK_THREE)
	{
		int count = 0;
		std::vector<double> parameters;

		while (count < tab)
		{
			parameters[count] = neuronsResults[count];
			count ++;
		}

		net->tail->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsResults[tab] = net->tail->neurons[i]->GetOutputFunction();

		i++;
		tab++;
	}

	firstREsult = neuronsResults[tab-1];

	//TODO: Algorytm do propagacji, po uzyskaniu wstêpnego wyniku 
	
	return net;
}

double BackPropagation::NetworkResult(int lastX, int lastY, NeuralNetwork* net)
{
	double finalNetResult = 0;

	int NETWORK_ONE = 2, NETWORK_TWO = 5, NETWORK_THREE = 1;
	int i = 0;



	return finalNetResult; 
}