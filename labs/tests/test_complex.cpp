/** Copyright 2018 Kirill Skibin **/

#include <iostream>
#include <sstream>

#include <complex/complex.h>
#include "catch.hpp"

using namespace std;

bool testParse(const string& str) {
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    } else {
        cout << "Read error: " << str << " -> " << z << endl;
    }
    return istrm.good();
}

void testCopyConstructor() {
    cout << endl << "### testCopyConstructor ###" << endl << endl;
    cout << "cout << (Complex(Complex(-1,-1)))" << endl;
    cout << "waited : {-1,-1}" << endl;
    cout << "result : " << (Complex(Complex(-1, -1))) << endl;
}

void testAssignmentOperator() {
    cout << endl << "### testAssignmentOperator ###" << endl << endl;
    cout << "cout << (Complex() = 5)" << endl;
    cout << "waited : {5,0}" << endl;
    cout << "result : " << (Complex() = 5) << endl;
    cout << "cout << (Complex() = Complex(5,-6))" << endl;
    cout << "waited : {5,-6}" << endl;
    cout << "result : " << (Complex() = Complex(5, -6)) << endl;
}

void testSameTypeExpressions() {
    cout << endl << "### testSameTypeExpressions ###" << endl << endl;
    cout << "cout << (Complex(1,1) - Complex(-1,5))" << endl;
    cout << "waited : {2,-4}" << endl;
    cout << "result : " << (Complex(1, 1) - Complex(-1, 5)) << endl;
    cout << "cout << (Complex(1,2) * Complex(-3,5))" << endl;
    cout << "waited : {-13,-1}" << endl;
    cout << "result : " << (Complex(1, 2) * Complex(-3, 5)) << endl;
}

void testMultipleTypeExpressions() {
    cout << endl << "### testMultipleTypeExpressions ###" << endl << endl;
    cout << "cout << (2 + Complex(-1,5) - 3)" << endl;
    cout << "waited : {-2,5}" << endl;
    cout << "result : " << (2 + Complex(-1, 5) - 3) << endl;
    cout << "cout << (Complex(1,2) * -8)" << endl;
    cout << "waited : {-8,-16}" << endl;
    cout << "result : " << (Complex(1, 2) * -8) << endl;
}

void testEqualityOperators() {
    cout << endl << "### testEqualityOperators ###" << endl << endl;
    cout << "cout << (Complex(3,1) == Complex(3,1))" << endl;
    cout << "waited : 1" << endl;
    cout << "result : " << (Complex(3, 1) == Complex(3, 1)) << endl;
    cout << "cout << (Complex(4,1) != Complex(3,1))" << endl;
    cout << "waited : 1" << endl;
    cout << "result : " << (Complex(4, 1) != Complex(3, 1)) << endl;
}

int main() {
    Complex z;
    z += Complex(8.0);
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");

    testCopyConstructor();
    testAssignmentOperator();
    testSameTypeExpressions();
    testMultipleTypeExpressions();
    testEqualityOperators();

    return 0;
}
