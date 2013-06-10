#pragma once
#include "NeuralNetworkComponents\Neuron.h"
#include "NeuralNetworkComponents\NeuralNetwork.h"
#include "NeuralNetworkComponents\IPropagable.h"
#include "NeuralNetworkComponents\BackPropagation.h"

/** Klasa menad¿erska s³u¿¹ca do obs³ugi sieci neuronowej */
class NetworkManager
{
private:
	/** Zmienna wskaŸnikowa interfejsu, wskazuj¹ca obiekt klasy BackPropagation */
	IPropagable* propagation;
	/** Zmienna wskaŸnikowa wskazuj¹ca obiekt NeuralNetwork*/
	NeuralNetwork* network;

public:
	/** Konstruktor bezargu mentowy klasy Networkmanager */
	NetworkManager(void);

	/** Destruktor klasy NetworkManager */
	~NetworkManager(void);

/** Metoda s³u¿¹ca do stworzenia sieci neuronowej
	@return network -> stworzona sieæ neuronowa */
	NeuralNetwork* CreateNetwork();

/** Metoda s³u¿¹ca do usuniêcia sieci neuronowej */
	void DestroyNetwork();

/** Metoda ucz¹ca sieæ neuronow¹ */
	NeuralNetwork* TeachNetwork();

/** Metoda uruchamiaj¹ca sieæ i zwracaj¹ca wynik 
	@return wynik -> wynik obliczeñ sieci*/
	double RunNetwork();

};

