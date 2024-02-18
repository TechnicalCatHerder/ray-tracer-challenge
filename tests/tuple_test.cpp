#include "tuple.h"
#include <gtest/gtest.h>

TEST(TupleTest, ConstructorValues) {
    Tuple test_tuple(3.0f, 2.0f, 5.0f, 1.0f);

    // const auto test_tuple = new Tuple(4.3, -4.2, 3.1, 1.0);

    ASSERT_FLOAT_EQ(test_tuple.GetX(), 3.0f); // Check x value
    ASSERT_FLOAT_EQ(test_tuple.GetY(), 2.0f); // Check y value
    ASSERT_FLOAT_EQ(test_tuple.GetZ(), 5.0f); // Check z value
    ASSERT_FLOAT_EQ(test_tuple.GetW(), 1.0f); // Check w value

    ASSERT_TRUE(test_tuple.IsPoint());
    ASSERT_FALSE(test_tuple.IsVector());

    
}

