#include <gtest/gtest.h>
#include "Vector2D.h"

TEST(Vector2D_ADD_Operator, BasicAssertions) {
  Vector2D vector1(10.0, 5.0);
  Vector2D vector2(5.0, 5.0);
  vector1 += vector2 += vector2;
  EXPECT_FLOAT_EQ(20.0, vector1.getX());
  EXPECT_FLOAT_EQ(15.0, vector1.getY());
}

TEST(Vector2D_SUB_Operator, BasicAssertions) {
  Vector2D vector1(10.0, 5.0);
  Vector2D vector2(5.0, 5.0);
  vector1 -= vector2;
  EXPECT_FLOAT_EQ(5.0, vector1.getX());
  EXPECT_FLOAT_EQ(0.0, vector1.getY());
}

TEST(Vector2D_SUB_Operator2, BasicAssertions) {
  Vector2D vector1(10.0, 5.0);
  Vector2D vector2(5.0, 5.0);
  Vector2D vector3(0.0, 0.0);
  vector3 = vector1 - vector2;
  //Expect that vector3 lower then vector1 
  EXPECT_LT(vector3.length(), vector1.length()); 
  EXPECT_FLOAT_EQ(5.0, vector3.getX());
  EXPECT_FLOAT_EQ(0.0, vector3.getY());
}