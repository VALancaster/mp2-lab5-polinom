#include "monom.h"
#include "monom.cpp"
#include <gtest.h>

TEST(Monom, can_create_monom_with_valid_degrees)
{
    EXPECT_NO_THROW(Monom m(2.4, 1, 1, 0));
}

TEST(Monom, cant_create_monom_with_invalid_degrees)
{
    EXPECT_THROW(Monom m(1.0, 100, -100, 50), std::invalid_argument);
}

TEST(Monom, can_create_copied_monom)
{
    Monom m1(3.3, 4, 8, 5);
    Monom m2(m1);

    EXPECT_EQ(m2.getCoef(), 3.3);
    EXPECT_EQ(m2.getX(), 4);
    EXPECT_EQ(m2.getY(), 8);
    EXPECT_EQ(m2.getZ(), 5);
}

TEST(Monom, can_assign_monom)
{
    Monom m1(1.25, 1, 2, 3);
    Monom m2;

    m2 = m1;

    EXPECT_EQ(m2.getCoef(), 1.25);
    EXPECT_EQ(m2.getX(), 1);
    EXPECT_EQ(m2.getY(), 2);
    EXPECT_EQ(m2.getZ(), 3);
}

TEST(Monom, can_compare_equal_monoms)
{
    Monom m1(3.5, 1, 2, 3);
    Monom m2(3.5, 1, 2, 3);
    EXPECT_TRUE(m1 == m2);
}

TEST(Monom, can_compare_not_equal_monoms)
{
    Monom m1(3.5, 1, 2, 3);
    Monom m2(3.5, 2, 4, 6);
    EXPECT_TRUE(m1 < m2);
}

TEST(Monom, getters_return_values)
{
    Monom m(5.0, 2, 3, 4);

    EXPECT_EQ(m.getCoef(), 5.0);
    EXPECT_EQ(m.getX(), 2);
    EXPECT_EQ(m.getY(), 3);
    EXPECT_EQ(m.getZ(), 4);
}

TEST(Monom, setters_can_set_values)
{
    Monom m;

    m.setCoef(5.0);
    m.setX(2);
    m.setY(3);
    m.setZ(4);

    EXPECT_EQ(m.getCoef(), 5.0);
    EXPECT_EQ(m.getX(), 2);
    EXPECT_EQ(m.getY(), 3);
    EXPECT_EQ(m.getZ(), 4);
}

