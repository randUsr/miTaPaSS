cmake_minimum_required(VERSION 2.8)

PROJECT(miTaPaSS)

set (MITAPASS_VERSION_MAJOR 0)
set (MITAPASS_VERSION_MINOR 2)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/ )

SET(LIBRARY_OUTPUT_PATH ../lib
CACHE PATH "CMakeLists.txt files optimized for this directory! Please do not change.")

SET(EXECUTABLE_OUTPUT_PATH ../bin
CACHE PATH "CMakeLists.txt files optimized for this directory! Please do not change.")

set(CMAKE_CXX_STANDARD 17)

configure_file (
	"${PROJECT_SOURCE_DIR}/src/Config.h.in"
	"${PROJECT_SOURCE_DIR}/bin/Config.h"
	)

find_package(Threads)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(.)
include_directories(${GTKMM_INCLUDE_DIRS})

SET(MITAPASS_SRC
	${PROJECT_SOURCE_DIR}/src/main.cpp
	${PROJECT_SOURCE_DIR}/src/Config.cpp
	${PROJECT_SOURCE_DIR}/src/Simulator.cpp
	${PROJECT_SOURCE_DIR}/src/FerranteFake.cpp
	${PROJECT_SOURCE_DIR}/src/ManualEngine.cpp
	${PROJECT_SOURCE_DIR}/src/NeuralEngine.cpp
	${PROJECT_SOURCE_DIR}/src/Resultor.cpp
	${RESOURCE_FILE}
)

ADD_EXECUTABLE(miTaPaSS ${MITAPASS_SRC})

target_link_libraries(miTaPaSS ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(miTaPaSS ${GTKMM_LIBRARIES})
