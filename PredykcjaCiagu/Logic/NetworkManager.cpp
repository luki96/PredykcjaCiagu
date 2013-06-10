#include "NetworkManager.h"



NetworkManager::NetworkManager(void)
{
	

	network = new NeuralNetwork(FIRST_NETWORK, SECOND_NETWORK, THIRD_NETWORK);
	propagation = new BackPropagation();

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

NeuralNetwork* NetworkManager::TeachNetwork()
{

	return network;
}

double NetworkManager::RunNetwork()
{
	double wynik = 0;

	return wynik;
}

double NetworkManager::ManageNeuralNetwork()
{
	double WynikKoncowy = 0;

	return WynikKoncowy; 
}

