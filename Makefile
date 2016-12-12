naural-system: main.o defineNeuralSystem.o
	g++ -std=c++11 -o neural-system main.o neuralNetwork.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
neuralNetwork.o: neuralNetwork.cpp
	g++ -std=c++11 -c neuralNetwork.cpp
clean:
	rm -f *.o neural-system \#* *~
