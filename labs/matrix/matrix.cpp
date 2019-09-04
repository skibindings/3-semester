/** Copyright 2018 Kirill Skibin **/

#include "matrix.h"
#include <iostream>
#include <sstream>

using namespace std;

Matrix::Matrix(const int width, const int height) :
    width_(width), height_(height) {
    if (width_ < 0 || height_ < 0)
        throw logic_error("matrix row and column number should be >= 0");

    data_ = new double*[height];
    for (int i = 0; i < height_; i++) {
        data_[i] = new double[width];
    }
}

Matrix::Matrix(const Matrix& obj) {
    if (this != &obj) {
        width_ = obj.width();
        height_ = obj.height();

        data_ = new double*[height_];
        for (int i = 0; i < height_; i++) {
            data_[i] = new double[width_];
        }
        for (int x = 0; x < width_; x++) {
            for (int y = 0; y < height_; y++) {
                at(x, y) = obj.at(x, y);
            }
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < height_; i++) {
        delete [] data_[i];
    }
    delete [] data_;
}

Matrix& Matrix::operator=(const Matrix& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < height_; i++) {
            delete[] data_[i];
        }
        delete[] data_;

        width_ = rhs.width();
        height_ = rhs.height();

        data_ = new double*[height_];
        for (int i = 0; i < height_; i++) {
            data_[i] = new double[width_];
        }
        for (int x = 0; x < width_; x++) {
            for (int y = 0; y < height_; y++) {
                at(x, y) = rhs.at(x, y);
            }
        }
    }
    return *this;
}

double& Matrix::at(const int x, const int y) {
    if (!indexIsValid(x, y))
        throw logic_error("invalid index");

    return (data_[y])[x];
}

double& Matrix::at(const int x, const int y) const {
    if (!indexIsValid(x, y))
        throw logic_error("invalid index");

    return (data_[y])[x];
}

Matrix& operator*=(Matrix& lhs, const Matrix& rhs) {
    if(!(lhs.width() == rhs.height() && lhs.height() == rhs.width()))
        throw logic_error("inappropriate matrix size for multiplication");
    
    Matrix mul(lhs.height(), rhs.width());
    for (int x = 0; x < lhs.height(); x++) {
        for (int y = 0; y < rhs.width(); y++) {
            double value = 0;
            for (int i = 0; i < lhs.width(); i++) {
                value += lhs.at(i, y) * rhs.at(x, i);
            }
            mul.at(x, y) = value;
        }
    }
    lhs = mul;
    return lhs;
}

Matrix& operator*(const Matrix& lhs, const Matrix& rhs) {
    Matrix mul(lhs);
    mul *= rhs;
    return mul;
}

bool Matrix::indexIsValid(const int x, const int y) const {
    return (x >= 0 && x < width_ && y >= 0 && y < height_);
}

int Matrix::width() const {
    return width_;
}

int Matrix::height() const {
    return height_;
}

ostream& Matrix::writeTo(ostream& ostrm) {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            ostrm << at(j, i) << "  ";
        }
        ostrm << endl;
    }
    return ostrm;
}
