#include <point.hpp>
#include <vector.hpp>

namespace Geom_Objects {

class Line {
    Point  point_;
    Vector drc_vec_;
    public:
        Line(const Point& p1, const Point& p2): point_{p1}, drc_vec_ {p1.x_ - p2.x_, p1.y_ - p2.y_, p1.z_ - p2.z_}
        {
            #ifndef RELEASE
            if (are_equal(p1, p2))
                throw std::invalid_argument{"In constructor of Line(Point, Point): two equal points"};
            #endif 
        }

        Line(const Point& p, const Vector& vec): point_ {p}, drc_vec_ {vec}
        {
            #ifndef RELEASE
            if (is_equal(vec.module(), 0))
                throw std::invalid_argument{"In constructor of Line(Point, Vector): null vector"};
            #endif
        }

        Vector drc_vec() const {return drc_vec_;}
        Point  point () const {return point_;}
};

bool are_paral(const Line& line1, const Line& line2) {return are_complinear(line1.drc_vec(), line2.drc_vec());}

bool are_complanar(const Line& line1, const Line& line2, const Line& line3)
{
    return are_complanar(line1.drc_vec(), line2.drc_vec(), line3.drc_vec());
}

double distance(const Line& line, const Point& pt)
{
    Vector dot_vec {pt, line.point()};
    double coef = scalar_product(dot_vec, line.drc_vec())/scalar_product(line.drc_vec(), line.drc_vec());
    return (dot_vec - coef * line.drc_vec()).module();
}

double distance(const Point& pt, const Line& line) {return distance(line, pt);}

double distance(const Line& line1, const Line& line2)
{
    
}

}