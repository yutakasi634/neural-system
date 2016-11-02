//defineForNeuralSystem.h
#ifndef NEURAL1
#define NEURAL1
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>

class Neurons{
private:
  std::vector<double> potential;
  std::size_t numneuron;
public:
  Neurons(int num);
  const std::vector<double>& getpotential() const;
  const std::size_t getneuronnum() const {return numneuron;}
  double setpotential(int i,double x) {return potential[i] = x;}
};

template<typename T>//主にvectorが入る
double differentialEquation(const std::vector<T>& potential,int cellnumber){
  T otherCellSum = -1*(potential[cellnumber]);
  for(typename std::vector<T>::const_iterator i = potential.begin();i != potential.end(); ++i)//typenameをつけないとstd::vector<T>::iteratorが型と認識されない
    //const std::vector<T>のiteratorはconst_iteratorになる
    otherCellSum += *i;
  double dpdt = 1/(1+exp(otherCellSum))-potential[cellnumber];    
  return dpdt;
}

template<typename charT, typename traits> //typenameもclassも実用上相違はない
std::basic_ostream<charT, traits>&
operator<<(std::basic_ostream<charT, traits>& os, const Neurons& n)
{
  for(std::size_t i=0; i<n.getneuronnum(); ++i)//size関数を定義する必要がある
    os << (n.getpotential())[i] << " ";
  return os;
}

int theta(double x);

void timeevolution(Neurons& neuron,double dt);

#endif
