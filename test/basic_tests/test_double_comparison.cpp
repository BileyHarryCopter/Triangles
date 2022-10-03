#include "double_comparison.hpp"

#include <cmath> // for NAN and INFINITY
#include <gtest/gtest.h>

using namespace Comparison;

TEST (Comp_With_Zero, Normalized)
{
    EXPECT_EQ (are_equal (0.0, 0.0), true);
    EXPECT_EQ (are_equal (0.0, -0.0), true);

    EXPECT_EQ (are_equal (1.0, 0.0), false);
    EXPECT_EQ (are_equal (1.0, -0.0), false);
    EXPECT_EQ (are_equal (-1.0, 0.0), false);
    EXPECT_EQ (are_equal (-1.0, -0.0), false);

    EXPECT_EQ (are_equal (83745.2, 0.0), false);
    EXPECT_EQ (are_equal (83745.2, -0.0), false);
    EXPECT_EQ (are_equal (-83745.2, 0.0), false);
    EXPECT_EQ (are_equal (-83745.2, -0.0), false);
}

TEST (Comp_With_Zero, Subnormal)
{
    EXPECT_EQ (are_equal (epsilon / 2.0, 0.0), true);
    EXPECT_EQ (are_equal (epsilon / 2.0, -0.0), true);
    EXPECT_EQ (are_equal (-epsilon / 2.0, 0.0), true);
    EXPECT_EQ (are_equal (-epsilon / 2.0, -0.0), true);

    EXPECT_EQ (are_equal (1e-10, 0.0), true);
    EXPECT_EQ (are_equal (1e-10, -0.0), true);
    EXPECT_EQ (are_equal (-1e-10, 0.0), true);
    EXPECT_EQ (are_equal (-1e-10, -0.0), true);

    EXPECT_EQ (are_equal (0.00005, 0.0), false);
    EXPECT_EQ (are_equal (0.00005, -0.0), false);
    EXPECT_EQ (are_equal (-0.00005, 0.0), false);
    EXPECT_EQ (are_equal (-0.00005, -0.0), false);
}

TEST (Comp_With_Zero, INF_NAN)
{
    EXPECT_EQ (are_equal (0.0, NAN), false);
    EXPECT_EQ (are_equal (0.0, -NAN), false);
    EXPECT_EQ (are_equal (-0.0, NAN), false);
    EXPECT_EQ (are_equal (-0.0, -NAN), false);

    EXPECT_EQ (are_equal (0.0, INFINITY), false);
    EXPECT_EQ (are_equal (0.0, -INFINITY), false);
    EXPECT_EQ (are_equal (-0.0, INFINITY), false);
    EXPECT_EQ (are_equal (-0.0, -INFINITY), false);
}

TEST (Exotic, INF_NAN)
{
    EXPECT_EQ (are_equal (NAN, NAN), false);
    EXPECT_EQ (are_equal (NAN, -NAN), false);

    EXPECT_EQ (are_equal (INFINITY, INFINITY), true);
    EXPECT_EQ (are_equal (INFINITY, -INFINITY), false);
}
