CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -O2

VHDRS := Vector.h Vector.hpp
MHDRS := matrix.h matrix.hpp

all: test_vector.x matrix_driver.x

test_vector.x: test_vector.cpp $(VHDRS)
	$(CXX) $(CXXFLAGS) test_vector.cpp -o $@

matrix_driver.x: matrix_driver.cpp $(VHDRS) $(MHDRS)
	$(CXX) $(CXXFLAGS) matrix_driver.cpp -o $@

clean:
	rm -f *.o *.x

.PHONY: all clean

