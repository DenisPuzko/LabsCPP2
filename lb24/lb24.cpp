#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
    bool isGreaterThan(Fraction that);
    bool isLessThan(Fraction that);
    bool isEqual(Fraction that);
private:
    int numerator;
    int denominator;
    void reduce();
};

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    int divisor = gcd(numerator, denominator);
    if (divisor > 1) {
        numerator /= divisor;
        denominator /= divisor;
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

string Fraction::toString() {
    int wholePart = numerator / denominator;
    int remainder = abs(numerator % denominator);

    if (remainder == 0) {
        return to_string(wholePart);
    } else if (wholePart == 0) {
        return to_string(numerator) + "/" + to_string(denominator);
    } else {
        return to_string(wholePart) + " " + to_string(remainder) + "/" + to_string(denominator);
    }
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

bool Fraction::isGreaterThan(Fraction that) {
    int num1 = this->numerator * that.denominator;
    int num2 = that.numerator * this->denominator;
    return num1 > num2;
}

bool Fraction::isLessThan(Fraction that) {
    int num1 = this->numerator * that.denominator;
    int num2 = that.numerator * this->denominator;
    return num1 < num2;
}

bool Fraction::isEqual(Fraction that) {
    int num1 = this->numerator * that.denominator;
    int num2 = that.numerator * this->denominator;
    return num1 == num2;
}

int main() {
    int num1, den1, num2, den2;
    string input1, input2, token;

    getline(cin, input1);
    getline(cin, input2);

    stringstream ss1(input1);
    ss1 >> num1 >> token >> den1;

    stringstream ss2(input2);
    ss2 >> num2 >> token >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    if (f1.isGreaterThan(f2)) {
        cout << f1.toString() << " > " << f2.toString() << endl;
    } else if (f1.isLessThan(f2)) {
        cout << f1.toString() << " < " << f2.toString() << endl;
    } else {
        cout << f1.toString() << " == " << f2.toString() << endl;
    }

    return 0;
}