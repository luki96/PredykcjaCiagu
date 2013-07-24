#pragma once
#include <ctime>
#include <math.h>
#include <vector>

/** Klasa reprezentuje pojedynczy neuron sieci */
class Neuron
{
private:

	/** Dolne ograniczenie przedzia³u wag */
	const double LOWER_LIMIT_WEIGHTS_RANGE;

	/** Gorne ograniczenie przedzia³u wag */
	const double UPPER_LIMIT_WEIGHTS_RANGE;

	/** Iloœæ wejœæ w neuronie */
	int numberOfNeuronInputs;

	/** Wylosowana waga wejœcia dla neuronu */
	double weight;

	/** Wartoœæ bias (dobierana na pocz¹tku losowo) */
	double bias;

	/** Wartoœæ funkcji wyjœcia z neuronu czyli suma ka¿dego z wejœæ razy odpowiednia waga przypisana temu wejœciu */
	double outputFunction;

	/** Tablica zawierajaca wagê ka¿dego wejœcia neuronu */
	std::vector<double> weightsOfNeuronInputs;

	/** Gradient klasy neuron */ 
	double gradient;

public:

	/** Konstruktor klasy Neuron 
	@param int numberOfNeuronInputs Iloœæ wejœæ pojedynczego neuronu */
	Neuron(int numberOfNeuronInputs);
	
	/** Destruktor klasy Neuron */
	~Neuron(void);
	
	/** Getter dla pola outputFunction 
	@return Wartoœæ funkcji wyjœcia z neuronu
	*/
	double GetOutputFunction()
	{
		return this->outputFunction;
	}

	/** Getter dla pola weightsOfNeuronInputs 
	@return std::vector<double> weightsOfNeuronInputs Tablica zawierajaca wagê ka¿dego wejœcia neuronu
	*/
	std::vector<double> GetWeight()
	{
		return weightsOfNeuronInputs;
	}

	/** Setter dla pola weightsOfNeuronInputs 
	@param std::vector<double> weights Tablica z nowymi wagami
	*/
	void SetWeight(std::vector<double> weights)
	{
		this->weightsOfNeuronInputs.clear();
		this->weightsOfNeuronInputs.swap(weights);
	}

	/** Getter do zmiennej gradient 
	@return double gradient Oblicozny gradient
	*/ 
	double GetGradient()
	{
		return this->gradient;
	}

	/** Setter do zmiennej gradient 
	@param double tGradient Nowa wartoœæ gradientu
	*/ 
	void SetGradient(double tGradient)
	{
		this->gradient = tGradient;
	}

	/** Getter do zmiennej bias 
	@return double bias Wartoœæ wspó³czynnika korekcji
	*/
	double GetBias()
	{
		return this->bias;
	}

	/** Setter do zmiennej bias 
	@param double Nowa wartoœæ wspó³czynnika korekcji
	*/
	void  SetBias(double tBias)
	{
		this->bias = tBias;
	}

	/** Getter do pojedynczej wagi neurona 
	@param int whichInput Okreœla, z którego wejœcia chcemy pobraæ wagê
	@return double Wartoœæ pobranej wagi
	*/
	double GetOneWeight(int whichInput)
	{
		return weightsOfNeuronInputs[whichInput];
	}

	/** Setter do pojedynczej wagi neuronu 
	@param int whichInput Okreœla, które wejœcie chcemy modyfikowaæ
	@param double tWeight Nowa wartoœæ wagi
	*/
	void SetOneWeight(int whichInput, double tWeight)
	{
		weightsOfNeuronInputs[whichInput] = tWeight;
	}
	
	/** Metoda oblicza wagi dla ka¿dego z wejœæ pojedynczego neuronu 
	@return true gdy uda siê obliczyæ wagi dla wszystkich wejœæ neuronu.
	W przeciwnym wypadku wartosci¹ zwracan¹ jest false
	*/
	bool CalculateNeuronInputsWeights();

	/** Metoda oblicza wartoœæ funkcji wyjœcia z neuronu 
	@param std::vector<double> neuronInputData Tablica zawieraj¹ca dane wejœciowe
	podawane na kolejne wejœcia pojedynczego neuronu
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