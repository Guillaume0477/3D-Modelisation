
#base directory of Qt files
QT_DIR_BASE=/usr/include/qt4

#specific include directories for Qt
QT_INCLUDE=-I${QT_DIR_BASE} -I${QT_DIR_BASE}/QtCore -I${QT_DIR_BASE}/QtGui

#specific lib dependecies for Qt
QT_DEPENDENCIES=-lQtCore -lQtGui -lQtOpenGL

#Qt MOC
MOC=moc-qt4

#QT UIC
UIC=uic-qt4

LINK_PC_CPE=-L/usr/lib/nvidia-331

#Compilation flags
CXXFLAGS= -g -Wall -Wextra -std=c++11 ${QT_INCLUDE}
#Linking flags
LDFLAGS=${LINK_PC_CPE} -lGLEW -lGL -lGLU -pthread ${QT_DEPENDENCIES}
#Compiler
CXX=g++


main: main.o glutils.o myWidgetGL.o myWindow.o moc_myWidgetGL.o moc_myWindow.o
	${CXX} $^ -o $@ ${LDFLAGS}

main.o: main.cpp myWindow.hpp
glutils.o: glutils.cpp glutils.hpp

myWidgetGL.o: myWidgetGL.cpp myWidgetGL.hpp  glutils.hpp
moc_myWidgetGL.o: moc_myWidgetGL.cpp myWidgetGL.hpp
moc_myWidgetGL.cpp: myWidgetGL.hpp
	${MOC} $< -o $@ ${QT_INCLUDE}

myWindow.o: myWindow.cpp myWindow.hpp myWidgetGL.hpp ui_mainwindow.h
moc_myWindow.o: moc_myWindow.cpp myWindow.hpp
moc_myWindow.cpp: myWindow.hpp
	${MOC} $< -o $@ ${QT_INCLUDE}

ui_mainwindow.h: mainwindow.ui
	${UIC} $< -o $@

clean:
	rm -f *~ *.o moc_* ui_* main
