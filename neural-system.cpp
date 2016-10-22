//The soft for simulating neural system.
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

double dt = 0.001;
int numneuron = 2;

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
      potential = 2.0*(rand() % 1000);
  }
  double getpotential() const{return potential[]};
  double getpotential(int i) const{return potential[i]}
  double setpotential(int i,double x) {potential[i] = x};
};

double differentialEquation(double potential[],int cellnumber){
  double otherCellSum = -1*(potential[cellnumber]);
  for(int i = 0;i < numneuron;i++)
    otherCellSum += potential[i];
  double dpdt = 1/(1+exp(potential[otherCellSum]))-potential[cellnumber];    
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
    k1[i] = differentialEquation(Neurons.getpotential(),i);
    temporaryPotential[i] = Neurons.getpotential(i) + (1/2)*dt*k1[i];
  }
  for(int i = 0;i < numneuron;i++){
    k2[i] = differentialEquation(temporaryPotential[],i);
    temporaryPotential[i] = Neurons.getpotential(i) + (1/2)*dt*k2[i];
  }
  for(int i = 0;i < numneuron;i++){
    k3[i] = differentialEquation(temporaryPotential[],i);
    temporaryPotential[i] = Neurons.getpotential(i) + dt*k3[i];
  }
  for(int i = 0;i < numneuron;i++){
    k4[i] = differentialEquation(temporaryPotential[],i);
    setpotential(i,getpotential(i) + (k1[i]+2*k2[i]+2*k3[i]+k4[i])/6);
  }
}

void dataOutPut(Neurons neuron){
  for(i = 0;i < numneuron;i++)
    test0.dat << getpotential(i) << " ";
  test0.dat << "\n"
}

int main{
  ofstream fout("test0.dat")
  Neurons neuron;
  dataOutPut(neuron)
  for(i = 0;i*dt < 100;i++){
    timeevolution(neuron);
    dataOutPut(neuron)
  }
  return 0;
}
