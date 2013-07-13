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

	/** Wylosowana waga wejscia dla neuronu */
	double weight;

	/** Wartoœæ bias (dobiorana na pocz¹tku losowo) */
	double bias;

	/** Wartosc funkcji wyjscia z neuronu czyli suma kazdego z wejsc razy odpowiednia waga przypisana temu wejsciu */
	double outputFunction;

	/** Tablica zawierajaca wage kazedego wejscia neuronu */
	std::vector<double> weightsOfNeuronInputs;

	/** Gradient klasy neuron */ 
	double gradient;

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
		return this->outputFunction;
	}

	/** Getter dla pola weight 
	@return Wartosc wylosowanej wagi dla 
	*/
	std::vector<double> GetWeight()
	{
		return weightsOfNeuronInputs;
	}

	/** Setter dla pola weight 
	@param Nowa wartosc wagi*/
	void SetWeight(std::vector<double> weights)
	{
		this->weightsOfNeuronInputs.clear();
		this->weightsOfNeuronInputs.swap(weights);
	}

	/** Getter do zmiennej gradient */ 
	double GetGradient()
	{
		return this->gradient;
	}

	/** Setter do zmiennej gradient */ 
	void SetGradient(double tGradient)
	{
		this->gradient = tGradient;
	}

	/** Getter do zmiennej bias */
	double GetBias()
	{
		return bias;
	}

	/** Setter do zmiennej bias */
	void  SetBias(double tBias)
	{
		this->bias = tBias;
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




/*
 
	
	double GetWeight()
	{
		return this->weight;
	}

	void SetWeight(double weight)
	{
		this->weight = weight;
	}
	
	*/