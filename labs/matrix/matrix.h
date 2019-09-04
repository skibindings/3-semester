/** Copyright 2018 Kirill Skibin **/

#ifndef LABS_MATRIX_MATRIX_H_
#define LABS_MATRIX_MATRIX_H_

#include <iostream>
#include <sstream>

class Matrix {
 public:
    Matrix() = default;
    explicit Matrix(const int width, const int height);
    Matrix(const Matrix& obj);

    ~Matrix();

    Matrix& operator=(const Matrix& rhs);

    double& at(const int x, const int y);
    double& at(const int x, const int y) const;

    int width() const;
    int height() const;

    std::ostream& writeTo(std::ostream& ostrm);

 private:
    int width_{ 0 };
    int height_{ 0 };
    double** data_{ nullptr };

    bool indexIsValid(const int column, const int row) const;
};

inline std::ostream& operator<<(std::ostream& ostrm, Matrix& rhs) {
    return rhs.writeTo(ostrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, Matrix* rhs) {
    return rhs->writeTo(ostrm);
}

Matrix& operator*=(Matrix& lhs, const Matrix& rhs);
Matrix& operator* (const Matrix& lhs, const Matrix& rhs);

#endif  // LABS_MATRIX_MATRIX_H_
