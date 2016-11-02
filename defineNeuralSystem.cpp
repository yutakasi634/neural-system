//defineNeuralSystem.cpp
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <random>
#include "declareNeuralSystem.h"

Neurons::Neurons(int num){
  std::mt19937 mt(0);
  std::uniform_real_distribution<double> rand2(0,2.0);
  numneuron = num;
  potential.reserve(numneuron);
  for(uint i = 0;i < numneuron;i++)
    potential.push_back(rand2(mt));
}

const std::vector<double>& Neurons::getpotential() const{
   return potential;
}

int theta(double x){
  int result;
  if(x >= 0)
    result = 1;
  else
    result = 0;
  return result;
}

void timeevolution(Neurons& neuron,double dt){/*class is avalable for argument.*/
  std::vector<double> k1(neuron.getneuronnum()),k2(neuron.getneuronnum()),k3(neuron.getneuronnum()),k4(neuron.getneuronnum());
  std::vector<double> temporaryPotential(neuron.getneuronnum());
  for(uint i = 0;i < neuron.getneuronnum();i++){
    k1[i] = differentialEquation(neuron.getpotential(),i);
    temporaryPotential[i] = (neuron.getpotential())[i] + (1/2)*dt*k1[i];
  }
  for(uint i = 0;i < neuron.getneuronnum();i++){
    k2[i] = differentialEquation(temporaryPotential,i);
    temporaryPotential[i] = (neuron.getpotential())[i] + (1/2)*dt*k2[i];
  }
  for(uint i = 0;i < neuron.getneuronnum();i++){
    k3[i] = differentialEquation(temporaryPotential,i);
    temporaryPotential[i] = (neuron.getpotential())[i] + dt*k3[i];
  }
  for(uint i = 0;i < neuron.getneuronnum();i++){
    k4[i] = differentialEquation(temporaryPotential,i);
    neuron.setpotential(i,(neuron.getpotential())[i] + dt*(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6);
  }
}
