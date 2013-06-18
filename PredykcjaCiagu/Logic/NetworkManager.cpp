#include "NetworkManager.h"



NetworkManager::NetworkManager(void)
{
	network = new NeuralNetwork(FIRST_NETWORK, SECOND_NETWORK, THIRD_NETWORK);
	propagation = new BackPropagation(); 
	reader = new TxtFileReader();
	temp1 = temp2 = 0;
	converter = new DataConverter();

	reader->ReadFile("a.txt");
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
		i++;
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
	dataSize = 0;
	
	convertedData.clear();
	data.clear();

	data.swap(reader->GetData());
	dataSize = data.size();
	converter->ConvertDataToSigmoidFunctionRange(data);
	convertedData.swap(converter->GetConvertedData());


	if (dataSize >= 2)
	{
		while ((i+2) < dataSize)
		{
			temp1 = convertedData[i];
			temp2 = convertedData[i+1];
			network = propagation->BackPropagationMethod(temp1, temp2, network);
			i++;
		}
		// przygotowanie danych do metody Calculate (by tam ponownie nie iterowaæ po tablicy)
		temp1 = convertedData[i];
		temp2 = convertedData[i+1];
	}
	else
	{
		std::cout << "Wprowadzono zbyt ma³o danych, aby sieæ mog³a zadzia³aæ." << std::endl;
	}
}

double NetworkManager::Calculate()
{
	double result = 0;

	// temp1 i temp2 zosta³y uprzednio przygotowane przez metodê TeachNetwork, po zakoñczeniu jej pêtli g³ównej 
	result = propagation->NetworkResult(temp1, temp2, network);
	return result;
}

double NetworkManager::RunNetwork()
{
	double result = 0;

	network = CreateNetwork();
	TeachNetwork();
	if (dataSize >= 2)
	{
		result = Calculate();
	}
	finalyNetworkResult = result;
	return result;
}


