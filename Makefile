CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = $(wildcard src/*.cpp)
TARGET = build/echoes_of_yggdrasil

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) -lraylib

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
