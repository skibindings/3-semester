/** Copyright 2018 Kirill Skibin **/

#ifndef LABS_RATIONAL_RATIONAL_H_
#define LABS_RATIONAL_RATIONAL_H_

#include <iostream>
#include <sstream>
#include <cmath>

class Rational {
 public:
    Rational() {}
    explicit Rational(const int m);
    Rational(const int m, const int n);
    Rational(const Rational& obj) = default;

    bool operator==(const Rational& rhs) const {
        return (m == rhs.m) && (n == rhs.n);
    }
    bool operator!=(const Rational& rhs) const {
        return !operator==(rhs);
    }
    bool operator>(const Rational& rhs) const {
        return (m * rhs.n > rhs.m * n);
    }
    bool operator<(const Rational& rhs) const {
        return (m * rhs.n < rhs.m * n);
    }
    bool operator>=(const Rational& rhs) const {
        return operator>(rhs) || operator==(rhs);
    }
    bool operator<=(const Rational& rhs) const {
        return operator<(rhs) || operator==(rhs);
    }

    bool operator==(const int rhs) const {
        if (n != 1) return false;
        return (m == rhs);
    }
    bool operator!=(const int rhs) const {
        return !operator==(rhs);
    }
    bool operator>(const int rhs) const {
        return
            ((static_cast<double>(m) / static_cast<double>(n)) >
              static_cast<double>(rhs));
    }
    bool operator<(const int rhs) const {
        return
            ((static_cast<double>(m) / static_cast<double>(n)) <
              static_cast<double>(rhs));
    }
    bool operator>=(const int rhs) const {
        return operator>(rhs) || operator==(rhs);
    }
    bool operator<=(const int rhs) const {
        return operator<(rhs) || operator==(rhs);
    }

    Rational& operator=(const Rational& rhs);
    Rational& operator=(const int rhs);

    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs) {
        return operator+=(Rational(rhs));
    }
    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const int rhs) {
        return operator-=(Rational(rhs));
    }

    Rational& operator*=(const Rational& rhs);
    Rational& operator*=(const int rhs);
    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const int rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    Rational& operator -() { m *= -1; return *this; }

    Rational& operator++();
    Rational& operator--();
    Rational operator++(int);
    Rational operator--(int);

    Rational operator/(const Rational& rhs);
    Rational operator*(const Rational& rhs);
    Rational operator+(const Rational& rhs);
    Rational operator-(const Rational& rhs);

    Rational operator/(const int rhs);
    Rational operator*(const int rhs);
    Rational operator+(const int rhs);
    Rational operator-(const int rhs);

 private:
    void normalize();

    int m{ 0 };
    unsigned int n{ 1 };

    static const char leftBrace{ '{' };
    static const char separator{ '/' };
    static const char rightBrace{ '}' };
};

inline Rational operator/(const int lhs, const Rational& rhs) {
    Rational div(rhs);
    div = Rational(lhs)/ div;
    return div;
}

inline Rational operator*(const int lhs, const Rational& rhs) {
    Rational mul(rhs);
    mul = Rational(lhs)*mul;
    return mul;
}

inline Rational operator+(const int lhs, const Rational& rhs) {
    Rational sum(rhs);
    sum = Rational(lhs)+sum;
    return sum;
}

inline Rational operator-(const int lhs, const Rational& rhs) {
    Rational sub(rhs);
    sub = Rational(lhs)- sub;
    return sub;
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
    return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
    return rhs.readFrom(istrm);
}

#endif  // LABS_RATIONAL_RATIONAL_H_
