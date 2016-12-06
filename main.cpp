//The soft for simulating neural system.
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <array>
#include "declareNeuralSystem.h"

int main(){
  int NumOfNeuron = 2;
  NeuronTypeA<double> neuronA;
  NeuronTypeB<double> neuronB;
  std::array<std::array<double, NumOfNeuron>, NumOfNeuron> ConnectionMatrix;
  NeuralNetwork = {neuronA,neuronB};
  double dt = 0.0001;//タイムステップ
  double totaltime = 1000.0;//総シミュレーション時間
  std::ofstream fout("test0.dat");
  fout << 0.0 << " ";
  fout << neuronA << std::endl;
  for(int i = 0;i*dt < totaltime;i++){
    fourthOrderRungeKutta(neuronA,dt);
    if(i%100 == 0){
      fout << dt*i << " ";
      fout << neuronA;
      fout << "\n";
    }
  }
  return 0;
}
