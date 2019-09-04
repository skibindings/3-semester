/** Copyright 2018 Kirill Skibin **/

#include <iostream>
#include <sstream>

#include <dynamic_array/dynamic_array.h>

using namespace std;

void testCopyConstructor() {
    cout << "--testCopyConstructor--" << endl;

    DynamicArray d(5);
    d.add(1.0f);
    d.add(2.0f);
    d.add(3.0f);
    d.remove(1);

    DynamicArray a(d);
    a.set(0, 5.0f);

    cout << "--execution code begin-- " << endl;
    cout << "DynamicArray d = DynamicArray(5); \nd.add(1.0f);";
    cout << "\nd.add(2.0f); \nd.add(3.0f); \nd.remove(1);";
    cout << "\n\nDynamicArray a(d); \na.set(0, 5.0f);";
    cout << "\ncout << d << endl; \ncout << a << endl; \n";
    cout << "--execution code end--" << endl;
    cout << "--result-- " << endl;
    cout << d << endl;
    cout << a << endl;
}

void testAddSetRemoveMethods() {
    cout << endl << "testAddSetRemoveMethods" << endl;

    DynamicArray d(5);
    d.add(1.0f);
    d.add(2.0f);
    d.add(2.0f);
    d.add(2.0f);
    d.add(2.0f);
    d.add(2.0f);
    d.add(2.0f);
    d.add(3.0f);
    d.remove(1);
    d.set(1, 4.5f);

    cout << "--execution code begin-- " << endl;
    cout << "DynamicArray d = DynamicArray(5);\nd.add(1.0f);";
    cout << "\nd.add(2.0f); \nd.add(2.0f); \nd.add(2.0f);";
    cout << "\nd.add(2.0f); \nd.add(2.0f); \nd.add(2.0f);";
    cout << "\nd.add(3.0f); \nd.remove(1); \nd.set(1, 4.5f);";
    cout <<"\ncout << d << endl; \n";
    cout << "--execution code end--" << endl;
    cout << "--result-- " << endl;

    cout << d << endl;
}

void testAssignmentOperator() {
    cout << endl << "testAssignmentOperator" << endl;

    DynamicArray a(3);
    a.add(2);
    a.add(1);
    a.add(14);
    DynamicArray d = a;
    d.set(0, -11);

    cout << "--execution code begin-- " << endl;
    cout << "DynamicArray a = DynamicArray(3); \na.add(2);";
    cout << "\na.add(1); \na.add(14); \nDynamicArray d = a;";
    cout << "\n\nd.set(0, -11); \n\ncout << a << endl;";
    cout << "\ncout << d << endl; \n";
    cout << "--execution code end--" << endl;
    cout << "--result-- " << endl;

    cout << a << endl << d << endl;
}

void testIndexingOperator() {
    cout << endl << "testIndexingOperator" << endl;

    DynamicArray a(5);
    a.add(2);
    a.add(1);
    a.add(14);
    a.add(-5);
    a.add(6);
    for (int i = 0; i < a.size(); i++)
        a[i] = i*i;

    cout << "--execution code begin-- " << endl;
    cout << "DynamicArray a = DynamicArray(5);\na.add(2);";
    cout << "\na.add(1); \na.add(14); \na.add(-5); \na.add(6);";
    cout << "\nfor(int i = 0; i < a.size(); i++)\na[i] = i * i;";
    cout << "\ncout << a << endl; \n";
    cout << "--execution code end--" << endl;
    cout << "--result-- " << endl;

    cout << a << endl;
}

int main() {
    testCopyConstructor();
    testAddSetRemoveMethods();
    testAssignmentOperator();
    testIndexingOperator();

    return 0;
}
