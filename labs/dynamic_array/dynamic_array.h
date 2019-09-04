/** Copyright 2018 Kirill Skibin **/

#ifndef LABS_DYNAMIC_ARRAY_DYNAMIC_ARRAY_H_
#define LABS_DYNAMIC_ARRAY_DYNAMIC_ARRAY_H_

#include <iostream>
#include <sstream>

class DynamicArray {
 public:
    DynamicArray() = default;
    explicit DynamicArray(const int size);
    DynamicArray(const DynamicArray& obj);

    ~DynamicArray();

    double& operator[] (const int i);
    double& operator[] (const int i) const;

    DynamicArray& operator=(const DynamicArray& rhs);

    int size() const;
    void add(double new_entry);
    void set(int i, double entry);
    void remove(int i);

    std::ostream& writeTo(std::ostream& ostrm) const;

    void resize(int new_size);

 private:
    int physical_size_{ 0 };
    int logical_size_{ 0 };
    double* data_{ nullptr };

    bool indexIsValid(int i) const;

    const double kExtensionValue{ 2.0f };
    static const char kLeftBrace{ '{' };
    static const char kSeparator{ ',' };
    static const char kRightBrace{ '}' };
};

inline std::ostream& operator<<(std::ostream& ostrm, const DynamicArray& rhs) {
    return rhs.writeTo(ostrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, const DynamicArray* rhs) {
    return rhs->writeTo(ostrm);
}

#endif  // LABS_DYNAMIC_ARRAY_DYNAMIC_ARRAY_H_
