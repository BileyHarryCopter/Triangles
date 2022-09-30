#include <gtest/gtest.h>
#include "vector.hpp"

using namespace Geom_Objects;

TEST(Vector_Comparison, first)
{
    Vector vec_1 {1.0, 2.0, 3.0};
    Vector vec_2 {-1.0, 2.0, 3.0};
    
    EXPECT_TRUE (vec_1 != vec_2);
}
