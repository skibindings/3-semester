/** Copyright 2018 Kirill Skibin **/

#ifndef LABS_QUEUE_ON_ARRAY_QUEUE_ON_ARRAY_H_
#define LABS_QUEUE_ON_ARRAY_QUEUE_ON_ARRAY_H_

#include <iostream>
#include <sstream>

class QueueOnArray {
 public:
    QueueOnArray();
    QueueOnArray(const QueueOnArray& obj);

    ~QueueOnArray();

    QueueOnArray& operator=(const QueueOnArray& rhs);

    void push(const double new_entry);
    void pop();
    double front();
    bool isEmpty() const;
    void clear();

    int size() const;

    std::ostream& writeTo(std::ostream& ostrm) const;

 private:
    void resize(const int new_size);

    int physical_size_{0};
    int logical_size_{0};
    double* data_{ nullptr };

    int i_begin_{0};
    int i_end_{0};

    const double kExtensionValue{ 2.0 };
    static const int kStartPhysicalSize{ 4 };

    static const char kLeftBrace{ '{' };
    static const char kSeparator{ ',' };
    static const char kRightBrace{ '}' };
};

inline std::ostream& operator<<(std::ostream& ostrm, const QueueOnArray& rhs) {
    return rhs.writeTo(ostrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, const QueueOnArray* rhs) {
    return rhs->writeTo(ostrm);
}

#endif  // LABS_QUEUE_ON_ARRAY_QUEUE_ON_ARRAY_H_
