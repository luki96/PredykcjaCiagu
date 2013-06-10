#include "NetworkManager.h"



NetworkManager::NetworkManager(void)
{
	int firstNetwork = 2, secondNetwork = 5, thirdNetwork = 1;

	network = new NeuralNetwork(firstNetwork, secondNetwork, thirdNetwork);
	propagation = new BackPropagation();

}


NetworkManager::~NetworkManager(void)
{
}


NeuralNetwork* NetworkManager::CreateNetwork()
{


	return network;
}


void NetworkManager::DestroyNetwork()
{
	network->~NeuralNetwork();
}



