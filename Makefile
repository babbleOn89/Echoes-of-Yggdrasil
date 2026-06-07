CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Isrc
LIBS = -lraylib

SRC = $(shell find src -name "*.cpp")
OUT = build/echoes

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LIBS)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
