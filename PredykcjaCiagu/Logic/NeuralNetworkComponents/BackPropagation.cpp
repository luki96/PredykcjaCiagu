#include "BackPropagation.h"


BackPropagation::BackPropagation(void)
{
	eta = 0.5;
	ERROR = 0.001;
}


BackPropagation::~BackPropagation(void)
{
}

NeuralNetwork* BackPropagation::BackPropagationMethod(double x, double y, double z, NeuralNetwork* net)
{
	int NETWORK_ONE = 2, NETWORK_TWO = 5, NETWORK_THREE = 1;
	double derivative = 0;
	int i = 0;
	int tab = 0;
	int iterator = 0;
	double destinationValue = z;
	double zerro = 0;
	double propagationAnswear = 0;
	double afterConversion = 0;
	std::vector<double> neuronsResults;
	std::vector<double> neutralizeWeights; // tablica do ustawienia wag neuronów wejœciowych na wart. = 1 

	destinationValue = 1/(1 + exp(-(destinationValue))); // konwersja destinationValues do przedzialu {0,1}
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
		net->head->neurons[i]->SetBias(zerro); // j/w 

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

	propagationAnswear = destinationValue - firstResult;

	i = 0;

	// Back propagation 
	//while((iterator < 25) && (propagationAnswear > ERROR))
	{

		

		// 1 Compute output gradients 
		while (i <  NETWORK_THREE) 
		{
			double networkAnswear = net->tail->neurons[i]->GetOutputFunction();

			derivative = (1 - networkAnswear ) *  networkAnswear;
			net->tail->neurons[i]->SetGradient(derivative * (destinationValue - networkAnswear));
			i++;
		}

		derivative = 0;
		i = 0;

		// 2 Compute hidden gradients
		while (i < NETWORK_TWO)
		{
			double hiddenAnswear = net->head->next->neurons[i]->GetOutputFunction(); 
			double sum = 0;
			int ZERO = 0;
			int j = 0;
			std::vector<double> numbOfInputs;

			derivative = ( 1 - hiddenAnswear) * hiddenAnswear;

			numbOfInputs.clear();
			numbOfInputs.swap(net->tail->neurons[ZERO]->GetWeight());

			while (j < numbOfInputs.size())
			{
				sum += net->tail->neurons[ZERO]->GetGradient() * numbOfInputs[j];
				j++;
			}

			net->head->next->neurons[i]->SetGradient(derivative * sum);

			j = 0;
			i++;
		}

		i = 0;

		//3 Update hidden neuron weights
		while (i < (net->head->neurons.size())) // iteracja po iloœci wejœc  w neuronach warstwy ukrytej 
		{
			int j = 0;

			while (j < NETWORK_TWO)  // iteracja po warstwie ukrytej 
			{
				double delta = eta * net->head->next->neurons[j]->GetGradient() * net->head->neurons[i]->GetOutputFunction();
				delta += net->head->next->neurons[j]->GetOneWeight(i);
				net->head->next->neurons[j]->SetOneWeight(i, delta);
				j++;
			}

			i++;
		}

		i = 0;

		//3b Update hidden neuron biases
		while (i < NETWORK_TWO)
		{
			double delta = eta * net->head->next->neurons[i]->GetGradient();
			delta += net->head->next->neurons[i]->GetBias();
			net->head->next->neurons[i]->SetBias(delta);
			i++;
		}

		i = 0;

		//4 Update output neurons weights
		while (i < net->head->next->neurons.size())
		{
			int j = 0;

			while (j < NETWORK_THREE)
			{
				double delta = eta * net->tail->neurons[j]->GetGradient() * net->head->next->neurons[i]->GetOutputFunction(); 
				delta += net->tail->neurons[j]->GetOneWeight(i);
				net->tail->neurons[j]->SetOneWeight(i, delta);
				j++;
			}

			i++;
		}

		i = 0;

		// 4b Update outputs neurons biases 
		while (i < NETWORK_THREE)
		{
			double delta = eta * net->tail->neurons[i]->GetGradient();
			delta += net->tail->neurons[i]->GetBias();
			net->tail->neurons[i]->SetBias(delta);

			i++;
		}

		i = 0;
		//
		double abc = net->tail->neurons[i]->GetOutputFunction();
		//

		propagationAnswear = CalculateOutputNeuronAnswearError(destinationValue, net->tail->neurons[i]->GetOutputFunction());

		iterator++;

	} // end of weight update 

	iterator = 0;

	double finalResult = net->tail->neurons[i]->GetOutputFunction();
	//finalResult = log(finalResult/(1-finalResult));

	//cout << finalResult << endl;  

	return net;
}


double BackPropagation::NetworkResult(double lastX, double lastY, NeuralNetwork* net)
{
	double finalNetResult = 0;

	int NETWORK_ONE = 2, NETWORK_TWO = 5, NETWORK_THREE = 1;
	int i = 0;
	std::vector<double> neuronsTempResults;
	int tab = 0;
	double zero = 0;
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
		net->head->neurons[i]->SetBias(zero); // j/w 

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


double BackPropagation::CalculateOutputNeuronAnswearError(double expectedAnswear, double networkAnswear)
{
	double outputError = 0;

	outputError = abs(expectedAnswear - networkAnswear);

	return outputError; 
}