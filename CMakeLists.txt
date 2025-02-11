cmake_minimum_required(VERSION 3.22.1)
project(data_and_algo)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
include_directories(include)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

#compile everything in src directory into a libray
file(GLOB SOURCES "src/*.cc")
add_library(algo SHARED ${SOURCES})

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS 1 CACHE INTERNAL "")
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
	main
	main.cc
)
target_link_libraries(
  main
  algo
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(main)

