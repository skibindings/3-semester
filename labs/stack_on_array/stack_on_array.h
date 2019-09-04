/** Copyright 2018 Kirill Skibin **/

#pragma once
#ifndef STACK_ON_ARRAY
#define STACK_ON_ARRAY

#include <iostream>
#include <sstream>

class StackOnArray {
 public:
    StackOnArray();
    explicit StackOnArray(int var);
    StackOnArray(const StackOnArray& obj);
    ~StackOnArray();

    StackOnArray& operator=(const StackOnArray& rhs);

    void push(const double new_entry);
    void pop();
    double top() const;
    bool isEmpty() const;
    void clear();
    std::ostream& writeTo(std::ostream& ostrm) const;

 private:
    void resize(const int new_size);

    double* data_{ nullptr };
    int head_index_{-1};
    int physical_size_{0};

    const double kExtensionValue{ 2.0 };
    static const int kStartPhysicalSize{ 4 };
};

inline std::ostream& operator<<(
    std::ostream& ostrm,
    const StackOnArray& stack) {
    return stack.writeTo(ostrm);
}

#endif
