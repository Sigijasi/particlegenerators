cmake_minimum_required(VERSION 2.8)


project(particlegenerators)
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS log)
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK=1)

include_directories(${Boost_INCLUDE_DIRS})



add_executable(${PROJECT_NAME} "main.cpp" "R_Cube.h" "R_Cube.cpp" "S_Cube.h" "S_Cube.cpp" "Generator1.h" "Generator1.cpp" "M_Cube.h" "M_Cube.cpp")
target_link_libraries( ${PROJECT_NAME} ${VTK_LIBRARIES} )
