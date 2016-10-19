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

class Neuron{
private:
  double potential[numneuron];
public:
  Neuron(){
    for(int i = 0; i < numneuron; i++)
      potential[i] = 2.0*(rand() % 1000);
  }
  double getpotential() const{return potential[]};
  double setpotential(int i,double x) {potential[i] = x};
};

double transinput(double input){
  double result;
  result = 1/(1+exp(input));
  return result;
}

double damp(double potential){
  double result;
  result = -1*(potential);
  return result;
}

double output(double potential){
  double result;
  result = 1/(1+exp(potential));
  return result;
}

int theta(double x){
  int result;
  if(x >= 0)
    result = 1;
  else
    result = 0;
  return result;
}

int timeevolution(double potential[]){/*class is avalable for argument.*/
  double newpotential0,newpotential1,kneu0[4],kneu1[4];
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
