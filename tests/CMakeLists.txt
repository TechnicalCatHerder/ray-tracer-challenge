enable_testing()

add_executable(
  tuple_test
  tuple_test.cpp
)

target_link_libraries(
  tuple_test
  ray_tracer_lib
  GTest::gtest_main
)

# Include directories
target_include_directories(tuple_test PUBLIC ../include)

include(GoogleTest)
gtest_discover_tests(tuple_test)