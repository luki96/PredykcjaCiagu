#pragma once
#include "NeuralNetworkComponents\Neuron.h"
#include "NeuralNetworkComponents\NeuralNetwork.h"
#include "NeuralNetworkComponents\BackPropagation.h"
#include "..\Data\TxtFileReader.h"
#include "..\Interfaces\IReadable.h"
#include "..\Logic\DataConverter.h"
#include <vector>
#include <iostream>

/** Klasa menadøerska s≥uøπca do obs≥ugi sieci neuronowej */
class NetworkManager
{
private:
	/** Zmienna wskaünikowa wskazujπca obiekt NeuralNetwork*/
	NeuralNetwork* network;

	/** Wkaünijk na obiekt, typu interfejsu IPropagable */
	IPropagable* propagation;

	/** Obiekt Interfejsu IRedable, reprezentujacy klase TXTFileReader */
	IReadable* reader;

	/** Wskaünik na obiekt klasy odpowiadajπcy za konwertowanie danych do przedzialu <0,1) */ 
	DataConverter* converter;

	/** Zmienne odpowiadajπce za liczbÍ neuronÛw w kolejnych watstwach sieci */
	static const int FIRST_NETWORK = 2, SECOND_NETWORK = 5, THIRD_NETWORK = 1;

	/** Zmienna odpowiedzialna za liczbe warst sieci neuronowej */
	static const int NETWORK_LAYERS = 3; 

	/** Zmienne tymczasowe na wartoúci z pliku (z klasy TXTFileReader) */
	double temp1, temp2, temp3;

	/** Zmienna przechowujπca wielkoúÊ tablicy, danych wprowadzonych przez uøytkownika */ 
	int dataSize;

	/** Tablica danych wprowadzonych przez uzytkownika */ 
	std::vector<int> data;

	/** Skonwertowana tablica danych */ 
	std::vector<double> convertedData;

	/** Zmienna przechowujπca ostateczny wynik z dzia≥ania sieci */
	double finalyNetworkResult;

public:
	/** Konstruktor bezargu mentowy klasy Networkmanager */
	NetworkManager(void);

	/** Wirtualny destruktor klasy NetworkManager */
	virtual ~NetworkManager(void);

	/** Metoda s≥uøπca do stworzenia sieci neuronowej
	@return network -> stworzona sieÊ neuronowa */
	NeuralNetwork* CreateNetwork();

	/** Metoda s≥uøπca do usuniÍcia sieci neuronowej */
	void DestroyNetwork();

	/** Metoda uczπca sieÊ neuronowπ */
	void TeachNetwork();

	/** Metoda liczπca odpowiedü sieci 
	@retun result -> wynik obliczeÒ sieci, przekazywany do nadrzÍdnych metod*/
	double Calculate();

	/** Metoda uruchamiajπca sieÊ i zwracajπca wynik 
	@return Wynik -> wynik obliczeÒ sieci */
	double RunNetwork();

	/** Getter do finalNetworkResult */ 
	double GetFinalResult()
	{
		return finalyNetworkResult;
	}
};

