#pragma once
#include <ctime>
#include <math.h>
#include <vector>

/** Klasa reprezentuje pojedynczy neuron sieci */
class Neuron
{
private:

	/** Dolne ograniczenie przedzialu wag */
	const double LOWER_LIMIT_WEIGHTS_RANGE;

	/** Gorne ograniczenie przedzialu wag */
	const double UPPER_LIMIT_WEIGHTS_RANGE;

	/** Ilosc wejsc w neuronie */
	int numberOfNeuronInputs;

	/** Wartosc funkcji wyjscia z neuronu czyli suma kazdego z wejsc razy odpowiednia waga przypisana temu wejsciu */
	double outputFunction;

	/** Tablica zawierajaca wage kazedego wejscia neuronu */
	std::vector<double> weightsOfNeuronInputs;

public:

	/** Konstruktor klasy Neuron przyjmujacy jako argument ilosc wejsc pojedynczego neuronu */
	Neuron(int numberOfNeuronInputs);
	
	/** Destruktor klasy Neuron */
	~Neuron(void);

	/** Getter dla pola outputFunction 
	@return Wartosc funkcji wyjscia z neuronu
	*/
	double GetOutputFunction()
	{
		return outputFunction;
	}
	
	/** Metoda oblicza wagi dla kazdego z wejsc pojedynczego neuronu 
	@return true gdy uda sie obliczyc wagi dla wszystkich wejsc neuronu.
	W przeciwnym wypadku wartoscia zwracana jest false
	*/
	bool CalculateNeuronInputsWeights();

	/** Metoda oblicza wartosc funkcji wyjscia z neuronu 
	@param std::vector<double> neuronInputData Tablica zawierajaca dane wejsciowe
	podawane na kolejne wejscia pojedynczego neuronu
	*/
	void CalculateNeuronOutputFunction(std::vector<double> neuronInputData);
};