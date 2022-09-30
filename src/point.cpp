#include <cmath>    // for std::sqrt

#include "point.hpp"

namespace Geom_Objects
{

double distance (const Point &first, const Point &second)
{
    if (first == second)
        return 0.0;
    else
    {
        auto x_diff = first.x_ - second.x_;
        auto y_diff = first.y_ - second.y_;
        auto z_diff = first.z_ - second.z_;

        return std::sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
    }
}

}
