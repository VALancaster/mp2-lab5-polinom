#include "polinom.h"
#include "polinom.cpp"
#include <gtest.h>

TEST(Polinom, can_create_empty_polinom)
{
	EXPECT_NO_THROW(Polinom p);
}

TEST(Polinom, can_create_polinom_from_string)
{
	EXPECT_NO_THROW(Polinom p("1x2y0z0+2x1y0z0+1x0y0z0"));
}

TEST(Polinom, can_turn_polinom_into_string)
{
	Polinom p("1x2y0z0+2x1y0z0+3x0y2z2");

	cout << p.toString();
	
	EXPECT_EQ(p.toString(), " + 3x^0y^2z^2 + 2x^1y^0z^0 + 1x^2y^0z^0");
}

TEST(Polinom, can_create_empty_string) 
{
	Polinom p("");
	EXPECT_EQ(p.toString(), "0");
}

TEST(Polinom, can_simplify) 
{
	Polinom p("1x2y0z0+1x2y0z0");

	p.simplify();

	EXPECT_EQ(p.toString(), " + 2x^2y^0z^0");
}

TEST(Polinom, can_add_polinoms) 
{
    Polinom p1("1x2y0z0+2x1y0z0");
    Polinom p2("3x0y2z2+4x2y0z0");

    Polinom result = p1 + p2;

    EXPECT_EQ(result.toString(), " + 3x^0y^2z^2 + 5x^2y^0z^0 + 2x^1y^0z^0");
}

TEST(Polinom, can_subtract_polinoms) 
{
    Polinom p1("1x2y0z0+2x1y0z0");
    Polinom p2("3x0y2z2+4x2y0z0");

    Polinom result = p1 - p2;

    EXPECT_EQ(result.toString(), " - 3x^0y^2z^2 - 3x^2y^0z^0 + 2x^1y^0z^0");
}

TEST(Polinom, can_multiply_polinom_by_scalar) 
{
    Polinom p("1x2y0z0+2x1y0z0");

    Polinom result = p * 2.0;

    EXPECT_EQ(result.toString(), " + 2x^2y^0z^0 + 4x^1y^0z^0");
}

TEST(Polinom, can_take_the_derivative_of_x) 
{
    Polinom p("1x2y0z0+2x1y0z0");

    Polinom result = p.derivativeX();

    EXPECT_EQ(result.toString(), " + 2x^1y^0z^0 + 2x^0y^0z^0");
}

TEST(Polinom, can_assign_polinom) 
{
    Polinom p1("1x2y0z0+2x1y0z0");

    Polinom p2 = p1;

    EXPECT_EQ(p2.toString(), " + 2x^1y^0z^0 + 1x^2y^0z^0");
}
