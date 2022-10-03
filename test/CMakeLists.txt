<<<<<<< HEAD
set(SRC_LIST ./test_vector.cpp ./plane_test.cpp)

add_executable(test_vector)
=======
aux_source_directory(./basic_tests SRC_LIST)

add_executable(test_all ${SRC_LIST})
>>>>>>> master

target_link_libraries(test_all
                      PRIVATE ${GTEST_LIBRARIES}
                      PRIVATE basic_classes)

<<<<<<< HEAD
target_include_directories(test_vector
                           PRIVATE ../include)                                      
=======
target_include_directories(test_all
                           PRIVATE ../include)
>>>>>>> master

gtest_discover_tests(test_all)
