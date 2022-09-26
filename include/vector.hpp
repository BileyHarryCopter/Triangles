#ifndef INCLUDE_VECTOR_HPP
#define INCLUDE_VECTOR_HPP

#include "point.hpp"

namespace Geom_Objects
{

struct Vector
{
    double x_;
    double y_;
    double z_;

    Vector (double x, double y, double z) : x_{x}, y_{y}, z_{z} {}

    Vector (Point &pt) : x_{pt.x_}, y_{pt.y_}, z_{pt.z_} {}

    Vector (Point &first, Point &second)
           : x_{second.x_ - first.x_}, y_{second.y_ - first.y_}, z_{second.z_ - first.z_} {}

    Vector &operator+= (const Vector &rhs)
    {
        x_ += rhs.x_;
        y_ += rhs.y_;
        z_ += rhs.z_;

        return *this;
    }

    Vector operator+ (const Vector &rhs) const
    {
        Vector sum = *this;
        return sum += rhs;
    }

    Vector operator- () const { return Vector{-x_, -y_, -z_}; }
};

} // namespace Geom_Objects

#endif // INCLUDE_VECTOR_HPP
