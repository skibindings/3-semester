/** Copyright 2018 Kirill Skibin **/

#include "stack_on_list.h"

using namespace std;

StackOnList::StackOnList(const StackOnList& obj) {
    if (this != &obj) {
        head_ = obj.head_->cpy();
    }
}

StackOnList& StackOnList::operator=(const StackOnList& obj) {
    if (this != &obj) {
        clear();
        head_ = obj.head_->cpy();
    }
    return *this;
}

void StackOnList::push(const double new_entry) {
    Node* new_node = new Node();
    new_node->data = new_entry;

    if (head_ != nullptr) {
        new_node->next = head_;
    }
    head_ = new_node;
}

void StackOnList::pop() {
    if (!isEmpty()) {
        Node* node_deleted(head_);
        head_ = head_->next;
        delete node_deleted;
    }
}

double StackOnList::top() const {
    if (isEmpty())
        throw std::logic_error("Logic error : Try get top from empty stack.");

    return head_->data;
}

bool StackOnList::isEmpty() const {
    return (nullptr == head_);
}

void StackOnList::clear() {
    while (!isEmpty()) {
        pop();
    }
}

ostream& StackOnList::writeTo(std::ostream& ostrm) const {
    Node* printed_node(head_);
    ostrm << '{';
    while (printed_node != nullptr) {
        ostrm << printed_node->data;
        printed_node = printed_node->next;
        if (printed_node) {
            ostrm << ", ";
        }
    }
    ostrm << '}';
    return ostrm;
}

StackOnList::~StackOnList() {
    clear();
}
