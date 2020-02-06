cmake_minimum_required(VERSION 2.6)

project(main)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11")

FIND_PACKAGE(GLEW REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(Qt4 REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)


INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
LINK_DIRECTORIES(${GLEW_LIBRARY_DIRS})

INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})

INCLUDE(${QT_USE_FILE})

file(
	GLOB
	source_files
	src/*.[ch]pp
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(pgm_UI_H src/mainwindow.ui)
QT4_WRAP_CPP(source_files_moc src/myWindow.hpp src/myWidgetGL.hpp)

add_executable(
	pgm
	${source_files}
	${pgm_UI_H}
	${source_files_moc}
)

## Nvidia setting for CPE installs
LINK_DIRECTORIES("/usr/lib/nvidia-331")

TARGET_LINK_LIBRARIES(pgm ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${QT_LIBRARIES} ${QT_QTOPENGL_LIBRARY})


