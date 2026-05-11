#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class IPAddress {
protected:
    string ip;
public:
    IPAddress(string ip) : ip(ip) {}
    
    IPAddress(const IPAddress& other) : ip(other.ip) {}
    
    virtual void print() {
        cout << ip;
    }
    
    virtual ~IPAddress() {}
};

class IPAddressChecked : public IPAddress {
private:
    bool isCorrect;

    bool checkValidity(string ipAddress) {
        int dots = 0;
        for (char c : ipAddress) {
            if (c == '.') dots++;
        }
        if (dots != 3) return false;

        stringstream ss(ipAddress);
        string token;
        while (getline(ss, token, '.')) {
            if (token.empty() || token.length() > 3) return false;
            for (char c : token) {
                if (!isdigit(c)) return false;
            }
            int val = stoi(token);
            if (val < 0 || val > 255) return false;
        }
        return true;
    }

public:
    IPAddressChecked(string ip) : IPAddress(ip) {
        isCorrect = checkValidity(ip);
    }
    
    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other) {
        isCorrect = other.isCorrect;
    }

    void print() override {
        IPAddress::print();
        if (isCorrect) {
            cout << " - Correct";
        } else {
            cout << " - Not Correct";
        }
    }
};

int main() {
    string ip1, ip2, ip3;
    
    getline(cin, ip1);
    getline(cin, ip2);
    getline(cin, ip3);

    IPAddress obj1(ip1);
    IPAddressChecked obj2(ip2);
    IPAddressChecked obj3(ip3);

    obj1.print();
    cout << "\n";
    
    obj2.print();
    cout << "\n";
    
    obj3.print();
    cout << "\n";

    return 0;
}