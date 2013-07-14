#pragma once
#include "NeuralNetworkComponents\Neuron.h"
#include "NeuralNetworkComponents\NeuralNetwork.h"
#include "NeuralNetworkComponents\BackPropagation.h"
#include "..\Data\TxtFileReader.h"
#include "..\Interfaces\IReadable.h"
#include <vector>
#include <iostream>

/** Klasa menad¿erska s³u¿¹ca do obs³ugi sieci neuronowej */
class NetworkManager
{
private:
	/** Zmienna wskaŸnikowa wskazuj¹ca obiekt NeuralNetwork*/
	NeuralNetwork* network;

	/** WkaŸnijk na obiekt, typu interfejsu IPropagable */
	IPropagable* propagation;

	/** Obiekt Interfejsu IRedable, reprezentujacy klase TXTFileReader */
	IReadable* reader;

	/** Zmienne odpowiadaj¹ce za liczbê neuronów w kolejnych watstwach sieci */
	static const int FIRST_NETWORK = 2, SECOND_NETWORK = 5, THIRD_NETWORK = 1;

	/** Zmienna odpowiedzialna za liczbe warst sieci neuronowej */
	static const int NETWORK_LAYERS = 3; 

	/** Zmienne tymczasowe na wartoœci z pliku (z klasy TXTFileReader) */
	double temp1, temp2, temp3;

	/** Zmienna przechowuj¹ca wielkoœæ tablicy, danych wprowadzonych przez u¿ytkownika */ 
	int dataSize;

	/** Tablica danych wprowadzonych przez uzytkownika */ 
	std::vector<double> data;

	/** Skonwertowana tablica danych */ 
	std::vector<double> convertedData;

	/** Zmienna przechowuj¹ca ostateczny wynik z dzia³ania sieci */
	double finalyNetworkResult;

public:
	double test, zapamietajBlad, p1;

	/** Konstruktor bezargu mentowy klasy Networkmanager */
	NetworkManager(void);

	/** Wirtualny destruktor klasy NetworkManager */
	virtual ~NetworkManager(void);

	/** Metoda s³u¿¹ca do stworzenia sieci neuronowej
	@return network -> stworzona sieæ neuronowa */
	NeuralNetwork* CreateNetwork();

	/** Metoda s³u¿¹ca do usuniêcia sieci neuronowej */
	void DestroyNetwork();

	/** Metoda ucz¹ca sieæ neuronow¹ */
	void TeachNetwork();

	/** Metoda licz¹ca odpowiedŸ sieci 
	@retun result -> wynik obliczeñ sieci, przekazywany do nadrzêdnych metod*/
	double Calculate();

	/** Metoda uruchamiaj¹ca sieæ i zwracaj¹ca wynik 
	@return Wynik -> wynik obliczeñ sieci */
	double RunNetwork();

	/** Getter do finalNetworkResult */ 
	double GetFinalResult()
	{
		return finalyNetworkResult;
	}
};

