/** Copyright 2018 Kirill Skibin **/

#include <iostream>
#include <sstream>

#include <rational/rational.h>

using namespace std;

bool testParse(const string& str) {
    istringstream istrm(str);
    Rational z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    } else {
        cout << "Read error: " << str << " -> " << z << endl;
    }
    return istrm.good();
}

void testCopyConstructor() {
    cout << endl << "### TEST Copy Constructor ###" << endl << endl;

    cout << "Rational(Rational(2,4))" << endl;
    cout << "waited : {1/2}" << endl;
    cout << "result : " << (Rational(Rational(2, 4))) << endl;
}

void testAssignmentOperator() {
    cout << endl << "### TEST Assignment Operator ###" << endl << endl;

    cout << "Rational() = 5" << endl;
    cout << "waited : {5/1}" << endl;
    cout << "result : " << (Rational() = 5) << endl;

    cout << "Rational() = Rational(3,2)" << endl;
    cout << "waited : {3/2}" << endl;
    cout << "result : " << (Rational() = Rational(3, 2)) << endl;
}

void testSameTypeExpressions() {
    cout << endl << "### TEST Same Type Expressions ###" << endl << endl;

    cout << "Rational(3,5) + Rational(2,4)" << endl;
    cout << "waited : 3/5 + 2/4 = 11/10" << endl;
    cout << "result : " << (Rational(3, 5) + Rational(2, 4)) << endl;
    cout << "Rational(3,5) - Rational(2,4)" << endl;
    cout << "waited : 3/5 - 2/4 = 1/10" << endl;
    cout << "result : " << (Rational(3, 5) - Rational(2, 4)) << endl;
    cout << "Rational(3,5) * Rational(2,4)" << endl;
    cout << "waited : 3/5 * 2/4 = 3/10" << endl;
    cout << "result : " << (Rational(3, 5) * Rational(2, 4)) << endl;
    cout << "Rational(3,5) / Rational(2,4)" << endl;
    cout << "waited : 3/5 / 2/4 = 6/5" << endl;
    cout << "result : " << (Rational(3, 5) / Rational(2, 4)) << endl;
}

void testMultipleTypeExpressions() {
    cout << endl << "### TEST Multiple Type Expressions ###" << endl << endl;

    cout << "2 + Rational(3,5) + 5" << endl;
    cout << "waited : 2 + 3/5 + 5 = 38/5" << endl;
    cout << "result : " << (2 + Rational(3, 5) + 5) << endl;
    cout << "2 - Rational(3,5) - 5" << endl;
    cout << "waited : 2 - 3/5 - 5 = -18/5" << endl;
    cout << "result : " << (2 - Rational(3, 5) - 5) << endl;
    cout << "Rational(3,5) / 2" << endl;
    cout << "waited : 3/5 / 2 = 3/10" << endl;
    cout << "result : " << (Rational(3, 5) /2) << endl;
    cout << "Rational(3,5) / Rational(2,4)" << endl;
    cout << "waited : 3/5 * 5 = 3" << endl;
    cout << "result : " << (Rational(3, 5) * 5) << endl;
}

void testSameTypeComparasions() {
    cout << endl << "### TEST Same Type Comparasions ###" << endl << endl;

    cout << "Rational(2,4) == Rational(1,2)" << endl;
    cout << "waited : 1" << endl;
    cout << "result : " << (Rational(2, 4) == Rational(1 , 2)) << endl;

    cout << "Rational(333,111) != Rational(66,22)" << endl;
    cout << "waited : 0" << endl;
    cout << "result : " << (Rational(333, 111) != Rational(66, 22)) << endl;

    cout << "Rational(55,6) > Rational(55,7)" << endl;
    cout << "waited : 1" << endl;
    cout << "result : " << (Rational(55, 6) > Rational(55, 7)) << endl;
}

void testMultipleTypeComparasions() {
    cout << endl << "### TEST Multiple Type Comparasions ###" << endl << endl;

    cout << "Rational(10,2) == 5" << endl;
    cout << "waited : 1" << endl;
    cout << "result : " << (Rational(10, 2) == 5) << endl;

    cout << "Rational(33,11) != 4" << endl;
    cout << "waited : 1" << endl;
    cout << "result : " << (Rational(33, 11) != 4) << endl;

    cout << "Rational(55,6) > 9" << endl;
    cout << "waited : 1" << endl;
    cout << "result : " << (Rational(55, 6) > 9) << endl;
}

int main() {
    Rational z;
    z += Rational(8.0);
    testParse("{8/-9}");
    testParse("{8/9}");
    testParse("{8/9");

    testCopyConstructor();
    testAssignmentOperator();
    testSameTypeExpressions();
    testMultipleTypeExpressions();
    testSameTypeComparasions();
    testMultipleTypeComparasions();

    return 0;
}

