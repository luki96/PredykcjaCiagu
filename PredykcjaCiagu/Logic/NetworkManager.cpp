#include "NetworkManager.h"



NetworkManager::NetworkManager(void)
{
	network = new NeuralNetwork(FIRST_NETWORK, SECOND_NETWORK, THIRD_NETWORK);
	propagation = new BackPropagation(); 
	reader = new TxtFileReader();
	temp1 = temp2 = 0;
}


NetworkManager::~NetworkManager(void)
{
	DestroyNetwork();
	delete network;
	delete propagation;
}


NeuralNetwork* NetworkManager::CreateNetwork()
{
	int i = 0;

	while( i < NETWORK_LAYERS)
	{
		network->CreateNetwork();
	}

	return network;
}


void NetworkManager::DestroyNetwork()
{
	network->~NeuralNetwork();
}


void NetworkManager::TeachNetwork()
{
	int i = 0;
	int dataSize = 0;
	std::vector<int> data;
	
	data.swap(reader->GetData());
	dataSize = data.size();

	if (dataSize >= 2)
	{
		while (i < dataSize)
		{
			temp1 = data[i];
			temp2 = data[i+i];
			network = propagation->BackPropagationMethod(temp1, temp2, network);
			i++;
		}
	}
	else
	{
		//TODO: wzorzec obserwatora / wypisywanie 
		std::cout << "Wprowadzono zbyt ma³o danych, aby sieæ mog³a zadzia³aæ." << std::endl;
	}
}

double NetworkManager::Calculate()
{
	double result = 0;

	result = propagation->NetworkResult(temp1, temp2, network);
	return result;
}

double NetworkManager::RunNetwork()
{
	double result = 0;

	network = CreateNetwork();
	TeachNetwork();
	result = Calculate();

	return result;
}


