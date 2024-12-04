#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class FiniteAutomaton {
public:
    bool processString(const string& inputString) {
        if (inputString.length() < 4) return false;  
        for (char charac : inputString)
            if (charac != 'a' && charac != 'b') 
                throw invalid_argument("Input string must contain only 'a' and 'b'");
        return inputString[0] == inputString[inputString.length() - 2] &&
               inputString[1] == inputString[inputString.length() - 1];
    }
};

int main() {
    FiniteAutomaton fa;
    string inputString;
    cout << "Enter a string over {a, b} of length 4 or more: ";
    getline(cin, inputString);

    try {
        cout << "String: " << inputString << " -> " 
             << (fa.processString(inputString) ? "Accepted" : "Rejected") << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}
