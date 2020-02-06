CXXFLAGS= -g -Wall -Wextra -O2
LDFLAGS = -L/usr/lib/nvidia-331 -lm -lglut -lGLEW -lGLU -lGL -pthread
#remarque: /usr/lib/nvidia-331 specifique pour les installations de CPE

all: executable

executable: main.o glutils.o mat4.o
	g++ $^ -o executable $(LDFLAGS)

main.o: main.cpp glutils.hpp mat4.hpp
glutils.o: glutils.cpp glutils.hpp
mat4.o: mat4.cpp mat4.hpp

.PHONY: clean
clean: 
	rm -f *.o executable *~ 
