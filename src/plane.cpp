#include "plane.hpp"

namespace Geom_Objects
{

//  block with Plane and Point
double distance (const Point &p, const Plane &pl)
{
    Point origin = pl.origin ();
    Vector vec   = {p.x_ - origin.x_, p.y_ - origin.y_, p.z_ - origin.z_};
    double coef  = scalar_product (vec, pl.norm_vec ());
    vec *= coef;
    return vec.module ();
}

double distance (const Plane &pl, const Point &p) { return distance (p, pl); }

bool is_belong (const Point &p, const Plane &pl) { return cmp::are_equal (distance (p, pl), 0.0); }

//  block with Plane and Line
bool is_intersect (const Line &line, const Plane &pl)
{
    return cmp::are_equal (scalar_product (pl.norm_vec (), line.drc_vec ()), 0.0);
}

bool are_parallel (const Plane &pl, const Line &line)
{
    return are_collinear (pl.norm_vec (), line.drc_vec ());
}
bool are_parallel (const Line &line, const Plane &pl) { return are_parallel (pl, line); }

bool is_consisted (const Line &line, const Plane &pl)
{
    return is_belong (line.point_, pl) && are_parallel (line, pl);
}


double distance (const Plane &pl, const Line &line)
{
    if (is_consisted (line, pl))
        return 0.0;
    return vector_product (pl.norm_vec (), line.drc_vec ()).module ();
}
double distance (const Line &line, const Plane &pl) { return distance (pl, line); }

//  block with Plane and Plane
bool are_parallel (const Plane &pl1, const Plane &pl2)
{
    return are_collinear (pl1.norm_vec (), pl2.norm_vec ());
}
bool are_intersect (const Plane &pl1, const Plane &pl2) { return !are_parallel (pl1, pl2); }
bool are_equal (const Plane &pl1, const Plane &pl2)
{
    return are_parallel (pl1, pl2) && is_belong (pl1.origin (), pl2);
}

double distance (const Plane &pl1, const Plane &pl2)
{
    if (!are_parallel (pl1, pl2))
        throw std::invalid_argument {"Zero vector was given to constructor of Plane\n"};
    if (are_equal (pl1, pl2))
        return 0.0;
    Point p1 = pl1.origin ();
    Point p2 = pl2.origin ();
    Vector diff {p2, p1};
    return std::abs (scalar_product (pl1.norm_vec (), diff));
}

} // namespace Geom_Objects
