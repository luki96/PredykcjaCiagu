#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "NeuralNetworkComponents\Neuron.h"
#include "NeuralNetworkComponents\NeuralNetwork.h"
#include "NeuralNetworkComponents\BackPropagation.h"
#include "..\Data\TxtFileReader.h"
#include "..\Data\TxtFileWriter.h"
#include "..\Interfaces\IReadable.h"
#include "..\Interfaces\IWritable.h"

/** Klasa menad¿erska s³u¿¹ca do obs³ugi sieci neuronowej */
class NetworkManager
{
private:
	/** Tablica przechowuj¹ca sugerowane wyniki */
	std::vector<double> tabWynik;

	/** Zmienna wskaŸnikowa wskazuj¹ca obiekt NeuralNetwork */
	NeuralNetwork* network;

	/** Wska¿nik na obiekt, typu interfejsu IPropagable */
	IPropagable* propagation;

	/** Obiekt Interfejsu IReadable, reprezentuj¹cy klasê TxtFileReader */
	IReadable* reader;

	/** Obiekt Interfejsu IWritable, reprezentuj¹cy klasê TxtFileWriter */
	IWritable* writer;

	/** Zmienne odpowiadaj¹ce za liczbê neuronów w kolejnych watstwach sieci */
	static const int FIRST_NETWORK = 2, SECOND_NETWORK = 5, THIRD_NETWORK = 1;

	/** Zmienna odpowiedzialna za liczbê warstw sieci neuronowej */
	static const int NETWORK_LAYERS = 3; 

	/** Zmienne tymczasowe na wartoœci z pliku (z klasy TxtFileReader) */
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
	/** Zmienne pomocnicze */ 
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
	@retun result -> wynik obliczeñ sieci, przekazywany do nadrzêdnych metod */
	double Calculate();

	/** Metoda uruchamiaj¹ca sieæ i zwracaj¹ca wynik 
	@return Wynik -> wynik obliczeñ sieci */
	double RunNetwork();

	/** Metoda s³u¿¹ca do eksportu wyników do pliku 
	@param std::string fName Œcie¿ka do pliku
	@param std::vector<double> data Dane, które nale¿y zapisaæ
	*/
	void SaveToFile(std::string fName, std::vector<double> data);

	/** Getter do finalNetworkResult 
	@return double finalna odpowiedŸ sieci (przewidziany wyraz ci¹gu)
	*/ 
	double GetFinalResult()
	{
		return finalyNetworkResult;
	}
};

