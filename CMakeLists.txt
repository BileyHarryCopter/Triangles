cmake_minimum_required(VERSION 3.8)

project(HW3D
        LANGUAGES CXX)

if (${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    message(FATAL_ERROR "In-source build is forbidden")
endif()

find_package(GTest REQUIRED)
enable_testing()

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

<<<<<<< HEAD
aux_source_directory(./src BASIC_SRC)

add_library(basic_classes
            STATIC ${BASIC_SRC})

target_include_directories(basic_classes
                           PUBLIC ./include)


=======
>>>>>>> origin/ketchupp_point_and_vector
add_subdirectory(test)
