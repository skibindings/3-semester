/** Copyright 2018 Kirill Skibin **/

#include <iostream>
#include <sstream>

#include <queue_on_list/queue_on_list.h>

using namespace std;

int main() {
    cout << "Create QueueOnList named queue" << endl;
    QueueOnList queue;

    cout << "Push 2, 4 and 6 in queue" << endl;
    queue.push(2.0f);
    queue.push(4.0f);
    queue.push(6.0f);

    cout << "Print queue using cout" << endl;
    cout << queue << endl;

    cout << "Pop 1 element of queue and then print queue again" << endl;
    queue.pop();
    cout << queue << endl;

    cout << "Print front element of queue" << endl;
    cout << queue.front() << endl;

    cout << "Create new QueueOnList named queue2 "
            "using copy constructor (copying queue)" << endl;
    QueueOnList queue2(queue);
    cout << "Push 8, -5.2, -9 in queue2 and then cout queue and queue2" << endl;
    queue2.push(8.0f);
    queue2.push(-5.2f);
    queue2.push(-9.0f);
    cout << queue << endl << queue2 << endl;

    cout << "Now let's queue = queue" << endl;
    queue = queue;
    cout << "Cout queue" << endl;
    cout << queue << endl;

    cout << "Now let's queue = queue = queue2" << endl;
    queue = queue = queue2;

    cout << "Push 11 to queue and then cout queue and queue2" << endl;
    queue.push(11.0f);
    cout << queue << endl << queue2 << endl;

    cout << "Let's clear queue and check if it is Empty " << endl;
    queue.clear();
    cout << queue.isEmpty() << endl;

    cout << "Let's try to get front of queue" << endl;
    try {
        cout << queue.front() << endl;
    }
    catch (std::logic_error& e) {
        cout << e.what() << endl;
    }

    cout << "cout queue and queue2" << endl;
    cout << queue << endl << queue2 << endl;

    return 0;
}

