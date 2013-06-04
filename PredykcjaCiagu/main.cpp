#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Runner\Runner.h"
using namespace std;

int main (int argc, char* argv[])
{
	Runner* runner = new Runner;
	runner->RunProgram();
	//
	Neuron* n = new Neuron(5);
	//vector<double> tab;
	//tab.push_back(0.1);
	//tab.push_back(0.3);
	//tab.push_back(0.9);
	//tab.push_back(0.4);
	//tab.push_back(0.5);
	//n->CalculateNeuronInputsWeights();
	//n->CalculateNeuronOutputFunction(tab);
	
	delete runner;
	delete n;
	system("pause");
	return 0;
}