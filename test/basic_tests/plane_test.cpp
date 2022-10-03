#include "double_comparison.hpp"
#include "plane.hpp"

#include <gtest/gtest.h>
#include <iostream>

using namespace Geom_Objects;

TEST (PlaneTest, Constructors)
{
    Vector norm_bad {0.0, 0.0, 0.0};
    Point orig {0.0, 0.0, 0.0};

    Vector norm_1 {1.0, 0.0, 0.0};
    Vector norm_2 {0.0, 1.0, 0.0};
    Vector norm_3 {0.0, 0.0, 1.0};

    //  Test for bad constructors
    EXPECT_THROW ({ Plane {}; }, std::invalid_argument);
    EXPECT_THROW ({ Plane (orig, norm_bad); }, std::invalid_argument);
    EXPECT_THROW ({ Plane (0.0, 0.0, 0.0, 42.0); }, std::invalid_argument);

    //  Test for good constructor
    EXPECT_NO_THROW ({ Plane (orig, norm_1); });
    EXPECT_NO_THROW ({ Plane (orig, norm_2); });
    EXPECT_NO_THROW ({ Plane (orig, norm_3); });

    //  Test normal creation of a plane
    Point check_point {-42.0, 0.0, 0.0};
    Plane pl {1.0, 0.0, 0.0, 42};
    EXPECT_TRUE (check_point == pl.origin ());                    //  check origin
    EXPECT_TRUE (cmp::are_equal (pl.norm_vec ().module (), 1.0)); //  check module of unit vector
}

TEST (PlaneTest, PlanePoint)
{
    Plane pl {0.0, 0.0, 1.0, 5.0};
    Point p {0.0, 0.0, 0.0};
    Point p_in {-1.0, -2.0, -5.0};
    Point p_out {-1.0, -2.0, 0.0};

    EXPECT_TRUE (cmp::are_equal (distance (p, pl), 5.0));
    EXPECT_TRUE (is_belong (p_in, pl));
    EXPECT_FALSE (is_belong (p_out, pl));
}
