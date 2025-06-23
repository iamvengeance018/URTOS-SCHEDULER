CXX = g++
CXXFLAGS = -std=c++17 -pthread -Wall

SRC = src/main.cpp src/scheduler.cpp tasks/task1.cpp tasks/task2.cpp  # ← fixed here
INC = -Iinclude -Itasks
TARGET = urtos

all:
	$(CXX) $(CXXFLAGS) $(SRC) $(INC) -o $(TARGET)

clean:
	rm -f $(TARGET)

