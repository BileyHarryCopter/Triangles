#include "<gtest/gtest.h>"
#include "line.hpp"

using namespace Geom_Objects;

TEST (are_parallel_for_lines, )
{
    EXPECT_EQ(are_parallel({Point p {23, 45, 67},       Vector v {1, -2, 4}, {Point p {1, 3, 45}, Vector v {2, -4, 8}}), true)
    EXPECT_EQ(are_parallel({Point p {12.3, 5.7, -6.34}, Vector v {1, -2, 4}, {Point p {1, 3, 45}, Vector v {-1, 2, -4}}), true)
    EXPECT_EQ(are_parallel({Point p {0, 0, 0},          Vector v {1, -2, 4}, {Point p {0, 0, 0},  Vector v {0, -4, 8}}), false)
    EXPECT_EQ(are_parallel({Point p {0, 0, 0},          Vector v {1, -2, 4}, {Point p {1, 3, 45}, Vector v {2, -4, 8}}), true)
    EXPECT_EQ(are_parallel({Point p {0, 0, 0},          Vector v {1, -2, 4}, {Point p {1, 3, 45}, Vector v {2, -4, 8}}), true)
}