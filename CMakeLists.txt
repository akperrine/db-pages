cmake_minimum_required(VERSION 3.30)

project(db-pages LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cpp src/database.cpp src/btree.cpp)
target_compile_features(${PROJECT_NAME}  PRIVATE cxx_std_17)


if(BUILD_TESTING)
  add_library(DatabaseLibrary src/database.cpp src/btree.cpp)

  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  enable_testing()

  add_executable(Tests test/database_test.cpp test/btree_test.cpp)

  target_link_libraries(
    Tests
    DatabaseLibrary
    GTest::gtest_main
  )

  include(GoogleTest)
  gtest_add_tests(TARGET Tests)
endif()