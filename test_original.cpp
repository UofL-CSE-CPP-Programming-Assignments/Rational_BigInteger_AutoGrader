#include <gtest/gtest.h>
#include "Rational.hpp"
#include <sstream>

#define EXPECT_RATIONAL(r, num, denom) \
    EXPECT_EQ((r).getNumerator(), (num)); \
    EXPECT_EQ((r).getDenominator(), (denom))

TEST(RationalTest, ConstructionAndNormalization) {
    EXPECT_RATIONAL(Rational(4, 8), 1, 2);
    EXPECT_RATIONAL(Rational(-2, 4), -1, 2);
    EXPECT_RATIONAL(Rational(6, -9), -2, 3);
    EXPECT_RATIONAL(Rational(-3, -6), 1, 2);
    EXPECT_RATIONAL(Rational(5), 5, 1);
}

TEST(RationalTest, ConstructionFromFloatDouble) {
    EXPECT_RATIONAL(Rational(0.5), 1, 2);
    // EXPECT_RATIONAL(Rational(-0.25f), -1, 4);
    EXPECT_RATIONAL(Rational(2.75), 11, 4);
}

TEST(RationalTest, ArithmeticWithRational) {
    Rational a(1, 2), b(1, 3);
    EXPECT_RATIONAL(a + b, 5, 6);
    EXPECT_RATIONAL(a - b, 1, 6);
    EXPECT_RATIONAL(a * b, 1, 6);
    EXPECT_RATIONAL(a / b, 3, 2);
}

TEST(RationalTest, ArithmeticWithMixedTypes) {
    Rational a(1, 2);
    EXPECT_RATIONAL(a + 1, 3, 2);
    EXPECT_RATIONAL(a - 0.5, 0, 1);
    EXPECT_RATIONAL(a * 2, 1, 1);
    EXPECT_RATIONAL(a / 0.25, 2, 1);
}

TEST(RationalTest, MixedTypeCompoundAssignments) {
    Rational a(1, 2);
    a += 1;
    EXPECT_RATIONAL(a, 3, 2);
    a -= 0.5;
    EXPECT_RATIONAL(a, 1, 1);
    a *= 2;
    EXPECT_RATIONAL(a, 2, 1);
    a /= 4.0;
    EXPECT_RATIONAL(a, 1, 2);
}

TEST(RationalTest, ComparisonOperators) {
    Rational a(1, 2), b(2, 4), c(3, 4);
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(a != c);
    EXPECT_TRUE(c > a);
    EXPECT_TRUE(a < c);
    EXPECT_TRUE(c >= b);
    EXPECT_TRUE(a <= b);
}

TEST(RationalTest, ComparisonWithMixedTypes) {
    Rational a(3, 2);
    EXPECT_TRUE(a == 1.5);
    EXPECT_TRUE(a > 1);
    EXPECT_TRUE(a >= 1.5);
    EXPECT_TRUE(a != 2);
    EXPECT_TRUE(a < 2);
    EXPECT_TRUE(a <= 2.5);
    EXPECT_TRUE(a < 4);
    EXPECT_TRUE(a > 1.0);
    EXPECT_TRUE(a >= 1.0);
    EXPECT_TRUE(a <= 3.0);
    EXPECT_TRUE(a < 3.0);
    EXPECT_TRUE(a <= 3.5);
}

TEST(RationalTest, StreamOutput) {
    Rational r1(3, 4), r2(5, 1);
    std::ostringstream os1, os2;
    os1 << r1;
    os2 << r2;
    EXPECT_EQ(os1.str(), "3/4");
    EXPECT_EQ(os2.str(), "5");
}

TEST(RationalTest, StreamInput) {
    Rational r;
    std::istringstream is("3/4");
    is >> r;
    EXPECT_RATIONAL(r, 3, 4);

    std::istringstream is2("5");
    is2 >> r;
    EXPECT_RATIONAL(r, 5, 1);
}

TEST(RationalTest, ToDoubleAndIsInteger) {
    Rational a(3, 2), b(4, 2);
    EXPECT_DOUBLE_EQ(a.toDouble(), 1.5);
    EXPECT_TRUE(b.isInteger());
    EXPECT_FALSE(a.isInteger());
}

TEST(RationalTest, DivisionByZeroThrows) {
    Rational a(1, 2), zero(0, 1);
    EXPECT_THROW(a / zero, std::domain_error);
    EXPECT_THROW(Rational(5) / 0, std::domain_error);
    EXPECT_THROW(Rational(5) / 0.0, std::domain_error);
}



TEST(RationalTest, ConstructionAndNormalization_Expanded) {
    EXPECT_RATIONAL(Rational(2, 4), 1, 2);
    EXPECT_RATIONAL(Rational(4, 8), 1, 2);
    EXPECT_RATIONAL(Rational(6, 12), 1, 2);
    EXPECT_RATIONAL(Rational(-3, 3), -1, 1);
    EXPECT_RATIONAL(Rational(-6, 6), -1, 1);
    EXPECT_RATIONAL(Rational(1,2), 1, 2);

}

TEST(RationalTest, ArithmeticWithRational_Expanded) {
    EXPECT_NO_THROW(Rational(1, -2) + Rational(2, -3));
    EXPECT_NO_THROW(Rational(-1, 2) * Rational(-2, 3));
    EXPECT_NO_THROW(Rational(2, -3) + Rational(-3, 4));
    EXPECT_NO_THROW(Rational(2, 3) * Rational(3, 4));
    EXPECT_NO_THROW(Rational(-3, -4) + Rational(-4, -5));

}

TEST(RationalTest, MixedTypeCompoundAssignments_Expanded) {
    Rational r1(1, 2); r1 += 2.14;
    r1 *= 2.14; EXPECT_NO_THROW(r1.toDouble());
    Rational r2(1, 2); r2 += 2.28;
    r2 *= 2.28; EXPECT_NO_THROW(r2.toDouble());
    Rational r3(1, 2); r3 += 2.36;
    r3 *= 2.36; EXPECT_NO_THROW(r3.toDouble());
    Rational r4(1, 2); r4 += 3.96;
    r4 *= 3.96; EXPECT_NO_THROW(r4.toDouble());
    Rational r5(1, 2); r5 += 3.83;
    r5 *= 3.83; EXPECT_NO_THROW(r5.toDouble());
    Rational r6(1, 2); r6 += 1.85;
    r6 *= 1.85; EXPECT_NO_THROW(r6.toDouble());
    Rational r7(1, 2); r7 += 3.84;
    r7 *= 3.84; EXPECT_NO_THROW(r7.toDouble());
 
}

TEST(RationalTest, ComparisonOperators_Expanded) {
    EXPECT_TRUE(Rational(1, 2) < Rational(2, 3));
    EXPECT_FALSE(Rational(2, 3) < Rational(1, 2));
    EXPECT_TRUE(Rational(2, 3) < Rational(3, 4));
    EXPECT_FALSE(Rational(3, 4) < Rational(2, 3));
    EXPECT_TRUE(Rational(3, 4) < Rational(4, 5));
    EXPECT_FALSE(Rational(4, 5) < Rational(3, 4));
    EXPECT_TRUE(Rational(4, 5) < Rational(5, 6));
    EXPECT_FALSE(Rational(5, 6) < Rational(4, 5));
    EXPECT_TRUE(Rational(5, 6) < Rational(6, 7));
    EXPECT_FALSE(Rational(6, 7) < Rational(5, 6));
    EXPECT_TRUE(Rational(6, 7) < Rational(7, 8));
    EXPECT_FALSE(Rational(7, 8) < Rational(6, 7));
    EXPECT_TRUE(Rational(7, 8) < Rational(8, 9));
    EXPECT_FALSE(Rational(8, 9) < Rational(7, 8));
    EXPECT_TRUE(Rational(8, 9) < Rational(9, 10));
    EXPECT_FALSE(Rational(9, 10) < Rational(8, 9));
    EXPECT_TRUE(Rational(9, 10) < Rational(10, 11));
    EXPECT_FALSE(Rational(10, 11) < Rational(9, 10));
    EXPECT_TRUE(Rational(10, 11) < Rational(11, 12));
    EXPECT_FALSE(Rational(11, 12) < Rational(10, 11));
    EXPECT_TRUE(Rational(11, 12) < Rational(12, 13));
    EXPECT_FALSE(Rational(12, 13) < Rational(11, 12));
    EXPECT_TRUE(Rational(12, 13) < Rational(13, 14));
    EXPECT_FALSE(Rational(13, 14) < Rational(12, 13));
    EXPECT_TRUE(Rational(13, 14) < Rational(14, 15));
    EXPECT_FALSE(Rational(14, 15) < Rational(13, 14));
    EXPECT_TRUE(Rational(14, 15) < Rational(15, 16));
    EXPECT_FALSE(Rational(15, 16) < Rational(14, 15));
    EXPECT_TRUE(Rational(15, 16) < Rational(16, 17));
    EXPECT_FALSE(Rational(16, 17) < Rational(15, 16));
    EXPECT_TRUE(Rational(16, 17) < Rational(17, 18));
    EXPECT_FALSE(Rational(17, 18) < Rational(16, 17));
    EXPECT_TRUE(Rational(17, 18) < Rational(18, 19));
    EXPECT_FALSE(Rational(18, 19) < Rational(17, 18));
    EXPECT_TRUE(Rational(18, 19) < Rational(19, 20));
    EXPECT_FALSE(Rational(19, 20) < Rational(18, 19));
    EXPECT_TRUE(Rational(19, 20) < Rational(20, 21));
    EXPECT_FALSE(Rational(20, 21) < Rational(19, 20));
    EXPECT_TRUE(Rational(20, 21) < Rational(21, 22));
    EXPECT_FALSE(Rational(21, 22) < Rational(20, 21));
    EXPECT_TRUE(Rational(21, 22) < Rational(22, 23));
    EXPECT_FALSE(Rational(22, 23) < Rational(21, 22));
    EXPECT_TRUE(Rational(22, 23) < Rational(23, 24));
    EXPECT_FALSE(Rational(23, 24) < Rational(22, 23));
    EXPECT_TRUE(Rational(23, 24) < Rational(24, 25));
    EXPECT_FALSE(Rational(24, 25) < Rational(23, 24));
    EXPECT_TRUE(Rational(24, 25) < Rational(25, 26));
    EXPECT_FALSE(Rational(25, 26) < Rational(24, 25));
    EXPECT_TRUE(Rational(25, 26) < Rational(26, 27));
    EXPECT_FALSE(Rational(26, 27) < Rational(25, 26));
}

TEST(RationalTest, StreamOperations_Expanded) {
    Rational s1(1, 2); std::ostringstream os1; os1 << s1; EXPECT_FALSE(os1.str().empty());
    std::istringstream is1("1/2"); Rational r1; is1 >> r1; EXPECT_RATIONAL(r1, 1, 2);
    Rational s2(2, 3); std::ostringstream os2; os2 << s2; EXPECT_FALSE(os2.str().empty());
    std::istringstream is2("2/3"); Rational r2; is2 >> r2; EXPECT_RATIONAL(r2, 2, 3);
    Rational s3(3, 4); std::ostringstream os3; os3 << s3; EXPECT_FALSE(os3.str().empty());
    std::istringstream is3("-3/4"); Rational r3; is3 >> r3; EXPECT_RATIONAL(r3, -3, 4);
    Rational s4(4, 5); std::ostringstream os4; os4 << s4; EXPECT_FALSE(os4.str().empty());


}

TEST(RationalTest, DivisionByZeroThrows_Expanded) {
    EXPECT_THROW(Rational(1) / Rational(0, 1), std::domain_error);
    EXPECT_THROW(Rational(2) / Rational(0, 12), std::domain_error);
    EXPECT_THROW(Rational(3) / Rational(0, -13), std::domain_error);
    EXPECT_THROW(Rational(24) / Rational(0, 6), std::domain_error);
}

TEST(RationalTest, ConstructionWithZeroDenominatorThrows) {
    EXPECT_THROW(Rational(1, 0), std::invalid_argument);
    EXPECT_THROW(Rational(0, 0), std::invalid_argument);  
}
