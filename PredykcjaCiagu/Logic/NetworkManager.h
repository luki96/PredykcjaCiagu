#pragma once
#include "NeuralNetworkComponents\Neuron.h"
#include "NeuralNetworkComponents\NeuralNetwork.h"
#include "NeuralNetworkComponents\IPropagable.h"
#include "NeuralNetworkComponents\BackPropagation.h"

/** Klasa menad�erska s�u��ca do obs�ugi sieci neuronowej */
class NetworkManager
{
private:
	/** Zmienna wska�nikowa interfejsu, wskazuj�ca obiekt klasy BackPropagation */
	IPropagable* propagation;
	/** Zmienna wska�nikowa wskazuj�ca obiekt NeuralNetwork*/
	NeuralNetwork* network;
	/** Zmienne odpowiadaj�ce za liczb� neuron�w w kolejnych watstwach sieci */
	static const int FIRST_NETWORK = 2, SECOND_NETWORK = 5, THIRD_NETWORK = 1;
	/** Zmienna odpowiedzialna za liczbe warst sieci neuronowej */
	static const int NETWORK_LAYERS = 3; 


public:
	/** Konstruktor bezargu mentowy klasy Networkmanager */
	NetworkManager(void);

	/** Wirtualny destruktor klasy NetworkManager */
	virtual ~NetworkManager(void);

/** Metoda s�u��ca do stworzenia sieci neuronowej
	@return network -> stworzona sie� neuronowa */
	NeuralNetwork* CreateNetwork();

/** Metoda s�u��ca do usuni�cia sieci neuronowej */
	void DestroyNetwork();

/** Metoda ucz�ca sie� neuronow� 
	@return network -> nauczona siec */
	NeuralNetwork* TeachNetwork();

/** Metoda uruchamiaj�ca sie� i zwracaj�ca wynik 
	@return Wynik -> wynik oblicze� sieci */
	double RunNetwork();

/** Metoda do sterowania ca�ym procesem sieci neuronowej,
	tworzenie, uczenie, obliczania, usuwanie 
	@return WynikKoncowy -> koncowy wynik z dzialania funkcji */ 	
	double ManageNeuralNetwork();

};

