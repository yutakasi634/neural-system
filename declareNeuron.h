//Declare and define for Neuron class.
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
  std::vector<T> differentialEquation(const T& othercellpot) const override;
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
  std::vector<T> differentialEquation(const T& othercellpoto) const override;
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
