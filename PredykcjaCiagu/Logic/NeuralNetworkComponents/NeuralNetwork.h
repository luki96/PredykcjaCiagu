#pragma once
#include <vector>
#include "Neuron.h"

/** Klasa  odpowiadaj¹ca za sieæ neuronow¹ */
class NeuralNetwork
{
private: 
	/** Prywatne zmienne odpowiadaj¹ce wielkoœci sieci i flaga do obs³ugi w/w sieci */ 
	int network1, network2, network3, flag;

public:

	/** Konstruktor trój-argumentowy klasy NeuralNetwork (przekazywane s¹, wielkoœci poszczególnych warstw siecii) */
	NeuralNetwork(int, int, int);

	/** Wirtualny destruktor klasy NeuralNetwork */
	virtual ~NeuralNetwork();

	/** Struktura danych przechowuj¹ca kolejne warstwy sieci neuronowej */
	struct NeuronContainer
	{
		/** Tablica wskaŸników na neurony w poszczególnych warstwach sieci */
		std::vector<Neuron*> neurons;

		/** WskaŸnik na kolejn¹ warstwê */
		NeuronContainer* next;
	};

	/** WskaŸnik na pierwsz¹ warstwê sieci */
	NeuronContainer* head;

	/** WskaŸnik na ostatni¹ warstwê sieci */
	NeuronContainer* tail;

	/** Metoda odpowiedzialna, za stworzenie siecii neuronowej */
	NeuronContainer* CreateNetwork();

};
