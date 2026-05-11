#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string password;
    getline(cin, password);

    bool isValid = true;
    
    if (password.length() < 8) {
        cout << "The password must be 8 characters long\n";
        isValid = false;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSpecial = true; 
    }

    if (!hasUpper) {
        cout << "The password must have at least one upper case letter\n";
        isValid = false;
    }
    if (!hasLower) {
        cout << "The password must have at least one lower case letter\n";
        isValid = false;
    }
    if (!hasDigit) {
        cout << "The password must have at least one digit\n";
        isValid = false;
    }
    if (!hasSpecial) {
        cout << "The password must have at least one special character\n";
        isValid = false;
    }

    if (isValid) {
        cout << "The password is valid\n";
    }

    return 0;
}