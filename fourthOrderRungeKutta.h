//fourthOrderRungeKutta for NeuralNetwork.
#ifndef fourthOrderRungeKutta1
#define fourthOrderRungeKutta1
#include <vector>
#include "declareNeuralNetwork.h"

template<typename T>
void fourthOrderRungeKutta(NeuralNetwork& Network,double dt){/*class is avalable for argument.*/
  std::vector<std::vector<T>> k1,k2,k3,k4;
  std::vector<std::vector<T>> originalPotential;
  uint NeuronsSize = (Network.getpotential()).size();

  for(uint i = 0; i < NeuronSize; ++i)
    originalPotential[i] = (Network.getNeurons())[i];

  for(uint i = 0; i < NeuronSize; ++i){
    T othercellpot = 0;
    for(uint j = 0; j < NeuronSize; ++j)
      othercellpot += (Network.getNeurons())[j][0]*(Network.getConnection())[i][j];
    k1[i] = (Network.getNeurons())[i].differentialEquation(othercellpot);
    (Network.getNeurons())[i].setpotential(originalPotential[i] + (1.0/2.0)*dt*k1[i]);
  }

    for(uint i = 0; i < NeuronSize; ++i){
    T othercellpot = 0;
    for(uint j = 0; j < NeuronSize; ++j)
      othercellpot += (Network.getNeurons())[j][0]*(Network.getConnection())[i][j];
    k2[i] = (Network.getNeurons())[i].differentialEquation(othercellpot);
    (Network.getNeurons())[i].setpotential(originalPotential[i] + (1.0/2.0)*dt*k2[i]);
  }
    
    for(uint i = 0; i < NeuronSize; ++i){
    T othercellpot = 0;
    for(uint j = 0; j < NeuronSize; ++j)
      othercellpot += (Network.getNeurons())[j][0]*(Network.getConnection())[i][j];
    k3[i] = (Network.getNeurons())[i].differentialEquation(othercellpot);
    (Network.getNeurons())[i].setpotential(originalPotential[i] + dt*k3[i]);
  }

    for(uint i = 0; i < NeuronSize; ++i){
    T othercellpot = 0;
    for(uint j = 0; j < NeuronSize; ++j)
      othercellpot += (Network.getNeurons())[j][0]*(Network.getConnection())[i][j];
    k4[i] = (Network.getNeurons())[i].differentialEquation(othercellpot);
    (Network.getNeurons())[i].setpotential(originalPotential[i] + dt*(k1[i]+2.0*k2[i]+2.0*k3[i]+k4[i])/6.0);
  }
}

#endif