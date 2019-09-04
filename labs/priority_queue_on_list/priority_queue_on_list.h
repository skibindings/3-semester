/** Copyright 2018 Kirill Skibin **/

#ifndef LABS_PRIORITY_QUEUE_ON_LIST_PRIORITY_QUEUE_ON_LIST_H_
#define LABS_PRIORITY_QUEUE_ON_LIST_PRIORITY_QUEUE_ON_LIST_H_

#include <iostream>
#include <sstream>

class PriorityQueueOnList {
 public:
    PriorityQueueOnList() = default;
    PriorityQueueOnList(const PriorityQueueOnList& obj);

    ~PriorityQueueOnList();

    PriorityQueueOnList& operator=(const PriorityQueueOnList& rhs);

    void push(const double new_entry);
    void pop();
    double front();
    bool isEmpty() const;
    void clear();

    std::ostream& writeTo(std::ostream& ostrm) const;

 private:
    struct Node {
        Node* next{ nullptr };
        double data{ 0 };
    };

    Node* head_{ nullptr };

    static const char kLeftBrace{ '{' };
    static const char kSeparator{ ',' };
    static const char kRightBrace{ '}' };
};

inline std::ostream& operator<<(std::ostream& ostrm,
    const PriorityQueueOnList& rhs) {
    return rhs.writeTo(ostrm);
}

#endif  // LABS_PRIORITY_QUEUE_ON_LIST_PRIORITY_QUEUE_ON_LIST_H_
