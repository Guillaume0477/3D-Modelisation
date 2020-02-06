cmake_minimum_required(VERSION 2.6)

project(main)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11")


FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

file(
	GLOB
	source_files
	src/*.[ch]pp
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_CPP(source_files_moc src/myWindow.hpp)

add_executable(
	pgm
	${source_files}
	${source_files_moc}
)


TARGET_LINK_LIBRARIES(pgm -lm ${QT_LIBRARIES})


