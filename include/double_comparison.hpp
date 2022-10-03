#ifndef INCLUDE_DOUBLE_COMPARISON_HPP
#define INCLUDE_DOUBLE_COMPARISON_HPP

namespace cmp
{

constexpr double epsilon = 1e-6;

bool are_equal (const double first, const double second, const double zero_diff = epsilon,
                const double rel_diff = epsilon);

} // namespace cmp

#endif // INCLUDE_DOUBLE_COMPARISON_HPP
