/** Copyright 2018 Kirill Skibin **/

#include "priority_queue_on_list.h"

using namespace std;

PriorityQueueOnList::PriorityQueueOnList(const PriorityQueueOnList& obj) {
    if (this != &obj) {
        if (obj.head_ != nullptr) {
            head_ = new Node();
            head_->data = obj.head_->data;

            Node* previous_new_node = head_;
            Node* temp_node = obj.head_->next;
            while (temp_node != nullptr) {
                Node* new_node = new Node();
                new_node->data = temp_node->data;
                previous_new_node->next = new_node;

                previous_new_node = new_node;
                temp_node = temp_node->next;
            }
        }
    }
}

PriorityQueueOnList::~PriorityQueueOnList() {
    clear();
}

PriorityQueueOnList& PriorityQueueOnList::operator=(
    const PriorityQueueOnList& rhs) {
    if (this != &rhs) {
        clear();
        if (rhs.head_ != nullptr) {
            head_ = new Node();
            head_->data = rhs.head_->data;

            Node* previous_new_node = head_;
            Node* temp_node = rhs.head_->next;
            while (temp_node != nullptr) {
                Node* new_node = new Node();
                new_node->data = temp_node->data;
                previous_new_node->next = new_node;

                previous_new_node = new_node;
                temp_node = temp_node->next;
            }
        }
    }
    return *this;
}

void PriorityQueueOnList::push(const double new_entry) {
    Node* new_node = new Node();
    new_node->data = new_entry;

    if (head_ == nullptr) {
        head_ = new_node;
    } else {
        if (new_entry > head_->data) {  // first node situation
            new_node->next = head_;
            head_ = new_node;
        } else {
            Node* compare_node = head_;
            Node* previous_node = nullptr;
            while (new_entry < compare_node->data) {
                previous_node = compare_node;
                compare_node = compare_node->next;

                if (compare_node == nullptr) {  // last node situation
                    previous_node->next = new_node;
                    break;
                }
            }
            // mid node situation
            new_node->next = compare_node;
            previous_node->next = new_node;
        }
    }
}

void PriorityQueueOnList::pop() {
    if (!isEmpty()) {
        Node* new_head = head_->next;
        delete head_;
        head_ = new_head;
    }
}

double PriorityQueueOnList::front() {
    if (isEmpty())
        throw std::logic_error("Logic error : Try get front from empty queue");

    return head_->data;
}

bool PriorityQueueOnList::isEmpty() const {
    return (head_ == nullptr);
}

void PriorityQueueOnList::clear() {
    while (!isEmpty()) {
        pop();
    }
}

std::ostream& PriorityQueueOnList::writeTo(std::ostream& ostrm) const {
    ostrm << kLeftBrace;
    Node* cout_node = head_;
    while (cout_node != nullptr) {
        ostrm << cout_node->data;
        if (cout_node->next != nullptr) {
            ostrm << kSeparator << " ";
        }
        cout_node = cout_node->next;
    }
    ostrm << kRightBrace;
    return ostrm;
}
