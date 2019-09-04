/** Copyright 2018 Kirill Skibin **/

#ifndef LABS_COMPLEX_COMPLEX_H_
#define LABS_COMPLEX_COMPLEX_H_

#include <iostream>
#include <sstream>

struct Complex {
 public:
    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);
    Complex(const Complex& obj) = default;
    bool operator==(const Complex& rhs) const {
        return (re == rhs.re) && (im == rhs.im);
    }
    bool operator!=(const Complex& rhs) const {
        return !operator==(rhs);
    }
    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);

    Complex& operator -() { re *= -1; return *this; }

    Complex& operator++() {
        re += 1.0;
        return *this;
    }

    Complex& operator--() {
        re -= 1.0;
        return *this;
    }

    Complex operator++(int) {
        Complex temp(re, im);
        ++(*this);
        return temp;
    }

    Complex operator--(int) {
        Complex temp(re, im);
        --(*this);
        return temp;
    }

    Complex& operator=(const Complex& rhs);
    Complex& operator=(const double rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

 private:
    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const double rhs);

Complex operator/(const double lhs, const Complex& rhs);
Complex operator*(const double lhs, const Complex& rhs);
Complex operator+(const double lhs, const Complex& rhs);
Complex operator-(const double lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
    return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
    return rhs.readFrom(istrm);
}

#endif  // LABS_COMPLEX_COMPLEX_H_
