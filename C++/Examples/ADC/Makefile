CXX ?= g++
NAVIO = ../../Navio
INCLUDES = -I ../..

all:
	$(CXX) -std=gnu++11 $(INCLUDES) ADC_example.cpp $(NAVIO)/Util.cpp $(NAVIO)/ADC.cpp -o ADC_example

clean:
	rm ADC_example
