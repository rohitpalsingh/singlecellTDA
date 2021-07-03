# CMakeList.txt : CMake project for LHF, include source and define
# project specific logic here.
#

cmake_minimum_required(VERSION 3.11)

add_library(pipePacket "pipePacket.cpp" "pipePacket.hpp")
add_library(basePipe "basePipe.cpp" "basePipe.hpp")
add_library(distMatrixPipe "distMatrixPipe.cpp" "distMatrixPipe.hpp")
add_library(neighGraphPipe "neighGraphPipe.cpp" "neighGraphPipe.hpp")
add_library(incrementalPersistence "incrementalPersistence.cpp" "incrementalPersistence.hpp")


include_directories(${PROJECT_SOURCE_DIR}/Complex)
link_directories(${PROJECT_SOURCE_DIR}/Complex)

include_directories(${PROJECT_SOURCE_DIR}/Pipes)
link_directories(${PROJECT_SOURCE_DIR}/Pipes)

include_directories(${PROJECT_SOURCE_DIR}/Preprocessing)
link_directories(${PROJECT_SOURCE_DIR}/Preprocessing)

include_directories(${PROJECT_SOURCE_DIR}/Utils)
link_directories(${PROJECT_SOURCE_DIR}/Utils)
  
target_link_libraries(basePipe utils simplexBase pipePacket distMatrixPipe neighGraphPipe incrementalPersistence)

INSTALL (TARGETS basePipe
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)

# TODO: Add tests and install targets if needed.

MESSAGE (STATUS "CMAKE_INCLUDE_PATH: " ${CMAKE_INCLUDE_PATH})
MESSAGE (STATUS "FLAGS: " ${CMAKE_CXX_FLAGS})
