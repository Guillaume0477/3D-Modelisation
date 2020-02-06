
#base directory of Qt files
QT_DIR_BASE=/usr/include/qt4

#specific include directories for Qt
QT_INCLUDE=-I${QT_DIR_BASE} -I${QT_DIR_BASE}/QtCore -I${QT_DIR_BASE}/QtGui

#specific lib dependecies for Qt
QT_DEPENDENCIES=-lQtCore -lQtGui

#Qt MOC
MOC=moc-qt4

#Compilation flags
CXXFLAGS= -g -Wall -Wextra -std=c++11 ${QT_INCLUDE}
#Linking flags
LDFLAGS=-pthread ${QT_DEPENDENCIES}
#Compiler
CXX=g++


main: main.o myWindow.o moc_myWindow.o
	${CXX} $^ -o main ${LDFLAGS}

main.o: main.cpp myWindow.hpp
myWindow.o: myWindow.cpp myWindow.hpp
moc_myWindow.o: moc_myWindow.cpp myWindow.hpp

moc_myWindow.cpp: myWindow.hpp
	${MOC} $< -o $@ ${QT_INCLUDE}

clean:
	rm -f *~ *.o moc_* main
