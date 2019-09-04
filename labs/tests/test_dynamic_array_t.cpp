/** Copyright 2018 Kirill Skibin **/

#include <iostream>
#include <sstream>
#include <string>

#include <dynamic_array_t/dynamic_array_t.h>

using namespace std;

template <typename Q>
void testCopyConstructor(
    string typename_str,
    Q first_add,
    Q second_add,
    Q third_add,
    Q first_set) {
    cout << "testCopyConstructor <" << typename_str << ">" << endl;

    cout << "let's create dynamic array called D and add "
         << first_add << ", "
         << second_add << ", "
         << third_add << " in it"
         << endl;
    DynamicArrayT<Q> D(5);
    D.add(first_add);
    D.add(second_add);
    D.add(third_add);
    cout << "cout D" << endl;
    cout << D << endl;

    cout << "let's create dynamic array D2 using copy constructor (copying D)"
         << endl;
    DynamicArrayT<Q> D2(D);
    cout << "set first value of D2 to " << first_set << endl;
    D2.set(0, first_set);

    cout << "now cout D and D2" << endl;
    cout << D << endl << D2 << endl;
}

template <typename Q>
void testAddSetRemoveMethods(
    string typename_str,
    Q first_add,
    Q second_add,
    Q third_add,
    Q first_set) {
    cout << endl << "testAddSetRemoveMethods <" << typename_str << ">"
         << endl;

    cout << "let's create dynamic array called D and add "
         << first_add << " (1 time), "
         << second_add << " (2 times), "
         << third_add << " (3 times) in it"
         << endl;

    DynamicArrayT<Q> d(5);
    d.add(first_add);
    d.add(second_add);
    d.add(second_add);
    d.add(third_add);
    d.add(third_add);
    d.add(third_add);

    cout << "cout D" << endl;
    cout << d << endl;

    cout << "then remove first element of D and cout D" << endl;

    d.remove(1);

    cout << d << endl;

    cout << "then set second value of D to " << first_set << endl;
    d.set(1, first_set);

    cout << "and cout D" << endl;

    cout << "now, try to remove element with index 10 from D" << endl;
    try {
        d.remove(10);
    }
    catch (std::logic_error& e) {
        cout << e.what() << endl;
    }

    cout << d << endl;
}

template <typename Q>
void testAssignmentOperator(
    string typename_str,
    Q first_add,
    Q second_add,
    Q third_add,
    Q first_set) {
    cout << endl << "testAssignmentOperator <" << typename_str << ">" << endl;

    cout << "let's create dynamic array called D and add "
        << first_add << ", "
        << second_add << ", "
        << third_add << " in it"
        << endl;

    DynamicArrayT<Q> d(3);
    d.add(first_add);
    d.add(second_add);
    d.add(third_add);

    cout << "cout D" << endl;
    cout << d << endl;

    cout << "now let's create dynamic array D2 "
         << "and assign D to it using assign operator (=)"
         << endl;

    DynamicArrayT<Q> d2 = d;

    cout << "set first value of D2 to " << first_set << endl;

    d2.set(0, first_set);

    cout << "now cout D and D2" << endl;
    cout << d << endl << d2 << endl;
}

template <typename Q>
void testIndexingOperator(
    string typename_str,
    Q first_add,
    Q second_add,
    Q third_add,
    Q fourth_add,
    Q fifth_add) {
    cout << endl << "testIndexingOperator <" << typename_str << ">" << endl;

    cout << "let's create dynamic array called D and add "
        << first_add << ", "
        << second_add << ", "
        << third_add << ", "
        << fourth_add << ", "
        << fifth_add << " in it"
        << endl;

    DynamicArrayT<Q> d(5);
    d.add(first_add);
    d.add(second_add);
    d.add(third_add);
    d.add(fourth_add);
    d.add(fifth_add);

    cout << "get size of D" << endl << d.size() << endl;
    cout << "cout D" << endl << d << endl;

    cout << "then make all elements equal to the first "
         << "using indexing operator []"
         << endl;

    for (int i = 0; i < d.size(); i++)
        d[i] = d[0];

    cout << "cout D" << endl << d << endl;
}

int main() {
    string type = "double";
    testCopyConstructor<double>(type, 1.0f, -2.5f, 4.0f, 1.3f);
    testAddSetRemoveMethods<double>(type, 4.0f, -2.0f, -4.0f, 1.0f);
    testAssignmentOperator<double>(type, 5.0f, 3.0f, 1.0f, -1.0f);
    testIndexingOperator<double>(type, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f);
    cout << endl << endl;

    type = "char";
    testCopyConstructor<char>(type, 'd', 'e', 'a', '?');
    testAddSetRemoveMethods<char>(type, 'x', 'y', 'z', 'w');
    testAssignmentOperator<char>(type, 'a', 'b', 'c', 'd');
    testIndexingOperator<char>(type, '!', '?', '>', '<', '=');
    cout << endl << endl;

    type = "string";
    testCopyConstructor<string>(type, "right", "left", "up", "down");
    testAddSetRemoveMethods<string>(type, "right", "left", "up", "down");
    testAssignmentOperator<string>(type, "red", "green", "blue", "black");
    testIndexingOperator<string>(type, "one", "two", "three", "four", "five");

    return 0;
}
