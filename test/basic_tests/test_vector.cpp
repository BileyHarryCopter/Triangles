#include <gtest/gtest.h>
#include "vector.hpp"

using namespace Geom_Objects;

TEST(Vectors, Equality)
{    
    Vector vec_1 {1.0, 2.0, 3.0};
    Vector vec_2 {2.0, 3.0, 4.0};
    Vector vec_3 {1.000001, 2.000002, 3.000003};
    
    EXPECT_TRUE  (vec_1 == vec_1);

    EXPECT_FALSE (vec_1 == vec_2);
    EXPECT_FALSE (vec_2 == vec_1);

    EXPECT_TRUE  (vec_1 == vec_3);
    EXPECT_TRUE  (vec_3 == vec_1);
}

TEST(Vectors, Inequality)
{
    Vector vec_1 {1.0, 2.0, 3.0};
    Vector vec_2 {2.0, 3.0, 4.0};
    Vector vec_3 {1.000001, 2.000002, 3.000003};

    EXPECT_FALSE (vec_1 != vec_1);

    EXPECT_TRUE  (vec_1 != vec_2);
    EXPECT_TRUE  (vec_2 != vec_1);
    
    EXPECT_FALSE (vec_1 != vec_3);
    EXPECT_FALSE (vec_3 != vec_1);
}

TEST (Vectors, Addition)
{
    Vector vec_1  {1.0, 2.0, 3.0};
    Vector vec_2  {2.0, 3.0, 4.0};
    Vector vec_3  {3.0, 4.0, 5.0};
    Vector null   {0.0, 0.0, 0.0};
    Vector sum_12 {3.0, 5.0, 7.0};

    EXPECT_TRUE (vec_1 + vec_2 == vec_2 + vec_1);
    EXPECT_TRUE ((vec_1 + vec_2) + vec_3 == vec_1 + (vec_2 + vec_3));
    EXPECT_TRUE (vec_1 + (-vec_1) == null);
    EXPECT_TRUE (vec_1 + null == vec_1);

    EXPECT_TRUE (vec_1 + vec_2 == sum_12);
}

TEST (Vectors, Subtraction)
{
    Vector vec_1   {1.0, 2.0, 3.0};
    Vector vec_2   {2.0, 3.0, 4.0};
    Vector diff_21 {1.0, 1.0, 1.0};
    Vector diff_12 {-1.0, -1.0, -1.0};

    EXPECT_FALSE (vec_1 - vec_2 == vec_2 - vec_1);

    EXPECT_TRUE (vec_1 - vec_2 == diff_12);
    EXPECT_TRUE (vec_2 - vec_1 == diff_21);
}

TEST (Vectors, Multiplication)
{
    Vector vec_1 {1.0, 2.0, 3.0};
    Vector vec_2 {2.0, 3.0, 4.0};
    Vector null  {0.0, 0.0, 0.0};
    const double num_1 = 4.0;
    const double num_2 = 5.0;

    EXPECT_TRUE (vec_1 * num_1 == num_1 * vec_1);

    EXPECT_TRUE (num_1 * (num_2 * vec_1) == (num_1 * num_2) * vec_1);
    EXPECT_TRUE (1.0 * vec_1 == vec_1);
    EXPECT_TRUE ((num_1 + num_2) * vec_1 == num_1 * vec_1 + num_2 * vec_1);
    EXPECT_TRUE (num_1 * (vec_1 + vec_2) == num_1 * vec_1 + num_1* vec_2);

    EXPECT_TRUE (vec_1 * 0.0 == null);
    EXPECT_TRUE (num_1 * null == null);

    EXPECT_TRUE ((-num_1) * vec_1 == num_1 * (-vec_1));
}

TEST (Vectors, Inversion)
{
    Vector vec {1.0, 2.0, 3.0};
    Vector minus_vec {-1.0, -2.0, -3.0};

    EXPECT_TRUE (-vec == minus_vec);
    EXPECT_TRUE (-vec == -1.0 * vec);

    EXPECT_TRUE (-(-vec) == vec);
}
