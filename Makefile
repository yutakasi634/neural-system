naural-system: main.cpp
	g++ -std=c++11 -Wall -o neural-system main.cpp
clean:
	rm -f *.o neural-system \#* *~
