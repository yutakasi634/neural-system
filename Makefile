naural-system: main.o defineNeuralSystem.o
	g++ -std=c++11 -Wall -o neural-system defineNeuralSystem.o main.o
main.o: defineNeuralSystem.cpp main.cpp
	g++ -std=c++11 -Wall -c main.cpp
defineNeuralSystem.o: defineNeuralSystem.cpp
	g++ -std=c++11 -Wall -c defineNeuralSystem.cpp
clean:
	rm -f *.o neural-system
