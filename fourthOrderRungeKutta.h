//fourthOrderRungeKutta for NeuralNetwork.
#ifndef fourthOrderRungeKutta1
#define fourthOrderRungeKutta1
#include <vector>
#include "declareNeuralNetwork.h"

template<typename T>
void fourthOrderRungeKutta(NeuralNetwork<T>& Network,double dt){
  uint NeuronspSize = (Network.getNeuronsp()).size();
  std::vector<std::vector<T>> originalPotential(NeuronspSize);
  std::vector<std::vector<T>> k1(NeuronspSize),k2(NeuronspSize),k3(NeuronspSize),k4(NeuronspSize);
  
  for(uint i = 0; i < NeuronspSize; ++i)
    originalPotential[i] = (Network.getNeuronsp()[i])->getpotential();

  for(uint i = 0; i < NeuronspSize; ++i){
    T othercellpot = 0;
    for(uint j = 0; j < NeuronspSize; ++j)
      othercellpot += (*Network.getNeuronsp()[j]).getpotential()[0]*(Network.getConnection())[i][j];
    k1[i] = (*Network.getNeuronsp()[i]).differentialEquation(othercellpot);
    (*Network.getNeuronsp()[i]).setpotential(originalPotential[i] + (1.0/2.0)*dt*k1[i]);
  }

    for(uint i = 0; i < NeuronspSize; ++i){
    T othercellpot = 0;
    for(uint j = 0; j < NeuronspSize; ++j)
      othercellpot += (*Network.getNeuronsp()[j]).getpotential()[0]*(Network.getConnection())[i][j];
    k2[i] = (*Network.getNeuronsp()[i]).differentialEquation(othercellpot);
    (*Network.getNeuronsp()[i]).setpotential(originalPotential[i] + (1.0/2.0)*dt*k2[i]);
  }
    
    for(uint i = 0; i < NeuronspSize; ++i){
    T othercellpot = 0;
    for(uint j = 0; j < NeuronspSize; ++j)
      othercellpot += (*Network.getNeuronsp()[j]).getpotential()[0]*(Network.getConnection())[i][j];
    k3[i] = (*Network.getNeuronsp()[i]).differentialEquation(othercellpot);
    (*Network.getNeuronsp()[i]).setpotential(originalPotential[i] + dt*k3[i]);
  }

    for(uint i = 0; i < NeuronspSize; ++i){
    T othercellpot = 0;
    for(uint j = 0; j < NeuronspSize; ++j)
      othercellpot += (*Network.getNeuronsp()[j]).getpotential()[0]*(Network.getConnection())[i][j];
    k4[i] = (*Network.getNeuronsp()[i]).differentialEquation(othercellpot);
    (*Network.getNeuronsp()[i]).setpotential(originalPotential[i] + dt*(k1[i]+2.0*k2[i]+2.0*k3[i]+k4[i])/6.0);
  }
}

#endif
