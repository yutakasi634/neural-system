//The soft for simulating neural system.
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <array>
#include "declareNeuralSystem.h"

int main(){
  int NumOfNeuronA = 1;//NeuronAの数
  int NumOfNeuronB = 1;//NeuronBの数
  double dt = 0.0001;//タイムステップ
  double totaltime = 1000.0;//総シミュレーション時間

  NeuralNetwork Network(NumOfNeuronA,NumOfNeuronB);

  std::ofstream fout("test0.dat");
  fout << 0.0 << " ";
  for(uint i = 0; i < NumOfNeuronA + NumOfNeuronB; ++i)
    fout << (Network.getNeurons())[i];
  fout << std::endl;
  for(int i = 0;i*dt < totaltime;i++){
    fourthOrderRungeKutta(neuronA,dt);
    if(i%100 == 0){//100ステップごとに出力
      fout << dt*i << " ";
      for(uint j = 0; j < NumOfNeuronA + NumOfNeuronB; ++j)
	fout << (Network.getNeurons())[i];
      fout << std::endl;
    }
  }
  return 0;
}
