cmake_minimum_required(VERSION 3.10)

# Set the project name
project(sshtool)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)

# Find the json-c library
find_package(json-c REQUIRED)

# Add the executable
add_executable(sshtool main.c actions.c database.c)

# Link the json-c library
target_link_libraries(sshtool json-c::json-c)
