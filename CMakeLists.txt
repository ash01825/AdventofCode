# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.29)

# Define the project name and programming language
project(AdventofCode LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: Enable extra warnings for code quality
add_compile_options(-Wall -Wextra -pedantic)

# Define individual executables for each day's solution
add_executable(day1 day1/stars.cpp)
add_executable(day2 day2/stars.cpp)
add_executable(day3 day3/stars.cpp)
add_executable(day4 day4/stars.cpp)
add_executable(day5 day5/stars.cpp
        day5/stars.cpp)
add_executable(day6 day6/stars.cpp
        day6/stars.cpp)


# Optional: Add include directories (if needed)
# target_include_directories(day1 PUBLIC include)
# target_include_directories(day2 PUBLIC include)

# Optional: If you need to link libraries
# target_link_libraries(day1 PUBLIC some_library)