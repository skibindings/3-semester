/** Copyright 2018 Kirill Skibin **/

#include "queue_on_list.h"

using namespace std;

QueueOnList::QueueOnList(const QueueOnList& obj) {
    if (this != &obj) {
        Node* temp_node = obj.head_;
        Node* previous_copy_node = nullptr;
        Node* copy_node = nullptr;
        while (temp_node != nullptr) {
            copy_node = temp_node->cpy();
            if (previous_copy_node == nullptr) {
                head_ = copy_node;
            } else {
                previous_copy_node->next = copy_node;
            }
            temp_node = temp_node->next;
            previous_copy_node = copy_node;
        }
        tail_ = copy_node;
    }
}

QueueOnList::~QueueOnList() {
    clear();
}

QueueOnList& QueueOnList::operator=(const QueueOnList& rhs) {
    if (this != &rhs) {
        clear();

        Node* temp_node = rhs.head_;
        Node* previous_copy_node = nullptr;
        Node* copy_node = nullptr;
        while (temp_node != nullptr) {
            copy_node = temp_node->cpy();
            if (previous_copy_node == nullptr) {
                head_ = copy_node;
            } else {
                previous_copy_node->next = copy_node;
            }
            temp_node = temp_node->next;
            previous_copy_node = copy_node;
        }
        tail_ = copy_node;
    }
    return *this;
}

void QueueOnList::push(const double new_entry) {
    Node* new_node = new Node();
    new_node->data = new_entry;
    if (isEmpty()) {
        head_ = new_node;
        tail_ = new_node;
    } else {
        tail_->next = new_node;
        tail_ = tail_->next;
    }
}

void QueueOnList::pop() {
    if (!isEmpty()) {
        Node* node_deleted(head_);
        head_ = head_->next;
        delete node_deleted;
    }
}

double QueueOnList::front() {
    if (isEmpty())
        throw std::logic_error("Logic error : Try get front from empty queue.");

    return head_->data;
}

bool QueueOnList::isEmpty() const {
    return (nullptr == head_);
}

void QueueOnList::clear() {
    while (!isEmpty()) {
        pop();
    }
}

std::ostream& QueueOnList::writeTo(std::ostream& ostrm) const {
    ostrm << kLeftBrace;
    Node* temp_node = head_;
    while (temp_node != nullptr) {
        ostrm << temp_node->data;
        if (temp_node->next != nullptr) {
            ostrm << kSeparator << " ";
        }
        temp_node = temp_node->next;
    }
    ostrm << kRightBrace;
    return ostrm;
}
