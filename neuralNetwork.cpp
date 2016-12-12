//Function of NeuralNetwork class.
#include <vector>
#include "declareNeuron.h"
#include "declareNeuralNetwork.h"
#include "operatorForVector.h"

NeuralNetwork::NeuralNetwork(uint NumOfNeuronA,uint NumOfNeuronB){
  for(uint i = 0; i < NumOfNeuronA; ++i){
    NeuronTypeA<double> neuronA;
    Neurons.push_back(neuronA);
  }

  for(uint i = 0; i < NumOfNeuronB; ++i){
    NeuronTypeB<double> neuronB;
    Neurons.push_back(neuronB);
  }

  for(uint i = 0; i < Neurons.size(); ++i){
    for(uint j = 0; j < Neurons.size(); ++ j){
      if(i == j)
	ConnectionMatrix[i][j] = 1;
      else
	ConnectionMatrix[i][j] = 1;
    }
  }
}

std::vector<Neuron>& NeuralNetwork::getNeurons() const{
  return Neurons;
}

std::vector<std::vector<double>>& NeuralNetwork::getConnection() const{
  return ConnectionMatrix;
}

#endif
