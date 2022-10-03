#pragma once

#include "double_comparison.hpp"
#include "line.hpp"
#include "point.hpp"
#include "vector.hpp"

namespace Geom_Objects
{

class Plane
{
    //  By an origin and normal vector of the plane
    Vector normal_;
    Point origin_;

public:

    Plane (Vector &normal, Point &origin)
    {
        if (normal.is_zero ())
            throw std::invalid_argument {"Zero vector was given to constructor of Plane\n"};
        normal_ = normal * (1 / normal.module ());
        origin_ = origin;
    }

    //  Bad idea to construct a plane by 4 doubles
    Plane (double A, double B, double C, double D)
    {
        //  Three comparisons to not create unnecessery evict as vector
        if (normal_.is_zero ())
            throw std::invalid_argument {"Zero vector was given to constructor of Plane\n"};
        if (cmp::are_equal (A, 0.0))
        {
            if (cmp::are_equal (B, 0.0))
                origin_ = {0, 0, -D / C};
            else
                origin_ = {0, -D / B, 0};
        }
        else
            origin_ = {-D / A, 0, 0};

        normal_ = {A, B, C};
        normal_ *= (1 / normal_.module ());
    }

    Point origin () const { return Point {origin_.x_, origin_.y_, origin_.z_}; };
    Vector norm_vec () const { return Vector {normal_.x_, normal_.y_, normal_.z_}; };
};

//  block with Plane and Point
double distance (const Point &p, const Plane &pl);
double distance (const Plane &pl, const Point &p);

bool is_belong (const Point &p, const Plane &pl);

//  block with Plane and Line
bool is_intersect (const Line &line, const Plane &pl);
bool are_parallel (const Plane &pl, const Line &line);
bool are_parallel (const Line &line, const Plane &pl);

bool is_contained (const Line &line, const Plane &pl);

double distance (const Plane &pl, const Line &line);
double distance (const Line &line, const Plane &pl);

//  block with Plane and Plane
bool are_parallel (const Plane &pl1, const Plane &pl2);

bool are_intersect (const Plane &pl1, const Plane &pl2);
bool are_equal (const Plane &pl1, const Plane &pl2);

double distance (const Plane &pl1, const Plane &pl2);

} //  namespace Geom_Objects
