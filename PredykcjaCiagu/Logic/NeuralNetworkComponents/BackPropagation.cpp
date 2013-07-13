#include "BackPropagation.h"


BackPropagation::BackPropagation(void)
{
	factor = 0.9;
	converter = new DataConverter();
}


BackPropagation::~BackPropagation(void)
{
}

NeuralNetwork* BackPropagation::BackPropagationMethod(double x, double y, double z, NeuralNetwork* net)
{
	int NETWORK_ONE = 2, NETWORK_TWO = 5, NETWORK_THREE = 1;
	int i = 0;
	int tab = 0;
	double toConvert = 0, afterConversion = 0;
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

		net->head->neurons[i]->CalculateNeuronInputsWeights();
		net->head->neurons[i]->CalculateNeuronOutputFunction(parameters);
		
		// ew. proponowana zmiana 
		toConvert = net->head->neurons[i]->GetOutputFunction();
		toConvert *= 1000; // cofniecie konwersji po wczytaniu z pliku 
		afterConversion = converter->ConvertData(toConvert);

		neuronsResults.push_back(afterConversion);
		//
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
		neuronsResults.push_back(net->head->next->neurons[i]->GetOutputFunction());

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
		neuronsResults.push_back(net->tail->neurons[i]->GetOutputFunction());

		i++;
		tab++;
	}

	firstResult = neuronsResults[tab-1];

	i = 0;

	//TODO: Algorytm do propagacji, po uzyskaniu wstêpnego wyniku 

	//
	double sum = 0, blad = 0, tmp1 = 0, tmp2 = 0, waga = 0;

	std::vector<double> wagi;
	std::vector<double> zmiana;
	wagi.clear();
	zmiana.clear();

	tmp1 = net->tail->neurons[i]->GetOutputFunction();



		blad = (pow((z - tmp1), 2))/2;
		blad = blad/5;

		wagi.swap(net->tail->neurons[i]->GetWeight());

		int j = 0;

		while( j < wagi.size())
		{
			if (blad > 0)
			{
				zmiana.push_back(wagi[i] + ( factor));
			}
			else if (blad < 0)
			{
				zmiana.push_back(wagi[i] - ( factor));
			}
			j++;
		}

		net->tail->neurons[i]->SetWeight(zmiana);

		i = 0;
		j = 0;

		while (i < NETWORK_ONE)
		{
			tmp1 = z - net->head->next->neurons[i]->GetOutputFunction();
			blad = (pow((z - tmp1), 2))/2;
			blad = blad/2;

			wagi.clear();
			zmiana.clear();

			wagi.swap(net->head->next->neurons[i]->GetWeight());

		j = 0;

		while( j < wagi.size())
		{
			if (blad > 0)
			{
				zmiana.push_back(wagi[i] + ( factor));
			}
			else if (blad < 0)
			{
				zmiana.push_back(wagi[i] - ( factor));
			}
			j++;
		}

		net->head->next->neurons[i]->SetWeight(zmiana);

		i++;

		}

		i = 0;
		j = 0;
	


	//cout << firstResult<<endl;


	
	

	//
	
	return net;
}


double BackPropagation::NetworkResult(double lastX, double lastY, NeuralNetwork* net)
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
		
		net->head->neurons[i]->CalculateNeuronInputsWeights();
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