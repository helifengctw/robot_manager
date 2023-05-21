cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(untitled src/main.cpp src/RobotProcess.cpp src/Soldier.cpp src/Engineer.cpp src/Robot.cpp)
