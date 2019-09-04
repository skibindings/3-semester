/** Copyright 2018 Kirill Skibin **/

#include "rational.h"

using namespace std;

Rational::Rational(const int m) : Rational(m, 1) {}

Rational::Rational(const int m, const int n) {
    if (n == 0) {
        throw std::logic_error("n should be more than zero");
    }

    this->m = m * (n / abs(n));
    this->n = n;

    normalize();
}

void Rational::normalize() {
    for (int i = 2; i <= fmax(m, n); i++) {
        if (m % i == 0 && n % i == 0) {
            m /= i;
            n /= i;
            i = 1;
            continue;
        }
    }
}

Rational& Rational::operator=(const Rational& rhs) {
    if (this != &rhs) {
        m = rhs.m;
        n = rhs.n;
    }
    return *this;
}

Rational& Rational::operator=(const int rhs) {
    m = rhs;
    n = 1;
    return *this;
}

Rational& Rational::operator+=(const Rational& rhs) {
    m *= rhs.n;
    m += rhs.m*n;
    n *= rhs.n;
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
    m *= rhs.n;
    m -= rhs.m*n;
    n *= rhs.n;
    normalize();
    return *this;
}

Rational Rational::operator*(const Rational& rhs) {
    Rational mul(*this);
    mul *= rhs;
    return mul;
}

Rational Rational::operator/(const Rational& rhs) {
    Rational mul(*this);
    mul /= rhs;
    return mul;
}

Rational Rational::operator+(const Rational& rhs) {
    Rational sum(*this);
    sum += rhs;
    return sum;
}

Rational Rational::operator-(const Rational& rhs) {
    Rational sub(*this);
    sub -= rhs;
    return sub;
}

Rational& Rational::operator*=(const int rhs) {
    m *= rhs;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
    m *= rhs.m;
    n *= rhs.n;
    normalize();
    return *this;
}

Rational& Rational::operator/=(const int rhs) {
    if (rhs == 0)
        throw std::logic_error("divide by zero is prohibited");

    n *= rhs;
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    m *= rhs.n;
    n *= rhs.m;
    normalize();
    return *this;
}

Rational Rational::operator/(const int rhs) {
    Rational div(*this);
    div /= rhs;
    return div;
}

Rational Rational::operator*(const int rhs) {
    Rational mul(*this);
    mul *= rhs;
    return mul;
}

Rational Rational::operator+(const int rhs) {
    Rational sum(*this);
    sum += rhs;
    return sum;
}

Rational Rational::operator-(const int rhs) {
    Rational sub(*this);
    sub -= rhs;
    return sub;
}

Rational& Rational::operator++() {
    m += n;
    return *this;
}

Rational& Rational::operator--() {
    m += n;
    return *this;
}

Rational Rational::operator++(int) {
    Rational temp(m, n);
    ++(*this);
    return temp;
}

Rational Rational::operator--(int) {
    Rational temp(m, n);
    --(*this);
    return temp;
}

ostream& Rational::writeTo(ostream& ostrm) const {
    ostrm << leftBrace << m << separator << n << rightBrace;
    return ostrm;
}

istream& Rational::readFrom(istream& istrm) {
    char leftBrace(0);
    int m_(0);
    char comma(0);
    int n_(0);
    char rightBrace(0);
    istrm >> leftBrace >> m_ >> comma >> n_ >> rightBrace;

    if (n_ == 0)
        throw std::logic_error("divide by zero is prohibited");

    if (istrm.good()) {
        if ((Rational::leftBrace == leftBrace) &&
            (Rational::separator == comma) &&
            (Rational::rightBrace == rightBrace)) {
            m = m_*(n_/abs(n_));
            n = abs(n_);
        } else {
            istrm.setstate(ios_base::failbit);
        }
    }

    return istrm;
}
