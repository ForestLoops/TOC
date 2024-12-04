#include <iostream>
#include <string>
using namespace std;

class FiniteAutomaton {
    int count = 0;
public:
    bool processString(const string& inputString) {
        for (char charac : inputString) {
            if (charac != '0' && charac != '1') 
                throw invalid_argument("Input must contain only '0' and '1'");
            count += (charac == '1');
            if (count > 3) return false;
        }
        return count == 2 || count == 3;
    }
};

int main() {
    FiniteAutomaton fa;
    string inputString;
    cout << "Enter a binary string: ";
    getline(cin, inputString);

    try {
        cout << inputString << " -> " 
             << (fa.processString(inputString) ? "Accepted" : "Rejected") << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}
