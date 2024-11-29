cmake_minimum_required(VERSION 3.30)

project(db-pages LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} src/main.cpp src/database.cpp)

target_compile_features(${PROJECT_NAME}  PRIVATE cxx_std_17)