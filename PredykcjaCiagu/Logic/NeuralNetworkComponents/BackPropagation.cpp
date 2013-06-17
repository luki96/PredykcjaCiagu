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
	double firstResult = 0;

	while (i < NETWORK_ONE)
	{
		std::vector<double> parameters;

		if (i == 0)
		{
			parameters.push_back(x);
		}
		else if (i == 1)
		{
			parameters.clear();
			parameters.push_back(y);
		}
		else
		{
			parameters.clear();
			parameters[0] = 0;
		}

		net->head->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsResults.push_back(net->head->neurons[i]->GetOutputFunction());

		i++;
		tab++;
	}

	i = 0;

	while (i < NETWORK_TWO)
	{
		std::vector<double> parameters;

		parameters.push_back(neuronsResults[0]);
		parameters.push_back(neuronsResults[1]);

		net->head->next->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsResults.push_back(net->head->next->neurons[i]->GetOutputFunction());

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
			parameters.push_back(neuronsResults[count]);
			count ++;
		}

		net->tail->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsResults.push_back(net->tail->neurons[i]->GetOutputFunction());

		i++;
		tab++;
	}

	firstResult = neuronsResults[tab-1];

	//TODO: Algorytm do propagacji, po uzyskaniu wstêpnego wyniku 
	
	return net;
}


double BackPropagation::NetworkResult(int lastX, int lastY, NeuralNetwork* net)
{
	double finalNetResult = 0;

	int NETWORK_ONE = 2, NETWORK_TWO = 5, NETWORK_THREE = 1;
	int i = 0;
	std::vector<double> neuronsTempResults;
	int tab = 0;

	while (i < NETWORK_ONE)
	{
		std::vector<double> parameters;

		if (i == 0)
		{
			parameters.push_back(lastX);
		}
		else if (i == 1)
		{
			parameters.clear();
			parameters.push_back(lastY);
		}
		else
		{
			parameters.clear();
			parameters.push_back(0);
		}

		net->head->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsTempResults.push_back(net->head->neurons[i]->GetOutputFunction());

		i++;
		tab++;
	}

	i = 0;

	while (i < NETWORK_TWO)
	{
		std::vector<double> parameters;

		parameters.push_back(neuronsTempResults[0]);
		parameters.push_back(neuronsTempResults[1]);

		net->head->next->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsTempResults.push_back(net->head->next->neurons[i]->GetOutputFunction());

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
			parameters.push_back(neuronsTempResults[count]);
			count ++;
		}

		net->tail->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsTempResults.push_back(net->tail->neurons[i]->GetOutputFunction());

		i++;
		tab++;
	}

	finalNetResult = neuronsTempResults[tab-1];

	return finalNetResult; 
}