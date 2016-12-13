//The soft for simulating neural system.
#include <fstream>
#include <iostream>
#include <cmath>
#include "declareNeuralNetwork.h"
#include "fourthOrderRungeKutta.h"

int main(){
  uint NumOfNeuronA = 1;//NeuronAの数
  uint NumOfNeuronB = 1;//NeuronBの数
  double dt = 0.0001;//タイムステップ
  double totaltime = 100.0;//総シミュレーション時間

  NeuralNetwork<double> Network(NumOfNeuronA,NumOfNeuronB);

  std::ofstream fout("test0.dat");
  double time;
  for(int i = 0;(time = i*dt) < totaltime;++i){
    if(i%100 == 0){//100ステップごとに出力
      fout << time << " ";
      for(auto itr = Network.getNeuronsp().begin(); itr != Network.getNeuronsp().end(); ++itr)
	fout << **itr;
      fout << std::endl;
    }
    fourthOrderRungeKutta(Network,dt);
  }
  fout << time << " ";
  for(auto itr = Network.getNeuronsp().begin(); itr != Network.getNeuronsp().end(); ++itr)
    fout << **itr;
  fout << std::endl;
  
  return 0;
}
