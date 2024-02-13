#include "tuple.h"
#include <gtest/gtest.h>


TEST(TupleTest, ConstructorValues) {
    tuple myTuple(3.0f, 2.0f, 5.0f, 1.0f);

    ASSERT_FLOAT_EQ(myTuple.getX(), 3.0f); // Check x value
    ASSERT_FLOAT_EQ(myTuple.getY(), 2.0f); // Check y value
    ASSERT_FLOAT_EQ(myTuple.getZ(), 5.0f); // Check z value
    ASSERT_FLOAT_EQ(myTuple.getW(), 1.0f); // Check w value
}

