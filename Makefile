CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Wpedantic

all: main

main: main.o grid.o cell.o
	$(CXX) $(CXXFLAGS) -o main main.o grid.o cell.o

main.o: main.cpp grid.cpp cell.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp grid.cpp cell.cpp

format:
	clang-format -i -style=file *.cpp *.h

clean:
	rm -f *.o main
