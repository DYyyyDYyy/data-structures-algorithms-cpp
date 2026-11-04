# Makefile для Lab_06_01 (Алгоритм Краскала)

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = kruskal
OBJS = main.o DSU.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp DSU.h
	$(CXX) $(CXXFLAGS) -c main.cpp

DSU.o: DSU.cpp DSU.h
	$(CXX) $(CXXFLAGS) -c DSU.cpp

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
