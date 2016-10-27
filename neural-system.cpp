//The soft for simulating neural system.
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "declareNeuralSystem.h"

int main(int argc, char **argv){
  Neurons neuron(50);
  std::ofstream fout("test0.dat");
  fout << 0.0 << " ";
  fout << neuron << std::endl;
  for(int i = 0;i*dt < 10;i++){
    timeevolution(neuron);
    if(i%100 == 0){
      fout << dt*i << " ";
      for(int j = 0;j < neuron.getneuronnum();j++)
	fout << (neuron.getpotential())[j] << " ";
      fout << "\n";
    }
  }
  return 0;
}
