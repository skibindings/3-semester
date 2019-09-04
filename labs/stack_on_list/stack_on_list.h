/** Copyright 2018 Kirill Skibin **/

#pragma once
#ifndef STACK_ON_LIST
#define STACK_ON_LIST

#include <iostream>
#include <sstream>

class StackOnList {
 public:
    StackOnList() = default;
    explicit StackOnList(int);
    StackOnList(const StackOnList& obj);
    ~StackOnList();

    StackOnList& operator=(const StackOnList& rhs);

    void push(const double new_entry);
    void pop();
    double top() const;
    bool isEmpty() const;
    void clear();
    std::ostream& writeTo(std::ostream& ostrm) const;

 private:
    struct Node {
        Node* next{ nullptr };
        double data{ 0 };

        Node* cpy() {
            Node* copy = new Node();
            copy->data = data;
            if (next != nullptr) {
                copy->next = next->cpy();
            }
            return copy;
        }
    };

    Node* head_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const StackOnList& stack) {
    return stack.writeTo(ostrm);
}

#endif
