/** Copyright 2018 Kirill Skibin **/

#include "complex.h"

using namespace std;

Complex::Complex(const double real) : Complex(real, 0.0) {}

Complex::Complex(const double real, const double imaginary) :
    re(real),
    im(imaginary) {}

// COMPLEX - COMPLEX

Complex operator/(const Complex& lhs, const Complex& rhs) {
    Complex div(lhs);
    div /= rhs;
    return div;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    Complex mul(lhs);
    mul *= rhs;
    return mul;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    Complex sub(lhs);
    sub -= rhs;
    return sub;
}

// COMPLEX - DOUBLE

Complex operator/(const Complex& lhs, const double rhs) {
    Complex div(lhs);
    div /= rhs;
    return div;
}

Complex operator*(const Complex& lhs, const double rhs) {
    Complex mul(lhs);
    mul *= rhs;
    return mul;
}

Complex operator+(const Complex& lhs, const double rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const double rhs) {
    Complex sub(lhs);
    sub -= rhs;
    return sub;
}

// DOUBLE - COMPLEX

Complex operator/(const double lhs, const Complex& rhs) {
    Complex div(rhs);
    div = Complex(lhs)/ div;
    return div;
}

Complex operator*(const double lhs, const Complex& rhs) {
    Complex mul(rhs);
    mul = Complex(lhs)*mul;
    return mul;
}

Complex operator+(const double lhs, const Complex& rhs) {
    Complex sum(rhs);
    sum = Complex(lhs)+ sum;
    return sum;
}

Complex operator-(const double lhs, const Complex& rhs) {
    Complex sub(rhs);
    sub = Complex(lhs)-sub;
    return sub;
}

//

Complex& Complex::operator=(const Complex& rhs) {
    if (this != &rhs) {
        re = rhs.re;
        im = rhs.im;
    }
    return *this;
}

Complex& Complex::operator=(const double rhs) {
    re = rhs;
    im = 0;
    return *this;
}

Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator*=(const double rhs) {
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
    int temp_re = re;

    re = temp_re * rhs.re - im * rhs.im;
    im = temp_re * rhs.im + rhs.re*im;
    return *this;
}

Complex& Complex::operator/=(const double rhs) {
    re /= rhs;
    im /= rhs;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
    int temp_re = re;

    re = (temp_re*rhs.re+im*rhs.im)/(rhs.re*rhs.re+rhs.im*rhs.im);
    im = (rhs.re*im-temp_re*rhs.im)/(rhs.re*rhs.re+rhs.im*rhs.im);
    return *this;
}

ostream& Complex::writeTo(ostream& ostrm) const {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

istream& Complex::readFrom(istream& istrm) {
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) &&
            (Complex::separator == comma) &&
            (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;
        } else {
            istrm.setstate(ios_base::failbit);
        }
    }

    return istrm;
}
