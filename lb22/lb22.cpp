#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator) {
    if (denominator < 0) {
        this->numerator = -numerator;
        this->denominator = -denominator;
    } else {
        this->numerator = numerator;
        this->denominator = denominator;
    }
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

int main(void) {
    int num, den;
    string input = "";
    getline(cin, input);
    
    stringstream ss(input);
    string token;
    
    ss >> num;
    ss >> token;
    ss >> den;

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    
    return 0;
}