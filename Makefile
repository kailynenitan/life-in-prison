CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Wpedantic

all: main

main: main.o grid.o
	$(CXX) $(CXXFLAGS) -o main main.o grid.o

main.o: main.cpp grid.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp grid.cpp

format:
	clang-format -i -style=file *.cpp *.h

clean:
	rm -f *.o main
