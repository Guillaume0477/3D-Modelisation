
#base directory of Qt files
QT_DIR_BASE=/usr/include/qt4

#specific include directories for Qt
QT_INCLUDE=-I${QT_DIR_BASE} -I${QT_DIR_BASE}/QtCore -I${QT_DIR_BASE}/QtGui

#specific lib dependecies for Qt
QT_DEPENDENCIES=-lQtCore -lQtGui

#Compilation flags
CXXFLAGS= -g -Wall -Wextra -std=c++11 ${QT_INCLUDE}
#Linking flags
LDFLAGS=-pthread ${QT_DEPENDENCIES}
#Compiler
CXX=g++


hello_world: hello_world.o
	${CXX} $^ -o hello_world ${LDFLAGS}

hello_world.o: hello_world.cpp

clean:
	rm -f *~ *.o hello_world
