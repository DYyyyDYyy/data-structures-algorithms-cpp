CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = lab_06_02

SRCS = main.cpp Prim.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Prim.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Prim.o: Prim.cpp Prim.h
	$(CXX) $(CXXFLAGS) -c Prim.cpp

clean:
	rm -f $(OBJS) $(TARGET)