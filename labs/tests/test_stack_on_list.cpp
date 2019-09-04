/** Copyright 2018 Kirill Skibin **/

#include <iostream>
#include <sstream>

#include <stack_on_list/stack_on_list.h>

using namespace std;

int main() {
    cout << "Create StackOnList named stack" << endl;
    StackOnList stack;

    cout << "Push 2, 4 and 6 in stack" << endl;
    stack.push(2.0f);
    stack.push(4.0f);
    stack.push(6.0f);

    cout << "Print stack using cout" << endl;
    cout << stack << endl;

    cout << "Pop 1 element of stack and then print it again" << endl;
    stack.pop();
    cout << stack << endl;

    cout << "Print top element of stack" << endl;
    cout << stack.top() << endl;

    cout << "Create new StackOnList named stack2 using copy constructor"
         << endl;
    StackOnList stack2(stack);
    cout << "Push 8 in stack 2 and then cout stack and stack2" << endl;
    stack2.push(8.0f);
    cout << stack << endl <<stack2 << endl;

    cout << "Now let's stack = stack" << endl;
    stack = stack;
    cout << "Cout stack" << endl;
    cout << stack << endl;

    cout << "Now let's stack = stack = stack2" << endl;
    stack = stack = stack2;

    cout << "Push 11 to stack and then cout stack and stack2" << endl;
    stack.push(11.0f);
    cout << stack << endl << stack2 << endl;

    cout << "Let's clear stack and check if it is Empty " << endl;
    stack.clear();
    cout << stack.isEmpty() << endl;

    cout << "Let's try to get top of stack" << endl;
    try {
        cout << stack.top() << endl;
    }
    catch (std::logic_error& e) {
        cout << e.what() << endl;
    }

    cout << "cout stack and stack2" << endl;
    cout << stack << endl << stack2 << endl;

    return 0;
}

