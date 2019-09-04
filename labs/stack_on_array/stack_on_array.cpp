/** Copyright 2018 Kirill Skibin **/

#include "stack_on_array.h"

using namespace std;

StackOnArray::StackOnArray() :
    head_index_{-1} , physical_size_(kStartPhysicalSize) {
    data_ = new double[physical_size_];
}

StackOnArray::StackOnArray(const StackOnArray& obj) {
    if (this != &obj) {
        head_index_ = obj.head_index_;
        physical_size_ = obj.physical_size_;
        data_ = new double[physical_size_];

        for (int i = 0; i <= head_index_; i++) {
            data_[i] = obj.data_[i];
        }
    }
}

StackOnArray& StackOnArray::operator=(const StackOnArray& obj) {
    if (this != &obj) {
        delete[] data_;

        head_index_ = obj.head_index_;
        physical_size_ = obj.physical_size_;
        data_ = new double[physical_size_];

        for (int i = 0; i <= head_index_; i++) {
            data_[i] = obj.data_[i];
        }
    }
    return *this;
}

void StackOnArray::push(const double new_entry) {
    if (head_index_ == physical_size_ - 1) {
        resize(physical_size_*kExtensionValue);
    }
    head_index_++;
    data_[head_index_] = new_entry;
}

void StackOnArray::pop() {
    if (!isEmpty()) {
        head_index_--;
    }
}

double StackOnArray::top() const {
    if (isEmpty()) {
        throw std::logic_error("Logic error : Try get top from empty stack.");
    } else {
        return data_[head_index_];
    }
}

bool StackOnArray::isEmpty() const {
    return (head_index_ == -1);
}

void StackOnArray::clear() {
    head_index_ = -1;
}

void StackOnArray::resize(int new_size) {
    physical_size_ = new_size;

    double* new_data = new double[physical_size_];
    for (int i = 0; i <= head_index_; i++) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
}

ostream& StackOnArray::writeTo(std::ostream& ostrm) const {
    ostrm << '{';
    for (int i = head_index_; i >= 0; i--) {
        ostrm << data_[i];
        if (i != 0) {
            ostrm << ", ";
        }
    }
    ostrm << '}';
    return ostrm;
}

StackOnArray::~StackOnArray() {
    delete[] data_;
}
