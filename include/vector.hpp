#ifndef INCLUDE_VECTOR_HPP
#define INCLUDE_VECTOR_HPP

#include "point.hpp"

#include <cmath> // for std::sqrt

namespace Geom_Objects
{

struct Vector
{
    double x_, y_, z_;

    Vector (double x = 0.0, double y = 0.0, double z = 0.0) : x_ {x}, y_ {y}, z_ {z} {}

    Vector (Point &pt) : x_ {pt.x_}, y_ {pt.y_}, z_ {pt.z_} {}

    Vector (Point &first, Point &second)
        : x_ {second.x_ - first.x_}, y_ {second.y_ - first.y_}, z_ {second.z_ - first.z_}
    {}

    Vector &operator+= (const Vector &rhs)
    {
        x_ += rhs.x_;
        y_ += rhs.y_;
        z_ += rhs.z_;

        return *this;
    }

    Vector &operator-= (const Vector &rhs)
    {
        x_ -= rhs.x_;
        y_ -= rhs.y_;
        z_ -= rhs.z_;

        return *this;
    }

    Vector &operator*= (const double coeff)
    {
        x_ *= coeff;
        y_ *= coeff;
        z_ *= coeff;

        return *this;
    }

    Vector operator- () const { return Vector {-x_, -y_, -z_}; }

    double module () const { return std::sqrt (x_ * x_ + y_ * y_ + z_ * z_); }

    bool is_zero () const
    {
        return (Comparison::are_equal (x_, 0.0) && Comparison::are_equal (y_, 0.0) &&
                Comparison::are_equal (z_, 0.0));
    }
};

Vector operator+ (const Vector &lhs, const Vector &rhs);
Vector operator- (const Vector &lhs, const Vector &rhs);
Vector operator* (const Vector &lhs, const double coeff);

double scalar_product (const Vector &lhs, const Vector &rhs);
Vector vector_product (const Vector &lhs, const Vector &rhs);
double triple_product (const Vector &first, const Vector &second, const Vector &third);

bool are_equal (const Vector &lhs, const Vector &rhs);
bool are_collinear (const Vector &first, const Vector &second);
bool are_coplanar (const Vector &first, const Vector &second, const Vector &third);

} // namespace Geom_Objects

#endif // INCLUDE_VECTOR_HPP
