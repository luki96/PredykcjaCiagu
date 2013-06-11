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


double NetworkManager::Calculate()
{
	int calculations = 0;

	return calculations;
}


double NetworkManager::RunNetwork()
{
	double result = 0;

	network = CreateNetwork();

	result = Calculate();

	return result;
}


