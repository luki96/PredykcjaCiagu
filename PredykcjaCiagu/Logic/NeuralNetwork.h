#pragma once
#include "Neuron.h"
#include <vector>

class NeuralNetwork
{
  private: 
  
  int network1, network2, network3, flag;
  
  struct NeuronContainer
  {
    std::vector<Neuron> neurons;
    NeuronContainer* next;
  };
  
  NeuronContainer* head;
  NeuronContainer* tail;
  
  NeuronContainer* CreateNetwork();
  
  public:
  
  NeuralNetwork(int, int, int);
  ~virtual NeuralNetwork();
  
};
