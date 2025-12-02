CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

TARGET = lab13
SRC = Lab13.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
