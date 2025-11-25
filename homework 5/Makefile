CXX = g++
CXXFLAGS = -std=c++17

all: main

main: main.cpp DynArray.h ArrTxt.h ArrCSV.h
	$(CXX) $(CXXFLAGS) main.cpp -o main

clean:
	rm -f main *.o
