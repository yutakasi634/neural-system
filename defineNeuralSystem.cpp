//The soft for simulating neural system.
#include <fsteram>
#include <vector>
#include "declareNeuralSystem.h"
#include "operatorForVector.h"

class NeuralNetwork{
protected:
  std::vector<Neuron> Neurons;
  std::vector<std::vector<double>> ConnectionMatrix;
public:
  NeuralNetwork();
};

NeuralNetwork::NeuralNetwork(){
  NeuronTypeA<double> neuronA;
  NeuronTypeB<double> neuronB;
  Neurons.push_back(neuronA);
  Neurons.push_back(neuronB);
  for(uint i = 0; i < Neurons.size(); ++i){
    for(uint j = 0; j < Neurons.size(); ++ j){
      if(i == j)
	ConnectionMatrix[i][j] = 1;
      else
	ConnectionMatrix[i][j] = 1;
    }
  }
};
