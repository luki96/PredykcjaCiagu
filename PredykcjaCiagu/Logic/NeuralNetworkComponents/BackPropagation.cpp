#include "BackPropagation.h"


BackPropagation::BackPropagation(void)
{
	eta = 0.5;
	ERROR = 0.8;
}


BackPropagation::~BackPropagation(void)
{
}

NeuralNetwork* BackPropagation::BackPropagationMethod(double x, double y, double z, NeuralNetwork* net)
{
	int NETWORK_ONE = 2, NETWORK_TWO = 5, NETWORK_THREE = 1;
	int i = 0;
	int tab = 0;
	double one = 1;
	double afterConversion = 0;
	std::vector<double> neuronsResults;
	std::vector<double> neutralizeWeights; // tablica do ustawienia wag neuronów wejœciowych na wart. = 1 

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
		
		neutralizeWeights.push_back(1);		// ustawienie wag neuronów wejœciowych na wart. = 1 
		net->head->neurons[i]->SetWeight(neutralizeWeights);  // jak wy¿ej 
		net->head->neurons[i]->SetBias(one); // j/w 

		net->head->neurons[i]->CalculateNeuronOutputFunction(parameters);
		
		afterConversion = net->head->neurons[i]->GetOutputFunction();
		neuronsResults.push_back(afterConversion);

		i++;
		tab++;
	}

	i = 0;

	while (i < NETWORK_TWO)
	{
		std::vector<double> parameters;

		parameters.push_back(neuronsResults[0]);
		parameters.push_back(neuronsResults[1]);

		net->head->next->neurons[i]->CalculateNeuronInputsWeights();
		net->head->next->neurons[i]->CalculateNeuronOutputFunction(parameters);
		
		afterConversion = net->head->next->neurons[i]->GetOutputFunction();
		neuronsResults.push_back(afterConversion);

		i++;
		tab++;
	}

	i = 0;

	while (i < NETWORK_THREE)
	{
		int count = 0;
		std::vector<double> parameters;

		// u¿ywamy w tej pêtli NETWORK_ONE aby pomin¹æ elementy z pierwszej sieci neuronowej 
		while ((count+NETWORK_ONE) < tab)
		{
			parameters.push_back(neuronsResults[count+NETWORK_ONE]);
			count ++;
		}

		net->tail->neurons[i]->CalculateNeuronInputsWeights();
		net->tail->neurons[i]->CalculateNeuronOutputFunction(parameters);
		
		afterConversion = net->tail->neurons[i]->GetOutputFunction(); 
		neuronsResults.push_back(afterConversion);

		i++;
		tab++;
	}

	firstResult = neuronsResults[tab-1];

	i = 0;

	//TODO: Algorytm do propagacji, po uzyskaniu wstêpnego wyniku 

	while (i <  NETWORK_THREE) 
	{

		i++;
	}

	i = 0;

	return net;
}


double BackPropagation::NetworkResult(double lastX, double lastY, NeuralNetwork* net)
{
	double finalNetResult = 0;

	int NETWORK_ONE = 2, NETWORK_TWO = 5, NETWORK_THREE = 1;
	int i = 0;
	std::vector<double> neuronsTempResults;
 	int tab = 0;
	double one = 1;
	std::vector<double> neutralizeWeights; // tablica do ustawienia wag neuronów wejœciowych na wart. = 1 

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
		
		neutralizeWeights.push_back(1);		// ustawienie wag neuronów wejœciowych na wart. = 1 
		net->head->neurons[i]->SetWeight(neutralizeWeights);  // jak wy¿ej 
		net->head->neurons[i]->SetBias(one); // j/w 

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

		net->head->next->neurons[i]->CalculateNeuronInputsWeights();
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

		// u¿ywamy w tej pêtli NETWORK_ONE aby pomin¹æ elementy z pierwszej sieci neuronowej 
		while ((count+NETWORK_ONE) < tab)
		{
			parameters.push_back(neuronsTempResults[count+NETWORK_ONE]);
			count ++;
		}

		net->tail->neurons[i]->CalculateNeuronInputsWeights();
		net->tail->neurons[i]->CalculateNeuronOutputFunction(parameters);
		neuronsTempResults.push_back(net->tail->neurons[i]->GetOutputFunction());

		i++;
		tab++;
	}

	finalNetResult = neuronsTempResults[tab-1];

	return finalNetResult; 
}


double BackPropagation::CalculateOutputNeuronAnswearError(double networkAnswear, double expectedAnswear)
{
	double outputError = 0;

	outputError = abs(expectedAnswear - networkAnswear);

	return outputError; 
}