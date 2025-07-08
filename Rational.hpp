// Rational.hpp - using Integer for arbitrary-precision rational numbers

#ifndef RATIONAL_H
#define RATIONAL_H


#include <iostream>
#include <stdexcept>
#include "Integer.hpp"

class Rational {
private:
    Integer numerator;
    Integer denominator;

    void normalize(); // Ensures denominator is positive and reduces fraction

public:
    // Constructors
    Rational(int value); 
    Rational(Integer num = 0, Integer denom = 1);
    Rational(float value);
    Rational(double value);

    // Accessors
    Integer getNumerator() const;
    Integer getDenominator() const;

    // Type conversion
    bool isInteger() const;
    double toDouble() const;

    // Arithmetic operators
    Rational operator+(const Rational& rhs) const;
    Rational operator-(const Rational& rhs) const;
    Rational operator*(const Rational& rhs) const;
    Rational operator/(const Rational& rhs) const;

    Rational operator-() const;

    // Compound assignment
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);

    // Assignment
    Rational& operator=(const Rational& other);

    // Comparison operators
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;
    bool operator<(const Rational& rhs) const;
    bool operator<=(const Rational& rhs) const;
    bool operator>(const Rational& rhs) const;
    bool operator>=(const Rational& rhs) const;

    // Stream I/O
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
};

#include "RationalComparisons.hpp"
#include "RationalArithmetic.hpp"

#endif // RATIONAL_H
