#pragma once

#include "point.hpp"
#include "vector.hpp"
#include "line.hpp"
#include "double_comparison.hpp"

namespace Geom_Objects
{

class Plane
{
    //  from general form of plane: Ax + By + Cz + D = 0
    double A_, B_, C_, D_;

public:
    Plane (double A, double B, double C, double D) : A_{A}, B_{B}, C_{C}, D_{D} 
    {
        //  three comparisons to not create unnecessery evict as vector
        if (Comparison::are_equal (A, 0.0)
        &&  Comparison::are_equal (B, 0.0)
        &&  Comparison::are_equal (C, 0.0))
            throw std::invalid_argument {"In constructor of Plane(A, B, C, D): zero normal vector\n"};
    }

    Plane (const Point& p, const Vector& rhs) : A_{rhs.x_}, B_{rhs.y_}, C_{rhs.z_}, 
                                                D_{p.x_*rhs.x_ + p.y_*rhs.y_ + p.z_*rhs.z_}
    {
        if (rhs.is_zero())
            throw std::invalid_argument {"In constuctor of Plane(Vector normal, Point origin): zero normal\n"};
    }

    Vector norm_vec () const { return Vector norm = {A_, B_, C_}; };
    Point  origin () const {return Point or = {p.x_*rhs.x_, p.y_*rhs.y_, p.z_*rhs.z_};}

};

//  block with Plane and Point
double distance (const Point& p, const Plane& pl);
double distance (const Plane& pl, const Point& p);

bool is_belong (const Point& p, const Plane& pl);

//  block with Plane and Line
bool is_intersect (const Line& line, const Plane& pl);
bool are_paral (const Plane& pl, const Line& line);
bool are_paral (const Line& line, const Plane& pl);

bool is_consisted (const Line& line, const Plane& pl);

Point p_intersect (const Line& line, const Plane& pl);

double distance (const Plane& pl, const Line& line);
double distance (const Line& line, const Plane& pl);

//  block with Plane and Plane
bool are_paral (const Plane& pl1, const Plane& pl2);

bool are_intersect (const Plane& pl1, const Plane& pl2);
bool are_equal (const Plane& pl1, const Plane& pl2);

double distance (const Plane& pl1, const Plane& pl2);

}   //  namespace Geom_Objects
