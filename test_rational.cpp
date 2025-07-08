#include <gtest/gtest.h>
#include "Rational.hpp"
#include <sstream>

TEST(RationalTest, BasicConstruction) {
    Rational r(3, 4);
    EXPECT_EQ(r.getNumerator(), 3);
    EXPECT_EQ(r.getDenominator(), 4);
}



TEST(RationalTest, ConstructAndNormalizeBig) {
    Integer a("100000000000000000000000000000");
    Integer b("250000000000000000000000000000");
    Rational r(a, b);
    EXPECT_EQ(r.getNumerator(), Integer(2));
    EXPECT_EQ(r.getDenominator(), Integer(5));
}

TEST(RationalTest, NegativeNumeratorBig) {
    Integer a("-12345678901234567890");
    Integer b("98765432109876543210");
    Rational r(a, b);
    EXPECT_TRUE(r.getNumerator() < Integer(0));
    EXPECT_TRUE(r.getDenominator() > Integer(0));
}

TEST(RationalTest, NegativeDenominatorBig) {
    Integer a("999999999999999999");
    Integer b("-333333333333333333");
    Rational r(a, b);
    EXPECT_EQ(r.getNumerator(), Integer(-3));
    EXPECT_EQ(r.getDenominator(), Integer(1));
}

TEST(RationalTest, ArithmeticAddBig) {
    Rational r1(Integer("1"), Integer("3"));
    Rational r2(Integer("2"), Integer("3"));
    Rational sum = r1 + r2;
    EXPECT_EQ(sum.getNumerator(), Integer(1));
    EXPECT_EQ(sum.getDenominator(), Integer(1));
}

TEST(RationalTest, ArithmeticMulBig) {
    Rational r1(Integer("3"), Integer("4"));
    Rational r2(Integer("8"), Integer("9"));
    Rational prod = r1 * r2;
    EXPECT_EQ(prod.getNumerator(), Integer(2));
    EXPECT_EQ(prod.getDenominator(), Integer(3));
}

TEST(RationalTest, ComparisonBig) {
    Rational r1(Integer("12345678901234567890"), Integer("10000000000000000000"));
    Rational r2(Integer("22345678901234567890"), Integer("20000000000000000000"));
    Integer a("33333333333333333333333333333333333333333333333333333333333333333333333333333");
    Integer b("66666666666666666666666666666666666666666666666666666666666666666666666666666");
    Rational r3(a, b); // 1/2
    Integer c("12121212121212121212121212121212121212121212121212121212121212121212121212121");
    Integer d("24242424242424242424242424242424242424242424242424242424242424242424242424242");
    Rational r4(c, d); // 1/2
    EXPECT_TRUE(r1 > r2);
    EXPECT_TRUE(-r1 < -r2);

    EXPECT_FALSE(r2 > r1);
    EXPECT_FALSE(-r2 < -r1);

    EXPECT_TRUE(r1 >= r2);
    EXPECT_TRUE(-r1 <= -r2);

    EXPECT_TRUE(r2 < r1);
    EXPECT_TRUE(-r2 > -r1);

    EXPECT_TRUE(r2 <= r1);
    EXPECT_TRUE(-r2 >= -r1);

    EXPECT_TRUE(r3 == r4);
    EXPECT_TRUE(-r3 == -r4);

    EXPECT_FALSE(r3 != r4);
    EXPECT_FALSE(-r3 != -r4);


    EXPECT_TRUE(r3 < r1);
    EXPECT_TRUE(-r3 > -r1);

    EXPECT_FALSE(r1 < r3);
    EXPECT_TRUE(-r1 < -r3);
    EXPECT_FALSE(-r1 > -r3);

    EXPECT_TRUE(r1 >= r3);
    EXPECT_FALSE(-r1 >= -r3);

    EXPECT_FALSE(r3 >= r1);
    EXPECT_TRUE(-r3 >= -r1);

    EXPECT_TRUE(r1 >= r4);
    EXPECT_TRUE(-r1 <= -r4);
    EXPECT_FALSE(r4 >= r1);

    EXPECT_TRUE(r4 <= r3);
    EXPECT_TRUE(r3 <= r4);
    EXPECT_TRUE(r4 >= r3);
    EXPECT_TRUE(r3 >= r4);

    EXPECT_TRUE(-(-r3) == r4);
}

TEST(RationalTest, ToDoubleBig) {
    Rational r(Integer("50000000000000000000"), Integer("10000000000000000000"));
    EXPECT_DOUBLE_EQ(r.toDouble(), 5.0);
}

TEST(RationalTest, StreamInputBig) {
    std::istringstream is("123456789012345678901234567890/98765432109876543210");
    Rational r;
    is >> r;
    EXPECT_EQ(r.getNumerator(), Integer("1371742100137174210013717421")); // normalized
    EXPECT_EQ(r.getDenominator(), Integer("1097393690109739369"));
}

TEST(RationalTest, StreamOutputBig) {
    Rational r(Integer("-1234567890123456789"), Integer("9876543210"));
    std::ostringstream os;
    os << r;
    EXPECT_TRUE(os.str().find("-") == 0);  // starts with '-'
    EXPECT_NE(os.str().find("/"), std::string::npos);  // contains '/'
}
