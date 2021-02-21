.PHONY: build
CXXFLAGS=-Wall -Wextra -ggdb -pedantic -fno-exceptions 
INCLUDE=-I include/
LIBS=-L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

build:
	$(CXX) $(CXXFLAGS) -o monlo main.cpp $(INCLUDE) $(LIBS) 