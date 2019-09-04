/** Copyright 2018 Kirill Skibin **/

#include "queue_on_array.h"

using namespace std;

QueueOnArray::QueueOnArray() :
    physical_size_(kStartPhysicalSize) , logical_size_(0),
    i_begin_(0), i_end_(0) {
    data_ = new double[physical_size_];
}

QueueOnArray::QueueOnArray(const QueueOnArray& obj) {
    if (this != &obj) {
        physical_size_ = obj.physical_size_;
        logical_size_ = obj.logical_size_;
        i_begin_ = obj.i_begin_;
        i_end_ = obj.i_end_;

        data_ = new double[physical_size_];
        for (int i = 0; i < obj.physical_size_; i++) {
            data_[i] = obj.data_[i];
        }
    }
}

QueueOnArray::~QueueOnArray() {
    delete[] data_;
}

QueueOnArray& QueueOnArray::operator=(const QueueOnArray& rhs) {
    if (this != &rhs) {
        delete[] data_;

        physical_size_ = rhs.physical_size_;
        logical_size_ = rhs.logical_size_;
        i_begin_ = rhs.i_begin_;
        i_end_ = rhs.i_end_;
        data_ = new double[physical_size_];

        for (int i = 0; i < rhs.physical_size_; i++) {
            data_[i] = rhs.data_[i];
        }
    }
    return *this;
}

void QueueOnArray::push(const double new_entry) {
    if ((i_end_ + 1) % physical_size_ == i_begin_) {  // physical array is full
        resize(physical_size_*kExtensionValue);
    }

    data_[i_end_] = new_entry;
    i_end_ = (i_end_ + 1) % physical_size_;
    logical_size_++;
}

void QueueOnArray::pop() {
    if (!isEmpty()) {
        i_begin_ = (i_begin_ +1) % physical_size_;
        logical_size_--;
    }
}

double QueueOnArray::front() {
    if (isEmpty())
        throw std::logic_error("Logic error : Try get front from empty queue.");

    return data_[i_begin_];
}

bool QueueOnArray::isEmpty() const {
    return (logical_size_ == 0);
}

void QueueOnArray::clear() {
    i_begin_ = 0;
    i_end_ = 0;
    logical_size_ = 0;
}

int QueueOnArray::size() const {
    return logical_size_;
}

void QueueOnArray::resize(const int new_size) {
    int old_physcial_size = physical_size_;
    physical_size_ = new_size;
    if (logical_size_ > new_size)
        logical_size_ = new_size;

    double* new_data = new double[physical_size_];
    for (int i = 0; i < logical_size_; i++) {
        new_data[i] = data_[(i_begin_+i) % old_physcial_size];
    }
    i_begin_ = 0;
    i_end_ = logical_size_;
    data_ = new_data;
}

std::ostream& QueueOnArray::writeTo(std::ostream& ostrm) const {
    ostrm << kLeftBrace;
    for (int i = 0; i < logical_size_; i++) {
        ostrm << (*this).data_[(i_begin_+i) % physical_size_];
        if ((i_begin_ + i + 1) % physical_size_ != i_end_) {
            ostrm << kSeparator << " ";
        }
    }
    ostrm << kRightBrace;
    return ostrm;
}
