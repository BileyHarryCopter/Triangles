#ifndef INCLUDE_DOUBLE_COMPARISON_HPP
#define INCLUDE_DOUBLE_COMPARISON_HPP

#include <algorithm>    // for std::max
#include <cmath>        // for std::abs

namespace Comparison
{

constexpr double epsilon = 1e-6;

bool are_equal (const double first, const double second,
                const double zero_diff = epsilon,
                const double rel_diff  = epsilon);

} // namespace Comparison

#endif // INCLUDE_DOUBLE_COMPARISON_HPP
