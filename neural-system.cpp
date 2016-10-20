
//The soft for simulating neural system.
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
  double getpotential(int i) const{return potential[i]};
  double setpotential(int i,double x) {potential[i] = x};
};

double differentialEquation(double input,double potential){
  double dpdt = 1/(1+exp(input)) - potential;
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

int timeevolution(Neurons neurons){/*class is avalable for argument.*/
  double k1[numneuron],k2[numneuron],k3[numneuron],k4[numneuron];
  double sum = 0.0;
  for(int i = 0;i < numneuron;i++)
    sum += neurons.getpotential[i];
  for(int i = 0;i < numneuron;i++){
    double input = sum - neuron.getpotential[i];
    k1[i] = differentialEquation(input,neuron.getpotential[i]);
  }

  kneu0[0] = transinput(output(neuron.getpotential()))+damp(neuron0.getpotential);
  kneu1[0] = transinput(output(neuron.getpotential()))+damp(neuron1.getpotential);
  kneu0[1] = transinput(output(neuron.getpotential()+kneu0[0]*(dt/2)))+damp(neuron.getpotential()+kneu0[0]*(dt/2));
  kneu1[1] = transinput(output(neuron.getpotential()+kneu1[0]*(dt/2)))+damp(neuron.getpotential()+kneu1[0]*(dt/2));
  kneu0[2] = transinput(output(neuron.getpotential()+kneu0[1]*(dt/2)))+damp(neuron.getpotential()+kneu0[1]*(dt/2));
  kneu1[2] = transinput(output(neuron.getpotential()+kneu1[1]*(dt/2)))+damp(neuron.getpotential()+kneu1[1]*(dt/2));
  kneu0[3] = transinput(output(neuron.getpotential()+kneu0[2]*dt))+damp(neuron.getpotential()+kneu0[2]*dt);
  kneu1[3] = transinput(output(neuron.getpotential()+kneu1[2]*dt))+damp(neuron.getpotential()+kneu1[2]*dt);
  return 0;
}
