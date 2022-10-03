#ifndef INCLUDE_POINT_HPP
#define INCLUDE_POINT_HPP

#include "double_comparison.hpp"

#include <iostream>

namespace Geom_Objects
{

struct Point
{
    double x_;
    double y_;
    double z_;

    Point (double x = 0.0, double y = 0.0, double z = 0.0) : x_ {x}, y_ {y}, z_ {z} {}

    bool is_valid () const { return (x_ == x_ && y_ == y_ && z_ == z_); }

    void print () const { std::cout << "(" << x_ << ", " << y_ << ", " << z_ << ")" << std::endl; }
};

bool are_equal (const Point &first, const Point &second);
double distance (const Point &first, const Point &second);

} // namespace Geom_Objects

#endif // INCLUDE_POINT_HPP
