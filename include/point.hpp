#ifndef INCLUDE_POINT_HPP
#define INCLUDE_POINT_HPP

#include <cmath>    // for std::sqrt
#include <iostream>

#include "double_comparison.hpp"

namespace Geom_Objects
{

struct Point
{
    double x_;
    double y_;
    double z_;

    Point (double x, double y, double z) : x_{x}, y_{y}, z_{z} {}

    bool is_equal (const Point &other) const
    {
        return (Comparison::is_equal (x_, other.x_) &&
                Comparison::is_equal (y_, other.y_) &&
                Comparison::is_equal (z_, other.z_));
    }

    double distance (const Point &other) const
    {
        if (is_equal (other))
            return 0.0;
        else
        {
            auto x_diff = x_ - other.x_;
            auto y_diff = y_ - other.y_;
            auto z_diff = z_ - other.z_;

            return std::sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
        }
    }

    bool is_valid () const { return (x_ == x_ && y_ == y_ && z_ == z_); }

    void print () const { std::cout << "(" << x_ << ", " << y_ << ", " << z_ << ")" << std::endl; }
};

} // namespace Geom_Objects

#endif // INCLUDE_POINT_HPP
