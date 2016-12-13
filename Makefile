naural-system: main.o
	g++ -std=c++11 -o neural-system main.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
clean:
	rm -f *.o neural-system \#* *~
