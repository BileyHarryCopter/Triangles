#ifndef INCLUDE_POINT_HPP
#define INCLUDE_POINT_HPP

#include <iostream>

#include "double_comparison.hpp"

namespace Geom_Objects
{

struct Point
{
    double x_, y_, z_;

    Point (double x = 0.0, double y = 0.0, double z = 0.0) : x_{x}, y_{y}, z_{z} {}

    bool operator== (const Point &other) const
    {
        return (Comparison::are_equal (x_, other.x_) &&
                Comparison::are_equal (y_, other.y_) &&
                Comparison::are_equal (z_, other.z_));
    }

    bool operator!= (const Point &other) const { return !(*this == other); }

    bool is_valid () const { return (x_ == x_ && y_ == y_ && z_ == z_); }

    void print () const { std::cout << "(" << x_ << ", " << y_ << ", " << z_ << ")" << std::endl; }
};

double distance  (const Point &first, const Point &second);

} // namespace Geom_Objects

#endif // INCLUDE_POINT_HPP
