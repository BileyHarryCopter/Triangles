#ifndef INCLUDE_VECTOR_HPP
#define INCLUDE_VECTOR_HPP

#include <cmath> // for std::sqrt

#include "point.hpp"

namespace Geom_Objects
{

struct Vector
{
    double x_, y_, z_;

    Vector (double x = 0.0, double y = 0.0, double z = 0.0) : x_{x}, y_{y}, z_{z} {}

    Vector (Point &pt) : x_{pt.x_}, y_{pt.y_}, z_{pt.z_} {}

    Vector (Point &first, Point &second)
           : x_{second.x_ - first.x_}, y_{second.y_ - first.y_}, z_{second.z_ - first.z_} {}

    bool operator== (const Vector &other) const
    {
        return (Comparison::are_equal (x_, other.x_) &&
                Comparison::are_equal (y_, other.y_) &&
                Comparison::are_equal (z_, other.z_));
    }

    bool operator!= (const Vector &other) const { return !(*this == other); }

    Vector &operator+= (const Vector &rhs)
    {
        x_ += rhs.x_;
        y_ += rhs.y_;
        z_ += rhs.z_;

        return *this;
    }

    Vector operator+ (const Vector &other) const
    {
        Vector sum = *this;
        return (sum += other);
    }

    Vector &operator-= (const Vector &rhs)
    {
        x_ -= rhs.x_;
        y_ -= rhs.y_;
        z_ -= rhs.z_;

        return *this;
    }

    Vector operator- (const Vector &other) const
    {
        Vector diff = *this;
        return (diff -= other);
    }

    Vector &operator*= (const double coeff)
    {
        x_ *= coeff;
        y_ *= coeff;
        z_ *= coeff;

        return *this;
    }

    Vector operator* (const double coeff) const
    {
        Vector product = *this;
        return (product *= coeff);
    }

    Vector operator- () const { return Vector{-x_, -y_, -z_}; }

    double module () const { return std::sqrt (x_ * x_ + y_ * y_ + z_ * z_); }

    bool is_zero () const
    {
        return (Comparison::are_equal (x_, 0.0) &&
                Comparison::are_equal (y_, 0.0) &&
                Comparison::are_equal (z_, 0.0));
    }
};

inline double scalar_product (const Vector &lhs, const Vector &rhs)
{
    return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_ + lhs.z_ * rhs.z_;
}

inline Vector vector_product (const Vector &lhs, const Vector &rhs)
{
    return Vector { lhs.y_ * rhs.z_ - lhs.z_ * rhs.y_,
                    lhs.x_ * rhs.z_ - lhs.z_ * rhs.x_,
                    lhs.x_ * rhs.y_ - lhs.y_ * rhs.x_ };
}

inline double triple_product (const Vector &first, const Vector &second, const Vector &third)
{
    return first.x_ * (second.y_ * third.z_ - second.z_ * third.y_) -
           first.y_ * (second.x_ * third.z_ - second.z_ * third.x_) +
           first.z_ * (second.x_ * third.y_ - second.y_ * third.x_);
}

inline bool are_collinear (const Vector &first, const Vector &second)
{
    return vector_product (first, second).is_zero ();
}

inline bool are_coplanar (const Vector &first, const Vector &second, const Vector &third)
{
    return Comparison::are_equal (triple_product (first, second, third), 0.0);
}

} // namespace Geom_Objects

#endif // INCLUDE_VECTOR_HPP
