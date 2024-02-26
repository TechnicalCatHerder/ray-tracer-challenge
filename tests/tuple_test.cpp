#include "tuple.h"
#include <gtest/gtest.h>

TEST(TupleTest, PointTest) {
    Tuple test_point(3.0f, 2.0f, 5.0f, 1.0f);

    ASSERT_FLOAT_EQ(test_point.GetX(), 3.0f); // Check x value
    ASSERT_FLOAT_EQ(test_point.GetY(), 2.0f); // Check y value
    ASSERT_FLOAT_EQ(test_point.GetZ(), 5.0f); // Check z value
    ASSERT_FLOAT_EQ(test_point.GetW(), 1.0f); // Check w value

    ASSERT_TRUE(test_point.IsPoint());
    ASSERT_FALSE(test_point.IsVector());
}

TEST(TupleTest, VectorTest) {
    Tuple test_vector(3.0f, 2.0f, 5.0f, 0.0f);

    ASSERT_FLOAT_EQ(test_vector.GetX(), 3.0f); // Check x value
    ASSERT_FLOAT_EQ(test_vector.GetY(), 2.0f); // Check y value
    ASSERT_FLOAT_EQ(test_vector.GetZ(), 5.0f); // Check z value
    ASSERT_FLOAT_EQ(test_vector.GetW(), 0.0f); // Check w value

    ASSERT_FALSE(test_vector.IsPoint());
    ASSERT_TRUE(test_vector.IsVector());
}

TEST(TupleTest, CreatePointTest) {
    Tuple create_point = Point(3.0f, 12.0f, 1.0f);

    ASSERT_FLOAT_EQ(create_point.GetX(), 3.0f); // Check x value
    ASSERT_FLOAT_EQ(create_point.GetY(), 12.0f); // Check y value
    ASSERT_FLOAT_EQ(create_point.GetZ(), 1.0f); // Check z value
    ASSERT_FLOAT_EQ(create_point.GetW(), 1.0f); // Check w value

    ASSERT_TRUE(create_point.IsPoint());
    ASSERT_FALSE(create_point.IsVector());
}

TEST(TupleTest, CreateVectorTest) {
    Tuple create_vector = Vector(3.0f, 12.0f, 1.0f);

    ASSERT_FLOAT_EQ(create_vector.GetX(), 3.0f); // Check x value
    ASSERT_FLOAT_EQ(create_vector.GetY(), 12.0f); // Check y value
    ASSERT_FLOAT_EQ(create_vector.GetZ(), 1.0f); // Check z value
    ASSERT_FLOAT_EQ(create_vector.GetW(), 0.0f); // Check w value

    ASSERT_TRUE(create_vector.IsVector());
    ASSERT_FALSE(create_vector.IsPoint());
}

TEST(TupleTest, TupleAdditionTest) {
    Tuple test_point = Point(3.0f, 2.0f, 5.0f);
    Tuple test_vector = Vector(3.0f, 2.0f, 5.0f);
    Tuple my_tuple = test_point + test_vector;


    ASSERT_FLOAT_EQ(my_tuple.GetX(), 6.0f); // Check x value
    ASSERT_FLOAT_EQ(my_tuple.GetY(), 4.0f); // Check y value
    ASSERT_FLOAT_EQ(my_tuple.GetZ(), 10.0f); // Check z value
    ASSERT_FLOAT_EQ(my_tuple.GetW(), 1.0f); // Check w value

    ASSERT_TRUE(my_tuple.IsPoint());
    ASSERT_FALSE(my_tuple.IsVector());
}

TEST(TupleTest, PointSubtractionTest) {
    Tuple test_point = Point(3.0f, 2.0f, 5.0f);
    Tuple test_point2 = Point(2.0f, 1.0f, 7.0f);
    Tuple my_tuple = test_point - test_point2;


    ASSERT_FLOAT_EQ(my_tuple.GetX(), 1.0f); // Check x value
    ASSERT_FLOAT_EQ(my_tuple.GetY(), 1.0f); // Check y value
    ASSERT_FLOAT_EQ(my_tuple.GetZ(), -2.0f); // Check z value
    ASSERT_FLOAT_EQ(my_tuple.GetW(), 0.0f); // Check w value

    ASSERT_FALSE(my_tuple.IsPoint());
    ASSERT_TRUE(my_tuple.IsVector());
}

TEST(TupleTest, PointSubtractVectorTest) {
    Tuple test_point = Point(3.0f, 2.0f, 5.0f);
    Tuple test_vector = Vector(2.0f, 1.0f, 7.0f);
    Tuple my_tuple = test_point - test_vector;


    ASSERT_FLOAT_EQ(my_tuple.GetX(), 1.0f); // Check x value
    ASSERT_FLOAT_EQ(my_tuple.GetY(), 1.0f); // Check y value
    ASSERT_FLOAT_EQ(my_tuple.GetZ(), -2.0f); // Check z value
    ASSERT_FLOAT_EQ(my_tuple.GetW(), 1.0f); // Check w value

    ASSERT_TRUE(my_tuple.IsPoint());
    ASSERT_FALSE(my_tuple.IsVector());
}

TEST(TupleTest, VectorSubtractionTest) {
    Tuple test_vector = Vector(3.0f, 2.0f, 5.0f);
    Tuple test_vector2 = Vector(2.0f, 1.0f, 7.0f);
    Tuple my_tuple = test_vector - test_vector2;


    ASSERT_FLOAT_EQ(my_tuple.GetX(), 1.0f); // Check x value
    ASSERT_FLOAT_EQ(my_tuple.GetY(), 1.0f); // Check y value
    ASSERT_FLOAT_EQ(my_tuple.GetZ(), -2.0f); // Check z value
    ASSERT_FLOAT_EQ(my_tuple.GetW(), 0.0f); // Check w value

    ASSERT_FALSE(my_tuple.IsPoint());
    ASSERT_TRUE(my_tuple.IsVector());
}

TEST(TupleTest, ZeroVectorSubtractionTest) {
    Tuple zero_vector = Vector(0.0f, 0.0f, 0.0f);
    Tuple test_vector2 = Vector(2.0f, 1.0f, 7.0f);
    Tuple my_tuple = zero_vector - test_vector2;


    ASSERT_FLOAT_EQ(my_tuple.GetX(), -2.0f); // Check x value
    ASSERT_FLOAT_EQ(my_tuple.GetY(), -1.0f); // Check y value
    ASSERT_FLOAT_EQ(my_tuple.GetZ(), -7.0f); // Check z value
    ASSERT_FLOAT_EQ(my_tuple.GetW(), 0.0f); // Check w value

    ASSERT_FALSE(my_tuple.IsPoint());
    ASSERT_TRUE(my_tuple.IsVector());
}



TEST(TupleTest, TupleNegationTest) {
    Tuple test_tuple = Vector(3.0f, 2.0f, -5.0f);
    test_tuple = -test_tuple;

    ASSERT_FLOAT_EQ(test_tuple.GetX(), -3.0f); // Check x value
    ASSERT_FLOAT_EQ(test_tuple.GetY(), -2.0f); // Check y value
    ASSERT_FLOAT_EQ(test_tuple.GetZ(), 5.0f); // Check z value
    ASSERT_FLOAT_EQ(test_tuple.GetW(), 0.0f); // Check w value

    ASSERT_FALSE(test_tuple.IsPoint());
    ASSERT_TRUE(test_tuple.IsVector());
}

TEST(TupleTest, TupleMultiplationTest) {
    Tuple test_tuple = Tuple(3.0f, 2.0f, -5.0f, 2.0);
    test_tuple = 2.0f * test_tuple;

    ASSERT_FLOAT_EQ(test_tuple.GetX(), 6.0f); // Check x value
    ASSERT_FLOAT_EQ(test_tuple.GetY(), 4.0f); // Check y value
    ASSERT_FLOAT_EQ(test_tuple.GetZ(), -10.0f); // Check z value
    ASSERT_FLOAT_EQ(test_tuple.GetW(), 4.0f); // Check w value

    test_tuple = 0.5f * test_tuple;

    ASSERT_FLOAT_EQ(test_tuple.GetX(), 3.0f); // Check x value
    ASSERT_FLOAT_EQ(test_tuple.GetY(), 2.0f); // Check y value
    ASSERT_FLOAT_EQ(test_tuple.GetZ(), -5.0f); // Check z value
    ASSERT_FLOAT_EQ(test_tuple.GetW(), 2.0f); // Check w value
}

TEST(TupleTest, TupleDivisonTest) {
    Tuple test_tuple = Tuple(3.0f, 2.0f, -5.0f, 2.0);
    test_tuple = 2.0f / test_tuple;

    ASSERT_FLOAT_EQ(test_tuple.GetX(), 1.5f); // Check x value
    ASSERT_FLOAT_EQ(test_tuple.GetY(), 1.0f); // Check y value
    ASSERT_FLOAT_EQ(test_tuple.GetZ(), -2.5f); // Check z value
    ASSERT_FLOAT_EQ(test_tuple.GetW(), 1.0f); // Check w value

}