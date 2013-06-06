#include "NeuralNetwork.h"


NeuralNetwork::NeuralNetwork(int network1, int network2, int network3)
{
  this->network1 = network1;
  this->network2 = network2;
  this->network3 = network3;
  flag = 0;
  
  head =  NULL;
  tail = NULL;
  
}

NeuralNetwork::~NeuralNetwork()
{
  while (head != NULL)
  {
    NeuralContainer* temp = head;
    head = head->next;  
    temp->neurons.erase();
    delete temp;
  }
}

NeuronContainer NeuralNetwork::CreateNetwork()
{
  if (head == NULL)
  {
    head = new NeuronContainer;
    
    for (int i = 0; i < network1; i++)
    {
      head->neurons.push_back(new Neuron(1)); 
    }
    
    head->next = NULL;
    tail = head;
    flag = 1;
  }
  else if (flag == 1)
  {
    head->next = new NeuronContainer;
    tail = head->next;
    
    for (int i =0; i < network2; i++)
    {
      tail->neurons.push_back(new Neuron(2));
    }
    
    tail->next = NULL;
    flag = 2;
  }
  else 
  {
    tail->next = new NeuronContainer;
    tail = tail->next;
    
    for (int i =0; i < network3; i++)
    {
      tail->neurons.push_back(new Neuron(5));
    }
    
    tail->next = NULL;
  }
  
  return head;
}

