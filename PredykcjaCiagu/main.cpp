#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <crtdbg.h>
#include "Logic\NeuralNetworkComponents\Neuron.h"
#include "Runner\Runner.h"
#include "Interfaces\IReadable.h"
#include "Logic\NeuralNetworkComponents\NeuralNetwork.h"
#include "Logic\DataConverter.h"
#include "Logic\FileManager.h"
#include "Data\TxtFileReader.h"

using namespace std;

int main (int argc, char* argv[])
{
	Runner* runner = new Runner;
	runner->RunProgram();
	//Neuron* n = new Neuron(5);
	//vector<double> tab;
	//tab.push_back(0.1);
	//tab.push_back(0.3);
	//tab.push_back(0.9);
	//tab.push_back(0.4);
	//tab.push_back(0.5);
	//n->CalculateNeuronInputsWeights();
	//n->CalculateNeuronOutputFunction(tab);
	
	//delete runner;
	//delete n;

	DataConverter* dc = new DataConverter;
	FileManager* fm = new FileManager;
	fm->ireader->ReadFile("a.txt");
	dc->ConvertDataToSigmoidFunctionRange(fm->ireader->GetData());

	NeuralNetwork* nn = new NeuralNetwork(1, 2, 5);
	nn->CreateNetwork();
	nn->CreateNetwork();
	nn->CreateNetwork();
	nn->~NeuralNetwork();

	delete nn;
	delete dc;
	delete fm;
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}