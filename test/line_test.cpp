#include "../include/line.hpp"
#include <gtest/gtest.h>

using namespace Geom_Objects;

TEST(Line_are_equal, test1)
{
    Line line1 {Point p {0, 0, 0}, Vector v {1, 3, -2}};
    Line line2 {Point p {0, 0, 0}, Vector v {2, 6, -4}};

    EXPECT
}

int main(int argc, char* argv[])
{
    return 0;
}