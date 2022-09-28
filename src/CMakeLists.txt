set(SRC_LIST vector.cpp
             double_comparison.cpp)

add_library(vector
            STATIC ${SRC_LIST})

target_include_directories(vector
                           PUBLIC ../include)
