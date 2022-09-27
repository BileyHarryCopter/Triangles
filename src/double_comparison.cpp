#include "double_comparison.hpp"

namespace Comparison
{

bool are_equal (const double first, const double second,
                const double zero_diff,
                const double rel_diff)
{
    auto diff = std::abs (first - second);

    if (diff < zero_diff)
        return true;
    else
        return (diff < std::max (std::abs (first), std::abs (second)) * rel_diff);
}

} // namespace Comparison
