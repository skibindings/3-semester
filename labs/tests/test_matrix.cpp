/** Copyright 2018 Kirill Skibin **/

#include <iostream>
#include <sstream>

#include <matrix/matrix.h>

using namespace std;

void testCopyConstructor() {
    cout << "=== testCopyConstructor ===" << endl;

    cout << "{ execution code begin }" << endl;

    Matrix d(3, 3);
    for (int i = 0; i < d.width(); i++) {
        for (int j = 0; j < d.height(); j++) {
            d.at(i, j) = i*j;
        }
    }

    Matrix a(d);
    a.at(0, 0) = 100;

    const char *code = "Matrix d = Matrix(3, 3);\n"
        "for (int i = 0; i < d.width(); i++) {\n"
        "    for (int j = 0; j < d.height(); j++) {\n"
        "\n"
        "        d.at(i, j) = i * j;\n"
        "    }\n"
        "}\n"
        "Matrix a(d);\n"
        "a.at(0, 0) = 100;\n"
        "cout << d << endl << a << endl; \n";

    cout << code;
    cout << "{ execution code end }" << endl;
    cout << "{ execution code result }" << endl;
    cout << d << endl << a << endl;
}

void testMultiplicateOperator() {
    cout << endl;
    cout << "=== testMultiplicateOperator ===" << endl;

    Matrix a(3, 2);
    Matrix b(2, 3);

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 2; y++) {
            a.at(x, y) = y * 3 + x;
        }
    }

    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            b.at(x, y) = y * 2 + x;
        }
    }
}

void testAssignmentOperator() {
    cout << "=== testAssignmentOperator ===" << endl;
    cout << "{ execution code begin }" << endl;

    Matrix d(3, 3);
    for (int i = 0; i < d.width(); i++) {
        for (int j = 0; j < d.height(); j++) {
            d.at(i, j) = i * j;
        }
    }

    Matrix a = d;
    a.at(0, 0) = 25;

    const char *code = "Matrix d = Matrix(3, 3);\n"
        "for (int i = 0; i < d.width(); i++) {\n"
        "    for (int j = 0; j < d.height(); j++) {\n"
        "\n"
        "        d.at(i, j) = i * j;\n"
        "    }\n"
        "}\n"
        "Matrix a = d;\n"
        "a.at(0, 0) = 25;\n"
        "cout << d << endl << a << endl; \n";

    cout << code;

    cout << "{ execution code end }" << endl;
    cout << "{ execution code result }" << endl;
    cout << d << endl << a << endl;
}

void testAtMethod() {
    cout << endl << "=== testAtMethod ===" << endl;
    cout << "{ execution code begin }" << endl;

    Matrix d(3, 4);
    for (int i = 0; i < d.width(); i++) {
        for (int j = 0; j < d.height(); j++) {
            d.at(i, j) = 5;
        }
    }
    d.at(1, 2) = 0;

    const char *code = "Matrix d = Matrix(3, 4);\n"
        "for (int i = 0; i < d.width(); i++) {\n"
        "    for (int j = 0; j < d.height(); j++) {\n"
        "\n"
        "        d.at(i, j) = 5;\n"
        "    }\n"
        "}\n"
        "d.at(1, 2) = 0;\n"
        "cout << d \n";

    cout << code;

    cout << "{ execution code end }" << endl;
    cout << "{ execution code result }" << endl;
    cout << d;
}

int main() {
    testCopyConstructor();
    testAssignmentOperator();
    testAtMethod();
    testMultiplicateOperator();
    return 0;
}
