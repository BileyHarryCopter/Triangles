#include "vector.hpp"

#include <gtest/gtest.h>

using namespace Geom_Objects;

TEST (Vector_Comparison, first)
{
    Vector vec_1 {1.0, 2.0, 3.0};
    Vector vec_2 {-1.0, 2.0, 3.0};

    EXPECT_EQ (are_equal (vec_1, vec_2), false);
}

int main (int argc, char **argv)
{
    testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}
