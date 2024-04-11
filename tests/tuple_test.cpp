#include "tuple.h"
#include "environment.h"
#include "projectile.h"
#include "cannon.h"
#include <gtest/gtest.h>
#include <iostream>

#include "../../../../AppData/Local/Programs/CLion/bin/mingw/x86_64-w64-mingw32/include/math.h"

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
    Tuple point_add = Point(3.0f, 2.0f, 5.0f);
    Tuple vector_add = Vector(3.0f, 2.0f, 5.0f);
    Tuple point_vector_sum = point_add + vector_add;


    ASSERT_FLOAT_EQ(point_vector_sum.GetX(), 6.0f); // Check x value
    ASSERT_FLOAT_EQ(point_vector_sum.GetY(), 4.0f); // Check y value
    ASSERT_FLOAT_EQ(point_vector_sum.GetZ(), 10.0f); // Check z value
    ASSERT_FLOAT_EQ(point_vector_sum.GetW(), 1.0f); // Check w value

    ASSERT_TRUE(point_vector_sum.IsPoint());
    ASSERT_FALSE(point_vector_sum.IsVector());
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
    Tuple vector_multiplacation1 = Vector(3.0f, 2.0f, -5.0f);
    vector_multiplacation1 = vector_multiplacation1 * 2.0f;

    ASSERT_FLOAT_EQ(vector_multiplacation1.GetX(), 6.0f); // Check x value
    ASSERT_FLOAT_EQ(vector_multiplacation1.GetY(), 4.0f); // Check y value
    ASSERT_FLOAT_EQ(vector_multiplacation1.GetZ(), -10.0f); // Check z value
    ASSERT_FLOAT_EQ(vector_multiplacation1.GetW(), 0.0f); // Check w value

    Tuple vector_multiplacation2 = Vector(3.0f, 2.0f, -5.0f);
    vector_multiplacation2 = vector_multiplacation2 * 2.0f;

    ASSERT_FLOAT_EQ(vector_multiplacation2.GetX(), 6.0f); // Check x value
    ASSERT_FLOAT_EQ(vector_multiplacation2.GetY(), 4.0f); // Check y value
    ASSERT_FLOAT_EQ(vector_multiplacation2.GetZ(), -10.0f); // Check z value
    ASSERT_FLOAT_EQ(vector_multiplacation2.GetW(), 0.0f); // Check w value
}

TEST(TupleTest, TupleDivisonTest) {
    Tuple test_tuple = Tuple(1.0f, -2.0f, 3.0f, -4.0f);
    test_tuple = test_tuple / 2.0f;

    ASSERT_FLOAT_EQ(test_tuple.GetX(), 0.5f); // Check x value
    ASSERT_FLOAT_EQ(test_tuple.GetY(), -1.0f); // Check y value
    ASSERT_FLOAT_EQ(test_tuple.GetZ(), 1.5f); // Check z value
    ASSERT_FLOAT_EQ(test_tuple.GetW(), -2.0f); // Check w value
}

TEST(TupleTest, TupleMagnitudeTest) {
    Tuple my_vector = Vector(1.0f, 0.0f, 0.0f);
    Tuple my_vector2 = Vector(0.0f, 1.0f, 0.0f);
    Tuple my_vector3 = Vector(0.0f, 0.0f, 1.0f);
    Tuple my_vector4 = Vector(1.0f, 2.0f, 3.0f);
    Tuple my_vector5 = Vector(1.0f, 2.0f, 3.0f);

    ASSERT_FLOAT_EQ(my_vector.Magnitude(), 1.0f);
    ASSERT_FLOAT_EQ(my_vector2.Magnitude(), 1.0f);
    ASSERT_FLOAT_EQ(my_vector3.Magnitude(), 1.0f);
    ASSERT_FLOAT_EQ(my_vector4.Magnitude(), sqrtf(14));
    ASSERT_FLOAT_EQ(my_vector5.Magnitude(), sqrtf(14));
}

TEST(TupleTest, TupleNormalizeTest) {
    Tuple unit_vector = Vector(4.0f, 0.0f, 0.0f);
    ASSERT_TRUE(Vector(1.0f, 0.0f, 0.0f) == unit_vector.Normalize());

    Tuple unit_vector2 = Vector(1.0f, 2.0f, 3.0f);
    Tuple norm_vector = unit_vector2.Normalize();
    ASSERT_TRUE(norm_vector == Vector(0.26726f, 0.53452f, 0.80178f));
    ASSERT_FALSE(norm_vector == Vector(4.9f, 0.53452f, 0.80178f));

    Tuple unit_vector3 = Vector(1.0f, 2.0f, 3.0f);
    ASSERT_FLOAT_EQ(unit_vector3.Normalize().Magnitude(), 1.0f);
}

TEST(TupleTest, TupleDotProductTest) {
    Tuple my_vector = Vector(1, 2, 0);
    float dot_product = my_vector.DotProduct(Vector(2, 3, 0));

    ASSERT_FLOAT_EQ(dot_product, 8.0f);
}

TEST(TupleTest, TupleCrossProductTest) {
    Tuple vector1 = Vector(1,2,3);
    Tuple vector2 = Vector(2,3,4);

    ASSERT_TRUE(vector1.CrossProduct(vector2) == Vector(-1,2,-1));
    ASSERT_TRUE(vector2.CrossProduct(vector1) == Vector(1,-2,1));
    ASSERT_FALSE(vector2.CrossProduct(vector1) == Vector(1,-2,6));
}

TEST(CannonTest, FireCannonTest) {
    Cannon test = Cannon();
    Projectile ball = test.LoadCannon(Point(0, 1, 0), Vector(1, 1, 0) * 10.0f);
    Environment env = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));
    test.FireCannon(ball, env);
}