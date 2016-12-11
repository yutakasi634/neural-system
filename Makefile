naural-system: main.o defineNeuralSystem.o
	g++ -std=c++11 -Wall -O2 -o neural-system main.o defineNeuralSystem.o

main: main.cpp
	g++ -std=c++11 -c main.cpp

defineNeuralSystem: defineNeuralSystem.cpp
	g++ -std=c++11 -c defineNeuralSystem.cpp

clean:
	rm -f *.o neural-system \#* *~
