#pragma once
#include "double_comparison.hpp"
#include "point.hpp"
#include "vector.hpp"

namespace Geom_Objects {

class Line {
    Vector drc_vec_;
    public:
        Point  point_;
        Line(const Point& p1, const Point& p2);
        Line(const Point& p, const Vector& vec);

        const Vector& drc_vec() const;
        const Vector& drc_vec(const Vector& new_vec);
};

bool are_parallel(const Line& line1, const Line& line2);

bool are_coplanar(const Line& line1, const Line& line2, const Line& line3);

double distance(const Line& line, const Point& pt);

double distance(const Point& pt, const Line& line);

double distance(const Line& line1, const Line& line2);

bool are_intersect(const Line& line1, const Line& line2);

bool is_belong(const Point& pt, const Line& line);
bool is_belong(const Line& line, const Point& pt);

bool are_equal(const Line& line1, const Line& line2);

}