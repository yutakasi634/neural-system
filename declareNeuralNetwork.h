//Declare for NeuralNetwork class.
#ifndef declareNeuralNetwork1
#define declareNeuralNetwork1
#include <vector>
#include <memory>
#include "declareNeuron.h"
#include "operatorForVector.h"

template<typename T>
class NeuralNetwork{
protected:
  std::vector<std::shared_ptr<Neuron<T>>> Neuronsp;
  std::vector<std::vector<double>> ConnectionMatrix;
public:
  NeuralNetwork(uint NumOfNeuronA,uint NumOfNeuronB);
  std::vector<std::shared_ptr<Neuron<T>>> const& getNeuronsp() const;
  std::vector<std::vector<double>> const& getConnection() const;
};

template<typename T>
NeuralNetwork<T>::NeuralNetwork(uint NumOfNeuronA,uint NumOfNeuronB){
  Neuronsp.reserve(NumOfNeuronA+NumOfNeuronB);
  for(uint i = 0; i < NumOfNeuronA; ++i){
    std::shared_ptr<Neuron<T>> pA(new NeuronTypeA<T>());
    Neuronsp.push_back(pA);
  }

  for(uint i = 0; i < NumOfNeuronB; ++i){
    std::shared_ptr<Neuron<T>> pB(new NeuronTypeB<T>());
    Neuronsp.push_back(pB);
  }

  ConnectionMatrix.resize(Neuronsp.size());
  for(uint i = 0; i < Neuronsp.size(); ++i){
    ConnectionMatrix.at(i).resize(Neuronsp.size());
    for(uint j = 0; j < Neuronsp.size(); ++j){
      if(i == j)
	ConnectionMatrix.at(i).at(j) = 1;
      else
	ConnectionMatrix.at(i).at(j) = 1;
    }
  }
}

template<typename T>
std::vector<std::shared_ptr<Neuron<T>>> const& NeuralNetwork<T>::getNeuronsp() const{
  return Neuronsp;
}

template<typename T>
std::vector<std::vector<double>> const& NeuralNetwork<T>::getConnection() const{
  return ConnectionMatrix;
}


#endif
