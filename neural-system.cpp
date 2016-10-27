//The soft for simulating neural system.
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>

using namespace std;

const double dt = 0.0001;

class Neurons{
private:
  std::vector<double> potential;
  std::size_t numneuron;
public:
  Neurons(int num){
    numneuron = num;
    for(int i = 0;i < numneuron;i++)
      potential.push_back(2.0*(rand() % 1000)/1000);
  }
  double *getpotential() const {return potential.data();}
  double getpotential(int i) const{return potential[i];}
  double setpotential(int i,double x) {return potential[i] = x;}
};

double differentialEquation(double* potential,int cellnumber){
  double otherCellSum = -1*(potential[potential.size()]);
  for(int i = 0;i < potential.size();i++)
    otherCellSum += potential[i];
  double dpdt = 1/(1+exp(otherCellSum))-potential[cellnumber];    
  return dpdt;
}

int theta(double x){
  int result;
  if(x >= 0)
    result = 1;
  else
    result = 0;
  return result;
}

void timeevolution(Neurons& neuron){/*class is avalable for argument.*/
  std::vector<double> k1[neuron.size()],k2[neuron.size()],k3[neuron.size()],k4[neuron.size()];
  double temporaryPotential[neuron.size()];
  for(int i = 0;i < neuron.size();i++){
    k1[i] = differentialEquation(neuron.getpotential(),i);
    temporaryPotential[i] = neuron.getpotential(i) + (1/2)*dt*k1[i];
  }
  for(int i = 0;i < neuron.size();i++){
    k2[i] = differentialEquation(temporaryPotential,i);
    temporaryPotential[i] = neuron.getpotential(i) + (1/2)*dt*k2[i];
  }
  for(int i = 0;i < neuron.size();i++){
    k3[i] = differentialEquation(temporaryPotential,i);
    temporaryPotential[i] = neuron.getpotential(i) + dt*k3[i];
  }
  for(int i = 0;i < neuron.size();i++){
    k4[i] = differentialEquation(temporaryPotential,i);
    neuron.setpotential(i,neuron.getpotential(i) + dt*(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6);
  }
}

template<typename charT, typename traits> //typenameもclassも実用上相違はない
std::basic_ostream<charT, traits>&
operator<<(std::basic_ostream<charT, traits>& os, const Neurons& n)
{
  for(std::size_t i=0; i<n.size(); ++i)//size関数を定義する必要がある
    os << n.getpotential(i) << " ";
  return os;
}

/*void dataOutPut(Neurons& neuron){
  for(int i = 0;i < neuron.size();i++)
    fout << neuron.getpotential(i) << " ";
  fout << "\n";
  }*/

int main(int argc, char **argv){
  Neurons neuron;
  std::ofstream fout("test0.dat");
  fout << 0.0 << " ";
  fout << neuron << std::endl;
  //  for(int i = 0;i < neuron.size();i++)
  //  fout << neuron.getpotential(i) << " ";
  // fout << "\n";
  for(int i = 0;i*dt < 10;i++){
    timeevolution(neuron);
    fout << dt*i << " ";
    for(int j = 0;j < neuron.size();j++)
      fout << neuron.getpotential(j) << " ";
    fout << "\n";
  }
  return 0;
}
