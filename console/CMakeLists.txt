cmake_minimum_required(VERSION 3.16)
project(assignment-4-console)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    main.cpp
    Game.cpp
    GameStates.cpp
)

# Create the executable
add_executable(assignment-4-console ${SOURCES})
