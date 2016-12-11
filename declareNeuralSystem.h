//defineForNeuralSystem.h
#ifndef NEURAL1
#define NEURAL1
#include "operatorForVector.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <random>

template<typename T>//主にdoubleが入る
class Neuron{
protected:
  std::vector<T> potential;
public:
  Neuron(uint num);
  const std::vector<T>& getpotential() const;
  void setpotential(std::vector<T> x) {potential = x;}
  virtual std::vector<T> differentialEquation() const = 0;
};

template<typename T>
Neuron<T>::Neuron(uint num){
  std::mt19937 mt(0);
  std::uniform_real_distribution<T> rand2(0,2);
  potential.reserve(num);
  potential.push_back(0.0);
  potential.push_back(1.0); 
  potential.push_back(0.0); 
}

template<typename T>
const std::vector<T>& Neuron<T>::getpotential() const{
  return potential;
}

//派生クラスNeuronTypeAの実装
template<typename T>
class NeuronTypeA : public Neuron<T>{
public:
  NeuronTypeA();
  std::vector<T> differentialEquation() const override;
};

template<typename T>
NeuronTypeA<T>::NeuronTypeA() : Neuron<T>(3) {}

template<typename T>
std::vector<T> NeuronTypeA<T>::differentialEquation(const T& othercellpot) const{
  std::vector<T> dpdt;
  dpdt.resize(Neuron<T>::potential.size());
  dpdt[0] = 10*(this->potential[1] - this->potential[0]);
  dpdt[1] = 28*this->potential[0] - this->potential[1] - this->potential[0]*this->potential[2];
  dpdt[2] = this->potential[0]*this->potential[1] - (8.0/3.0)*this->potential[2];
  return dpdt;
}
//名前検索の関係でNeuronを明示しないといけない、らしい？？？ this->の方が直感的なので良いかも

template<typename T>
class NeuronTypeB : public Neuron<T>{
 public:
  NeuronTypeB();
  std::vector<T> differentialEquation(const T) const override;
};

template<typename T>
NeuronTypeB<T>::NeuronTypeB() : Neuron<T>(3) {}

template<typename T>
std::vector<T> NeuronTypeB<T>::differentialEquation(const T& othercellpot) const{
  std::vector<T> dpdt;
  dpdt.resize(Neuron<T>::potential.size());
  dpdt[0] = 10*(this->potential[1] - this->potential[0]);
  dpdt[1] = 28*othercellpot - this->potential[1] - othercellpot*this->potential[2];
  dpdt[2] = othercellpot*this->potential[1] - (8.0/3.0)*this->potential[2];
  return dpdt;
}

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

template<typename T>
int theta(T x){
  int result;
  if(x >= 0)
    result = 1;
  else
    result = 0;
  return result;
}

//Neuronについての<<演算子の宣言（定義）
template<typename T,typename charT, typename traits> //typenameもclassも実用上相違はない
std::basic_ostream<charT, traits>&
operator<<(std::basic_ostream<charT, traits>& os, const Neuron<T>& n)
{
  for(std::size_t i=0; i < (n.getpotential()).size(); ++i)
    os << (n.getpotential())[i] << " ";
  return os;
}

#endif
