//The soft for simulating neural system.
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

const double dt = 0.0001;
const int numneuron = 50;

/*
d(potential)/dt = transinput(input)+damp()
output=outputtrans(potential)
output is input for other neuron.
 */

class Neurons{
private:
  double potential[numneuron];
public:
  Neurons(){
    for(int i = 0;i < numneuron;i++)
      potential[i] = 2.0*(rand() % 1000)/1000;
  }
  double const *getpotential() const {return &(potential[0]);}
  double getpotential(int i) const{return potential[i];}
  double setpotential(int i,double x) {return potential[i] = x;}
};

double differentialEquation(double const potential[],int cellnumber);

{
  double otherCellSum = -1*(potential[cellnumber]);
  for(int i = 0;i < numneuron;i++)
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
  double k1[numneuron],k2[numneuron],k3[numneuron],k4[numneuron];
  double temporaryPotential[numneuron];
  for(int i = 0;i < numneuron;i++){
    k1[i] = differentialEquation(neuron.getpotential(),i);
    temporaryPotential[i] = neuron.getpotential(i) + (1/2)*dt*k1[i];
  }
  for(int i = 0;i < numneuron;i++){
    k2[i] = differentialEquation(temporaryPotential,i);
    temporaryPotential[i] = neuron.getpotential(i) + (1/2)*dt*k2[i];
  }
  for(int i = 0;i < numneuron;i++){
    k3[i] = differentialEquation(temporaryPotential,i);
    temporaryPotential[i] = neuron.getpotential(i) + dt*k3[i];
  }
  for(int i = 0;i < numneuron;i++){
    k4[i] = differentialEquation(temporaryPotential,i);
    neuron.setpotential(i,neuron.getpotential(i) + dt*(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6);
  }
}

template<typename charT, typename traits>
std::basic_ostream<charT, traits>&
operator<<(std::basic_ostream<charT, traits>& os, const Neurons& n)
{
  for(std::size_t i=0; i<n.size(); ++i)
    os << n.getpotential(i) << " ";
  return os;
}

/*void dataOutPut(Neurons& neuron){
  for(int i = 0;i < numneuron;i++)
    fout << neuron.getpotential(i) << " ";
  fout << "\n";
  }*/

int main(int argc, char **argv){
  Neurons neuron;
  ofstream fout("test0.dat");
  fout << 0.0 << " ";
  fout << neuron << std::endl;
  //  for(int i = 0;i < numneuron;i++)
  //  fout << neuron.getpotential(i) << " ";
  // fout << "\n";
  for(int i = 0;i*dt < 10;i++){
    timeevolution(neuron);
    fout << dt*i << " ";
    for(int j = 0;j < numneuron;j++)
      fout << neuron.getpotential(j) << " ";
    fout << "\n";
  }
  return 0;
}
