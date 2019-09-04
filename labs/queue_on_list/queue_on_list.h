/** Copyright 2018 Kirill Skibin **/

#ifndef LABS_QUEUE_ON_LIST_QUEUE_ON_LIST_H_
#define LABS_QUEUE_ON_LIST_QUEUE_ON_LIST_H_

#include <iostream>
#include <sstream>

class QueueOnList {
 public:
    QueueOnList() = default;
    QueueOnList(const QueueOnList& obj);

    ~QueueOnList();

    QueueOnList& operator=(const QueueOnList& rhs);

    void push(const double new_entry);
    void pop();
    double front();
    bool isEmpty() const;
    void clear();

    int size() const;

    std::ostream& writeTo(std::ostream& ostrm) const;

 private:
     struct Node {
         Node* next{ nullptr };
         double data{ 0 };

         Node* cpy() {
             Node* new_node = new Node();
             new_node->data = data;
             return new_node;
         }
     };

    Node* head_{nullptr};
    Node* tail_{nullptr};

    static const char kLeftBrace{ '{' };
    static const char kSeparator{ ',' };
    static const char kRightBrace{ '}' };
};

inline std::ostream& operator<<(std::ostream& ostrm, const QueueOnList& rhs) {
    return rhs.writeTo(ostrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, const QueueOnList* rhs) {
    return rhs->writeTo(ostrm);
}

#endif  // LABS_QUEUE_ON_LIST_QUEUE_ON_LIST_H_
