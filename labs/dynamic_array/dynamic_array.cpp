/** Copyright 2018 Kirill Skibin **/

#include "dynamic_array.h"
#include <iostream>
#include <sstream>

using namespace std;

DynamicArray::DynamicArray(const int max_size) :
    physical_size_(max_size) , logical_size_(0) {
    if (max_size < 0)
        throw std::logic_error("array size should me >= 0");

    data_ = new double[physical_size_];
}

DynamicArray::DynamicArray(const DynamicArray& obj) {
    if (this != &obj) {
        physical_size_ = obj.physical_size_;
        logical_size_ = obj.logical_size_;
        data_ = new double[physical_size_];
        for (int i = 0; i < obj.logical_size_; i++) {
            data_[i] = obj[i];
        }
    }
}

DynamicArray::~DynamicArray() {
    delete[] data_;
}

void DynamicArray::add(double new_entry) {
    if (physical_size_ <= 0) {
        throw logic_error("invalid array size");
    }
    if (logical_size_ + 1 > physical_size_) {
        resize(static_cast<double>(physical_size_) * kExtensionValue);
    }
    data_[logical_size_] = new_entry;
    logical_size_++;
}

void DynamicArray::set(int i, double entry) {
    if (!indexIsValid(i)) {
        throw logic_error("index is out of range");
    }
    data_[i] = entry;
}

void DynamicArray::remove(int i) {
    if (!indexIsValid(i)) {
        throw logic_error("index is out of range");
    }
    for (int j = i; j < logical_size_ - 1; j++) {
        data_[j] = data_[j + 1];
    }

    logical_size_--;
}

int DynamicArray::size() const {
    return logical_size_;
}

void DynamicArray::resize(int new_size) {
    physical_size_ = new_size;
    if (logical_size_ > new_size)
        logical_size_ = new_size;

    double* new_data = new double[physical_size_];
    for (int i = 0; i < logical_size_; i++) {
        new_data[i] = data_[i];
    }
    data_ = new_data;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& rhs) {
    if (this != &rhs) {
        delete[] data_;

        physical_size_ = rhs.physical_size_;
        logical_size_ = rhs.logical_size_;
        data_ = new double[physical_size_];
        for (int i = 0; i < rhs.logical_size_; i++) {
            data_[i] = rhs[i];
        }
    }
    return *this;
}

double& DynamicArray::operator[] (const int i) {
    if (!indexIsValid(i)) {
        throw logic_error("index is out of range");
    }

    return data_[i];
}

double& DynamicArray::operator[] (const int i) const {
    if (!indexIsValid(i)) {
        throw logic_error("index is out of range");
    }

    return data_[i];
}

bool DynamicArray::indexIsValid(const int i) const {
    return (i >= 0 && i < logical_size_);
}


std::ostream& DynamicArray::writeTo(std::ostream& ostrm) const {
    ostrm << kLeftBrace;
    for (int i = 0; i < logical_size_; i++) {
        ostrm << (*this)[i];
        if (i + 1 != logical_size_) {
            ostrm << kSeparator << " ";
        }
    }
    ostrm << kRightBrace;
    return ostrm;
}
