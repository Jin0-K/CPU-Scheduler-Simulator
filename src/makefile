CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET := RR-scheduler

SRC := main.cpp \
       process/process.cpp \
       cpu/cpu.cpp \
       scheduler/scheduler.cpp

OBJ := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
