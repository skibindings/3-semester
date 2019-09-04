/** Copyright 2018 Kirill Skibin **/

#ifndef LABS_DYNAMIC_ARRAY_T_DYNAMIC_ARRAY_T_H_
#define LABS_DYNAMIC_ARRAY_T_DYNAMIC_ARRAY_T_H_

#include <iostream>
#include <sstream>

template<typename T>
class DynamicArrayT {
 public:
    DynamicArrayT() = default;
    explicit DynamicArrayT(const int size);
    DynamicArrayT(const DynamicArrayT<T>& obj);

    ~DynamicArrayT();

    T& operator[] (const int i);
    T& operator[] (const int i) const;

    DynamicArrayT<T>& operator=(const DynamicArrayT<T>& rhs);

    int size() const;
    void add(T new_entry);
    void set(int i, T entry);
    void remove(int i);

    std::ostream& writeTo(std::ostream& ostrm) const;

    void resize(int new_size);

 private:
    int physical_size_{ 0 };
    int logical_size_{ 0 };
    T* data_{ nullptr };

    bool indexIsValid(int i) const;

    const double kExtensionValue{ 2.0f };
    static const char kLeftBrace{ '{' };
    static const char kSeparator{ ',' };
    static const char kRightBrace{ '}' };
};

template<typename T>
inline std::ostream& operator<<(
    std::ostream& ostrm,
    const DynamicArrayT<T>& rhs) {
    return rhs.writeTo(ostrm);
}

template<typename T>
inline std::ostream& operator<<(
    std::ostream& ostrm,
    const DynamicArrayT<T>* rhs) {
    return rhs->writeTo(ostrm);
}

template<typename T>
DynamicArrayT<T>::DynamicArrayT(const int max_size) :
    physical_size_(max_size), logical_size_(0) {
    if (max_size < 0)
        throw std::logic_error("array size should me >= 0");

    data_ = new T[physical_size_];
}

template<typename T>
DynamicArrayT<T>::DynamicArrayT(const DynamicArrayT<T>& obj) {
    if (this != &obj) {
        physical_size_ = obj.physical_size_;
        logical_size_ = obj.logical_size_;
        data_ = new T[physical_size_];
        for (int i = 0; i < obj.logical_size_; i++) {
            data_[i] = obj[i];
        }
    }
}

template <typename T>
DynamicArrayT<T>::~DynamicArrayT() {
    delete[] data_;
}

template <typename T>
void DynamicArrayT<T>::add(T new_entry) {
    if (physical_size_ <= 0) {
        throw logic_error("invalid array size");
    }
    if (logical_size_ + 1 > physical_size_) {
        resize(static_cast<double>(physical_size_) * kExtensionValue);
    }
    data_[logical_size_] = new_entry;
    logical_size_++;
}

template <typename T>
void DynamicArrayT<T>::set(int i, T entry) {
    if (!indexIsValid(i)) {
        throw logic_error("index is out of range");
    }
    data_[i] = entry;
}

template <typename T>
void DynamicArrayT<T>::remove(int i) {
    if (!indexIsValid(i)) {
        throw logic_error("Logic error : index is out of range");
    }
    for (int j = i; j < logical_size_ - 1; j++) {
        data_[j] = data_[j + 1];
    }

    logical_size_--;
}

template <typename T>
int DynamicArrayT<T>::size() const {
    return logical_size_;
}

template <typename T>
void DynamicArrayT<T>::resize(int new_size) {
    physical_size_ = new_size;
    if (logical_size_ > new_size)
        logical_size_ = new_size;

    T* new_data = new T[physical_size_];
    for (int i = 0; i < logical_size_; i++) {
        new_data[i] = data_[i];
    }
    data_ = new_data;
}

template <typename T>
DynamicArrayT<T>& DynamicArrayT<T>::operator=(const DynamicArrayT<T>& rhs) {
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

template <typename T>
T& DynamicArrayT<T>::operator[] (const int i) {
    if (!indexIsValid(i)) {
        throw logic_error("index is out of range");
    }

    return data_[i];
}

template <typename T>
T& DynamicArrayT<T>::operator[] (const int i) const {
    if (!indexIsValid(i)) {
        throw logic_error("index is out of range");
    }

    return data_[i];
}

template <typename T>
bool DynamicArrayT<T>::indexIsValid(const int i) const {
    return (i >= 0 && i < logical_size_);
}

template <typename T>
std::ostream& DynamicArrayT<T>::writeTo(std::ostream& ostrm) const {
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

#endif  // LABS_DYNAMIC_ARRAY_T_DYNAMIC_ARRAY_T_H_
