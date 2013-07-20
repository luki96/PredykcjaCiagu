#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <crtdbg.h>
#include "Logic\NeuralNetworkComponents\Neuron.h"
#include "Runner\Runner.h"
#include "Interfaces\IReadable.h"
#include "Logic\NeuralNetworkComponents\NeuralNetwork.h"
#include "Logic\FileManager.h"
#include "Data\TxtFileReader.h"
#include "Logic\NetworkManager.h"

using namespace std;

/** G³ówna klasa programu */
int main (int argc, char* argv[])
{
//Runner* runner = new Runner;
//runner->RunProgram();
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

//DataConverter* dc = new DataConverter;
//FileManager* fm = new FileManager;
//fm->ireader->ReadFile("a.txt");
//dc->ConvertDataToSigmoidFunctionRange(fm->ireader->GetData());
//n->CalculateNeuronInputsWeights();
//n->CalculateNeuronOutputFunction(dc->GetConvertedData());

NetworkManager* network = new NetworkManager();

network -> RunNetwork();
double result = network->GetFinalResult();
//result = log (result / (1 -result));
cout << "Kolejnym przewidywanym elementem ciagu liczbowego jest: " << result << endl;


//NeuralNetwork* nn = new NeuralNetwork(1, 2, 5);
//nn->CreateNetwork();
//nn->CreateNetwork();
//nn->CreateNetwork();
//nn->~NeuralNetwork();

//delete nn;
//delete dc;
//delete fm;
delete network;
_CrtDumpMemoryLeaks();
system("pause");
return 0;
}