//Declare for NeuralNetwork class.
#ifndef declareNeuralNetwork1
#define declareNeuralNetwork1
#include <vector>
#include "declareNeuron.h"

class NeuralNetwork{
protected:
  std::vector<Neuron> Neurons;
  std::vector<std::vector<double>> ConnectionMatrix;
public:
  NeuralNetwork(uint NumOfNeuronA,uint NumOfNeuronB);
  std::vector<Neuron> const& getNeurons() const;
  std::vector<std::vector<double>> const& getConnection() const;
};

#endif
