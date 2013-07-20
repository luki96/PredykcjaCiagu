#include "NetworkManager.h"


NetworkManager::NetworkManager(void)
{
	network = new NeuralNetwork(FIRST_NETWORK, SECOND_NETWORK, THIRD_NETWORK);
	propagation = new BackPropagation(); 
	reader = new TxtFileReader();
	writer = new TxtFileWriter();
	temp1 = temp2 = 0;

	reader->ReadFile("a.txt");
}


NetworkManager::~NetworkManager(void)
{
	DestroyNetwork();
	delete network;
	delete propagation; 
	delete reader;
	delete writer;
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
	convertedData.swap(data);


	if (dataSize >= 3)
	{
		while ((i+2) < dataSize)
		{
			temp1 = convertedData[i];
			temp2 = convertedData[i+1];
			temp3 = convertedData[i+2];
			p1 = temp3;
			network = propagation->BackPropagationMethod(temp1, temp2, temp3, network);
			i++;
			test = propagation->GetEndResult();
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

void NetworkManager::SaveToFile(std::string fName, std::vector<double> data)
{
	writer->WriteFile(fName, data);
}

double NetworkManager::RunNetwork()
{
	double result = 0;
	double zlicz = 0;

	network = CreateNetwork();
	TeachNetwork();
	if (dataSize >= 2)
	{
		result = Calculate();
	}
	finalyNetworkResult = result;

	zlicz = (p1 * finalyNetworkResult)/test;

	tabWynik.push_back(zlicz);
	
	finalyNetworkResult = zlicz;

	SaveToFile ("OdpSieci.txt", tabWynik);

	return finalyNetworkResult;
}


