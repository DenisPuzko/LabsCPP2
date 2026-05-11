#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct KeyValuePair {
    string key;
    string value;
};

int main() {
    string valuesLine;
    getline(cin, valuesLine);
    string templateStr;
    getline(cin, templateStr);

    vector<KeyValuePair> pairs;
    size_t start = 0;
    while (start < valuesLine.length()) {
        size_t commaPos = valuesLine.find(',', start);
        if (commaPos == string::npos) {
            commaPos = valuesLine.length();
        }
        
        string pairStr = valuesLine.substr(start, commaPos - start);
        size_t equalPos = pairStr.find('=');
        
        if (equalPos != string::npos) {
            KeyValuePair kvp;
            kvp.key = "[" + pairStr.substr(0, equalPos) + "]";
            kvp.value = pairStr.substr(equalPos + 1);
            pairs.push_back(kvp);
        }
        start = commaPos + 1;
    }

    for (const auto& kvp : pairs) {
        size_t pos = 0;
        while ((pos = templateStr.find(kvp.key, pos)) != string::npos) {
            templateStr.replace(pos, kvp.key.length(), kvp.value);
            pos += kvp.value.length(); 
        }
    }

    cout << templateStr << "\n";

    return 0;
}