set(SRC_LIST ./test_vector.cpp ./plane_test.cpp)

add_executable(test_vector)

target_link_libraries(test_vector
                      PRIVATE ${GTEST_LIBRARIES}
                      PRIVATE vector)

target_include_directories(test_vector
                           PRIVATE ../include)                                      

gtest_discover_tests(test_vector)
